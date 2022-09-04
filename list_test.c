#include <stdio.h>
#include "list.h"

void outputList(struct node *root);

int main() {
    struct door doors[DOORS_COUNT];
    for (int i = 0; i < DOORS_COUNT; ++i) {
        doors[i].id = i;
        doors[i].status = i % 3 % 2;
    }
    struct node *root = init(doors);
    printf("Initialization\n");
    outputList(root);
    printf("\n");
    struct node *del;
    printf("\nRemoving node with id 5\n");
    del = find_door(5, root);
    if (del != NULL) {
        root = remove_door(del, root);
        printf("SUCCESS");
    } else {
        printf("FAIL");
    }
    printf("\n");
    printf("\nRemoving node with id 0\n");
    del = find_door(0, root);
    if (del != NULL) {
        root = remove_door(del, root);
        printf("SUCCESS");
    } else {
        printf("FAIL");
    }
    printf("\n");
    printf("\nRemoving node with id 14\n");
    del = find_door(14, root);
    if (del != NULL) {
        root = remove_door(del, root);
        printf("SUCCESS");
    } else {
        printf("FAIL");
    }
    printf("\n");
    printf("\nRemoving node with id 99\n");
    del = find_door(99, root);
    if (del != NULL) {
        root = remove_door(del, root);
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }
    printf("\nResult\n");
    outputList(root);
    printf("\n\n");
    doors[0].id = 40;
    doors[0].status = 40;
    add_door(root, &doors[0]);
    printf("Adding after root\n");
    root->next->id == 40 ? printf("SUCCESS\n") : printf("FAIL\n");
    del = find_door(7, root);
    add_door(del, &doors[0]);
    printf("\nAdding in the midle\n");
    del->next->id == 40 ? printf("SUCCESS\n") : printf("FAIL\n");
    del = find_door(13, root);
    add_door(del, &doors[0]);
    printf("\nAdding after last\n");
    del->next->id == 40 ? printf("SUCCESS\n") : printf("FAIL\n");
    outputList(root);
    destroy(root);
    return 0;
}

void outputList(struct node *root) {
    while (root != NULL) {
        printf("%d, %d", root->id, root->status);
        root = root->next;
        if (root != NULL) {
            printf("\n");
        }
    }
}
