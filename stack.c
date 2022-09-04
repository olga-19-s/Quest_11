 #include <stdlib.h>
#include "stack.h"

struct node* init(int *nums) {
    if (nums == NULL) {
        return NULL;
    }
    struct node *root = malloc(sizeof(struct node));
    struct node *p = root;
    p->num = nums[0];
    p->next = NULL;
    for (int i = 1; i < NUMS_COUNT; ++i) {
        struct node *new = malloc(sizeof(struct node));
        new->num = nums[i];
        new->next = NULL;
        p->next = new;
        p = p->next;
    }
    return root;
}

struct node* push(int num, struct node *root) {
    if (root == NULL) {
        return NULL;
    }
    struct node *tmp = root;
    struct node *new = malloc(sizeof(struct node));
    new->num = num;
    new->next = NULL;
    while (root->next != NULL) {
        root = root->next;
    }
    root->next = new;
    return tmp;
}

struct node* pop(struct node *root) {
    if (root == NULL) {
        return NULL;
    }
    struct node *tmp = root;
    while (root->next->next != NULL) {
        root = root->next;
    }
    free(root->next);
    root->next = NULL;
    return tmp;
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
