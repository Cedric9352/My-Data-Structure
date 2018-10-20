#ifndef STACK_H
#define STACK_H
struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode Stack;

int is_empty(Stack s);
void make_empty(Stack s);
void push(int elem, Stack s);
int top(Stack s);
void pop(Stack s);
Stack create_stack(void);
void print_stack(Stack s);
void delete_stack(Stack s);
#endif // STACK_H

struct Node {
    int element;
    PtrToNode next;
};
