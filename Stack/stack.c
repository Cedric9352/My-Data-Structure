#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stack.h>

int is_empty(Stack s) {
    if(s == NULL) {
        printf("must not be used on a NULL pointer");
        exit(EXIT_FAILURE);
    }
    return s->next == NULL;
}

void make_empty(Stack s) {
    if(s == NULL) {
        printf("must not be used on a NULL pointer");
        exit(EXIT_FAILURE);
    }
    while(!is_empty(s)) {
        pop(s);
    }
}

void push(int elem, Stack s) {
    PtrToNode tmp_ptr;
    if(s == NULL) {
        printf("must not be used on a NULL pointer");
        exit(EXIT_FAILURE);
    }
    tmp_ptr = (PtrToNode)malloc(sizeof(struct Node));
    if(tmp_ptr == NULL) {
        printf("out of memory");
        return;
    }
    tmp_ptr->element = elem;
    tmp_ptr->next = s->next;
    s->next = tmp_ptr;
}

int top(Stack s) {
    if(s == NULL || is_empty(s)) {
        printf("empty stack");
        exit(EXIT_FAILURE);
    }
    return s->next->element;
}

void pop(Stack s) {
    PtrToNode tmp_ptr;
    if(s == NULL || is_empty(s)) {
        printf("empty stack");
        exit(EXIT_FAILURE);
    }
    tmp_ptr = s->next;
    s->next = tmp_ptr->next;
    free(tmp_ptr);
}

Stack create_stack(void) {
    Stack s;
    s = (Stack)malloc(sizeof(struct Node));
    if(s == NULL) {
        printf("out of memory");
        return NULL;
    }
    s->next = NULL;
    make_empty(s);
    return s;
}

void print_stack(Stack s) {
    if(s == NULL) {
        printf("must not be used on a NULL pointer");
        exit(EXIT_FAILURE);
    }
    while(s->next != NULL) {
        printf("%d->", s->next->element);
        s = s->next;
    }
    printf(".");
}

void delete_stack(Stack s) {
    PtrToNode p, tmp_ptr;
    if(s == NULL) {
        printf("must not be used on a NULL pointer");
        exit(EXIT_FAILURE);
    }
    p = s->next;
    // delete top
    s->next =  NULL;
    while(p != NULL) {
        tmp_ptr = p->next;
        free(p);
        p = tmp_ptr;
    }
}
