#ifndef SRC_STACK_H_
#define SRC_STACK_H_

#define NUMS_COUNT 8

struct node {
    int num;
    struct node *next;
};

struct node* init(int *nums);
struct node* push(int num, struct node *root);
struct node* pop(struct node *root);
void destroy(struct node* root);

#endif  // SRC_STACK_H_
