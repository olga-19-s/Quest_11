#include <stdlib.h>
#include "list.h"

struct node* init(struct door* door) {
    if (door == NULL) {
        return NULL;
    }
    struct node *root = malloc(sizeof(struct node));
    struct node *p = root;
    p->id = door[0].id;
    p->status = door[0].status;
    p->next = NULL;
    for (int i = 1; i < DOORS_COUNT; ++i) {
        struct node *new = malloc(sizeof(struct node));
        new->id = door[i].id;
        new->status = door[i].status;
        new->next = NULL;
        p->next = new;
        p = p->next;
    }
    return root;
}

struct node* add_door(struct node* elem, struct door* door) {
    struct node *new = malloc(sizeof(struct node));
    new->id = door->id;
    new->status = door->status;
    new->next = NULL;
    if (elem->next == NULL) {
        elem->next = new;
    } else {
        struct node *tmp = elem->next;
        elem->next = new;
        new->next = tmp;
    }
    return new;
}

struct node* find_door(int door_id, struct node* root) {
    while (root != NULL) {
        if (root->id == door_id) {
            return root;
        }
        root = root->next;
    }
    return NULL;
}

struct node* remove_door(struct node* elem, struct node* root) {
    if (elem == root) {
        struct node *tmp = root->next;
        free(root);
        return tmp;
    }
    struct node *fir = root;
    struct node *sec = root->next;
    while (sec != NULL) {
        if (sec == elem) {
            fir->next = sec->next;
            free(sec);
            return root;
        }
        fir = sec;
        sec = sec->next;
    }
    return root;
}

void destroy(struct node* root) {
    struct node *tmp = root;
    root = root->next;
    while (root->next != NULL) {
        free(tmp);
        tmp = root;
        root = root->next;
    }
    free(tmp);
    free(root);
}
