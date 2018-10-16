#ifndef STACK_H
#define STACK_H
struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode Stack;

int is_empty(Stack s);
Stack create_stack(void);
void make_empty(Stack s);
void push(int elem, Stack s);
int top(Stack s);
void pop(Stack s);
void print_stack(Stack s);
#endif // STACK_H

struct Node {
    int element;
    PtrToNode next;
};
