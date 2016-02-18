/* Copyright (C) 2006.  Alastair Poole.
Verbatim copying and distribution of this entire article are permitted
worldwide, without royalty, in any medium, provided this notice, and the
copyright notice, are preserved. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    char *data;
    struct node *next;
};

void display_list(struct node *rootnode);
struct node *node_alloc(void);
void node_add_data(struct node *rootnode, char *data);
void free_list(struct node *rootnode);


int main(void)
{
    /* The root node remains zeroed, and is not used to store data */
    struct node *rootnode = node_alloc();

    node_add_data(rootnode, "This is our data");
    node_add_data(rootnode, "This is another data");
    display_list(rootnode);
    free_list(rootnode);
    return EXIT_SUCCESS;
}

struct node *node_alloc(void)
{
    struct node *tmp = calloc(1, sizeof(struct node));
    if (tmp == NULL)
    {
        fprintf(stderr, "calloc()\n");
        exit(EXIT_FAILURE);
    }
    return tmp;
}

/* Traverse the list until node->next is NULL which we will
       add to. When adding we do not traverse until tmp == NULL,
       otherwise we are at the end of the list and unable to
       connect to a previous node. */
void node_add_data(struct node *rootnode, char *data)
{
    struct node *tmp;

    for (tmp = rootnode; tmp->next != NULL; tmp = tmp->next)
    {
        if (tmp->next == NULL) {
            /* Connect to the list */
            tmp->next = node_alloc();
            tmp = tmp->next;
            tmp->data = strdup(data);
            /* Create the new end */
            tmp->next = NULL;
        } else {
            fprintf(stderr, "Oh shit!\n");
            exit(EXIT_FAILURE);
        }
    }
}

void display_list(struct node *rootnode)
{
    struct node *tmp;

    for (tmp = rootnode; tmp != NULL; tmp = tmp->next)
    {
        if (tmp->data != 0) {
            printf("Data is %s\n", tmp->data);
        }
    }
}

void free_list(struct node *rootnode)
{
    struct node *tmp;
    struct node *fwd;

    while (tmp != NULL)
    {
        fwd = tmp->next;
        free(tmp->data);
        free(tmp);
        tmp = fwd;
    }
}
