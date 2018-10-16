#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <linked_list.h>

int is_empty(List l) {
    // assume l is not NULL
    return l->next == NULL;
}

int is_last(Position p, List l) {
    // assume p is not NULL
    return p->next == NULL;
}

Position find(int elem, List l) {
    // assume l is not NULL
    Position p;
    p = l->next;
    while(p != NULL && p->element != elem) {
        p = p->next;
    }
    return p;
}

Position find_previous(int elem, List l) {
    // assume l is not NULL
    Position p;
    p = l->next;
    while(p->next != NULL && p->next->element != elem) {
        p = p->next;
    }
    return p;
}

void delete(int elem, List l) {
    // assume l is not NULL
    Position p, tmp_ptr;
    p = find_previous(elem, l);
    // find element at p
    if(!is_last(p, l)) {
        tmp_ptr = p->next;
        p->next = tmp_ptr->next;
        free(tmp_ptr);
    }
}

void insert(int elem, List l, Position p) {
    // assume both l & p are not NULL
    Position tmp_ptr;
    tmp_ptr = (Position)malloc(sizeof(struct Node));
    if(tmp_ptr == NULL) {
        printf("memory out of space");
        return;
    }
    tmp_ptr->element = elem;
    // if l is empty
    if(is_empty(l)) {
        l->next = tmp_ptr;
        tmp_ptr->next = NULL;
    } else {
        tmp_ptr->next = p->next;
        p->next = tmp_ptr;
    }
}

void delete_list(List l) {
    // assume l is not NULL
    Position p, tmp_ptr;
    p = l->next;
    // delete first node
    l->next = NULL;
    while(p != NULL) {
        tmp_ptr = p->next;
        free(p);
        p = tmp_ptr;
    }
}
