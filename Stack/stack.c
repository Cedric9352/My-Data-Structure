#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stack.h>

int is_empty(Stack s) {
    return s->next == NULL;
}

Stack create_stack(void) {
    Stack s;
    s = (Stack)malloc(sizeof(struct Node));
    if(s == NULL) {
        printf("memory out of space");
        return NULL;
    }
    s->next = NULL;
    make_empty(s);
    return s;
}

void make_empty(Stack s) {
    if(s == NULL) {
        printf("must use create_stack first");
        return;
    }
    while(!is_empty(s)) {
        pop(s);
    }
}

void push(int elem, Stack s) {
    PtrToNode tmp_ptr;
    if(s == NULL) {
        printf("must be used after a stack created");
        return;
    }
    tmp_ptr = (PtrToNode)malloc(sizeof(struct Node));
    if(tmp_ptr == NULL) {
        printf("memory out of space");
        return;
    }
    tmp_ptr->element = elem;
    tmp_ptr->next = s->next;
    s->next = tmp_ptr;
}

int* top(Stack s) {
    if(!is_empty(s)) {
        return &(s->next->element);
    }
    printf("empty stack");
    return NULL;
}

void pop(Stack s) {
    PtrToNode tmp_ptr;
    if(s == NULL) {
        printf("must be used after a stack created");
        return;
    }
    tmp_ptr = s->next;
    s->next = tmp_ptr->next;
    free(tmp_ptr);
}

void print_stack(Stack s) {
    if(!is_empty(s)) {
        printf("%d->", s->next->element);
        print_stack(s->next);
    } else {
        printf(".");
    }
}
