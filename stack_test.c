#include <stdio.h>
#include "stack.h"

void outputStack(struct node *root);
int peek(struct node *root);

int main() {
    int nums[NUMS_COUNT];
    for (int i = 0; i < NUMS_COUNT; ++i) {
        nums[i] = i;
    }
    struct node *root = init(nums);
    printf("Initialization\n");
    outputStack(root);
    printf("\n\nPush 25\n");
    push(25, root);
    (peek(root) == 25) ? printf("SUCCESS\n\n") : printf("FAIL\n\n");
    printf("Push 30\n");
    push(30, root);
    (peek(root) == 30) ? printf("SUCCESS\n\n") : printf("FAIL\n\n");
    printf("Push 40\n");
    push(40, root);
    (peek(root) == 40) ? printf("SUCCESS\n") : printf("FAIL\n");
    outputStack(root);
    printf("\n\nPop\n");
    pop(root);
    (peek(root) != 40) ? printf("SUCCESS\n\n") : printf("FAIL\n\n");
    printf("Pop\n");
    pop(root);
    (peek(root) != 30) ? printf("SUCCESS\n\n") : printf("FAIL\n\n");
    printf("Pop\n");
    pop(root);
    (peek(root) != 25) ? printf("SUCCESS\n") : printf("FAIL\n");
    outputStack(root);
    destroy(root);
    return 0;
}

int peek(struct node *root) {
    while (root->next != NULL) {
        root = root->next;
    }
    return root->num;
}

void outputStack(struct node *root) {
    while (root != NULL) {
        printf("%d", root->num);
        root = root->next;
        if (root != NULL) {
            printf("\n");
        }
    }
}
