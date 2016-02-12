/*
$Id: parse_msg.c 18 2008-07-06 09:18:48Z Makhtar $
Module de traitement des donnees envoyees par l'appareil de geo-localisation

COMPILATION: gcc -Wall -g parse_msg.c  -L/usr/lib/mysql -lmysqlclient -o parse_msg
(C) 2007 GSIE Technology
*/
#define _GNU_SOURCE  /* asprintf() */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <syslog.h>
#include <mysql/mysql.h>

/* Signales la necessite d'ajouter un signe a la latitude ou a la longitude */
static int aval = 0;

/* Parametres SQL */
static const char* sqlDb = "tracking";
static const char* sqlTable = "point";

enum {
    INDEX_SDATE,  /* Send Date */
    INDEX_STIME,
    INDEX_NS,       /* North ou South */
    INDEX_LAT,
    INDEX_WE,      /* West ou East */
    INDEX_LNG
};

/* Retournes la valeur de chaque champs sauf la vitesse */
char* ParseMsg(char* msg, int index);

/* Retournes la vitesse.
Devrait etre appelez avec "atof(GetSpeed(msg))"
*/
char* GetSpeed(char*msg)
{
    char* spd;
    char ret_val[8];
    asprintf(&spd, "%s", strrchr(msg, ':'));
    /* Saute le caractere ':' */
    ++spd;
    sprintf(ret_val, "%s", spd);
    syslog(LOG_INFO, "vitesse: %s\n\n", ret_val);
    free(--spd);
    return strdup(ret_val);
}

MYSQL* MySqlConnect(void);


int main(int argc, char* argv[])
{
    char header[8];
    char* champs[] = {"send_date", "send_time", "NS", "lat",
                      "WE", "lng"
                     };

    /* Nombre de champs */
    const int num_champs = sizeof(champs) / sizeof(champs[0]);
    char* val_champs;
    char* msg;
    /* Le numero de tel n'est pour l'instant pas inclu dans le message.
    Ceci est le numero de test utilise dans la BDD */
    static const char* tel = "1234";

    char query[1024];
    int i;
    MYSQL* sqlHd = NULL;
    errno = 0;
    openlog("parse_msg", LOG_PERROR | LOG_CONS | LOG_PID, 0);

    if (argv[1] == NULL) {
        syslog(LOG_ERR, "Specifiez une chaine de caracteres comme argument!");
        return EXIT_FAILURE;
    } else {
        /* Verifies que c'est un message TIMER! */
        asprintf(&msg, "%s", argv[1]);
        memset((void*)header, '\0', sizeof(header));
        strncpy(header, msg, sizeof(header) - 1);
        syslog(LOG_INFO, "Entete du message: %s", header);

        if (strcmp(header, "TIMER! ")) { /* NB: FALSE = 0 */
            syslog(LOG_ERR, "Ce message N'EST PAS destine a la table %s...", sqlTable);
            exit(EXIT_FAILURE);
        } else {
            syslog(LOG_INFO, "Ce message est destine a la table %s\n"
                   "Extraction des donnees en cours...\n", sqlTable);

            /* Creation de la requete - avec echappement de toutes les chaines de caracteres */
            sprintf(query, "INSERT INTO %s.%s (`tel`, `send_date`, `send_time`, `rcv_date`, `lat`, `lng`, `speed`, `msg`) "
                    "VALUES (", sqlDb, sqlTable);

            /* Insert le numero de tel de test */
            strcat(query, "'");
            strcat(query, tel);
            strcat(query, "', ");

            /***** Extraction des donnees destinees a chaque champs *****/
            for (i = 0; i < num_champs; i++) {
                asprintf(&val_champs, "%s", ParseMsg(msg, i));
                syslog(LOG_INFO, "%s: %s", champs[i], val_champs);

                if ((i != INDEX_NS) && (i != INDEX_WE)) {
                    strcat(query, "'");
                    strcat(query, val_champs);
                    strcat(query, "', ");
                }
                free(val_champs);
                /* Insert la date et l'heure actuelle apres "send_time"  pour renseigner le champ rcv_date */
                if (i == INDEX_STIME)
                    strcat(query, "NOW(), ");
            }
        }
    }

    /* obtention de la vitesse et insertion dans la requete */
    strcat(query, "'");
    strcat(query, GetSpeed(msg));

    /* insertion du message complet dans la requete */
    strcat(query, "', '");
    strcat(query, msg);
    strcat(query, "')");
    syslog(LOG_INFO, "Requete: %s", query);

    sqlHd = MySqlConnect();
    if (mysql_query(sqlHd, query) == 0)
        syslog(LOG_INFO, "Les donnees ont ete sauvegardees dans la table %s", sqlTable);
    else
        syslog(LOG_ERR, "Echec de la requete %s - %s", query, mysql_error(sqlHd));

    mysql_close(sqlHd);
    free(msg);
    return EXIT_SUCCESS;
}



