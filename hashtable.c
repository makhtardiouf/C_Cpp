/* Copyright (c) 2006.  Alastair Poole.
Verbatim copying and distribution of this entire article are permitted
worldwide, without royalty, in any medium, provided this notice, and the
copyright notice, are preserved.

Largely modified by Makhtar Diouf */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TABLE_SIZE 16

struct node
{
    char *data;
    struct node *next;
};

struct node *hashtab[TABLE_SIZE];
struct node *alloc_node(void);
void init_hashtab(void);
unsigned int gen_hash_index(const char *string);
void add_node(const char *data);
void list_hashtab(void);
void free_hashtab(void);

int main(void)
{
    init_hashtab();
    add_node("David");
    add_node("Goliath");
    add_node("Alan");
    /* Try to duplicate a node */
    add_node("Goliath");
    list_hashtab();
    free_hashtab();
    return EXIT_SUCCESS;
}

struct node *alloc_node(void)
{
    struct node *tmp = calloc(1, sizeof(struct node));
    if (tmp == NULL)
    {
        perror("calloc");
        exit(EXIT_FAILURE);
    }
    tmp->next = NULL;
    return tmp;
}

void init_hashtab(void)
{
    int x;
    printf("Initializing hash table...\n");

    for (x = 0; x < TABLE_SIZE; x++) {
        hashtab[x] = alloc_node();
    }
}

void add_node(const char *data)
{
    unsigned int x = gen_hash_index(data);
    struct node *tmp;

    for (tmp = hashtab[x]; tmp != NULL; tmp = tmp->next) {
        if (tmp->data != NULL)
            if ( strcmp(data, tmp->data) == 0) {
                printf("Entry \"%s\" already exists in table\n", data);
                return;
            }
    }

    for (tmp = hashtab[x]; tmp->next != NULL; tmp = tmp->next) {
        if (tmp->next == NULL) {
            tmp->next = alloc_node();
            tmp = tmp->next;
            tmp->data = strdup(data);
            printf("Added a new node identified by: %s\n", data);
            tmp->next = NULL;
        } else {
            perror("add_node");
            exit(EXIT_FAILURE);
        }
    }
}

unsigned int gen_hash_index(const char *string)
{
    unsigned int num = 0;
    unsigned int index = 0;

    while (*string++ != '\0')
        num += *string;

    index = (num % TABLE_SIZE);
    printf("Generated table index %d\n", index);

    return index;
}

void list_hashtab(void)
{
    unsigned int x = 0;
    struct node *tmp;

    printf("Listing hash table contents...\n");

    for (x = 0; x < TABLE_SIZE; x++) {
        for (tmp = hashtab[x]; tmp != NULL; tmp = tmp->next) {
            if (tmp->data != NULL) {
                printf("\tData at Index %d is %s\n", x, tmp->data);
            }
        }
    }
}

void free_hashtab(void)
{
    struct node *tmp;
    struct node *fwd;
    unsigned int x;

    printf("Freeing hash table...\n");

    for (x = 0; x < TABLE_SIZE; x++) {
        tmp = hashtab[x];
        while (tmp != NULL) {
            fwd = tmp->next;
            /* 	    printf("Freeing table data: %s\n", tmp->data); */
            free(tmp->data);
            free(tmp);
            tmp = fwd;
        }
    }
}