/* Retournes la valeur de chaque champs sauf la vitesse */
char* ParseMsg(char* msg, int index)
{
    char buffer[24];
    char ch[2];
    char* head;
    int i = 0;
    int avalFree = 0;
    memset((void*)buffer, '\0', sizeof(buffer));

    /* Saute l'entete "TIMER! " */
    do {
        memset((void*)ch, '\0', sizeof(ch));
        strncpy(ch, msg, sizeof(char));
        ++msg;
    } while (strcmp(ch, " "));

    for (i = 0; i <= index; i++) {
        memset((void*)buffer, '\0', sizeof(buffer));

        for (;;) {
            memset((void*)ch, '\0', sizeof(ch));
            if (strncpy(ch, msg, sizeof(char)) != '\0') {
                /* La virgule est le separateur des champs */
                if ( (!strcmp(ch, ",")) ) {
                    ++msg;   /* saute l'espace */
                    ++msg;
                    break;
                }
                strcat(buffer, ch);
                ++msg;
            }
        }
    }

    /* Detectes l'orientation Sud et West */
    if (!strcmp(buffer, "S") || !strcmp(buffer, "W"))
        aval = 1;

    if ( (index == INDEX_LAT) || (index == INDEX_LNG) ) {
        /* Supprimes les trois premiers caracteres - i.e. "Lat", "Lng" */
        asprintf(&head, "%s", strchr(buffer, ':'));
        if (head != NULL) {
            ++head;  /* Sautes le caractere ':' */

            if (head[0] == '0') {
                avalFree = 1;
                ++head;
            }

            memset((void*)buffer, '\0', sizeof(buffer));
            if (aval == 1) {
                aval = 0;
                strcat(buffer, "-");   /* Insert le signe moins */
            }
            strcat(buffer, head);
            if (avalFree == 1) {
                --head;
                avalFree = 0;
            }
            free(--head);
        }
    }
    return strdup(buffer);
}



MYSQL* MySqlConnect(void)
{
    /* Parametres SQL */
    const char* sqlHost = "192.168.0.2";
    const char* sqlUser = "tracking";
    const char* sqlPass = "tracking";

    MYSQL* sqlHd = mysql_init(NULL);
    if (sqlHd != NULL) {
        if (mysql_real_connect(sqlHd, sqlHost, sqlUser, sqlPass, sqlDb, 0,
                               NULL, 0) != NULL) {

            syslog(LOG_INFO, "Connection a la BDD %s... OK", sqlDb);
            return sqlHd;
        } else {
            syslog(LOG_ERR, "Echec de la connection a la BDD %s - %s",
                   sqlDb, mysql_error(sqlHd));
            exit(EXIT_FAILURE);
        }
    }

    syslog(LOG_ERR, "Echec de l'initialisation de la connection - %s",
           mysql_error(sqlHd));
    exit(EXIT_FAILURE);
}
