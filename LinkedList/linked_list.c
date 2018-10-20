#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <linked_list.h>

int is_empty(List l) {
    if(l == NULL) {
        printf("must not be used on a NULL pointer");
        exit(EXIT_FAILURE);
    }
    return l->next == NULL;
}

int is_last(Position p) {
    // assume that p is a element of linked-list
    if(p == NULL) {
        printf("position must not be a Null pointer");
        exit(EXIT_FAILURE);
    }
    return p->next == NULL;
}

List create_list() {
    List l;
    l = (List)malloc(sizeof(struct Head));
    if(l == NULL) {
        printf("out of memory");
        return NULL;
    }
    l->next = NULL;
    make_empty(l);
    return l;
}

List make_empty(List l) {
    if(l == NULL) {
        printf("must not be used on a NULL pointer");
        exit(EXIT_FAILURE);
    }
    Position p = l->next, tmp_ptr;
    l->next = NULL;
    while(p != NULL) {
        tmp_ptr = p->next;
        free(p);
        p = tmp_ptr;
    }
    return l;
}

Position find(int elem, List l) {
    if(l == NULL) {
        printf("empty linked-list");
        exit(EXIT_FAILURE);
    }
    Position p;
    p = l->next;
    while(p != NULL && p->element != elem) {
        p = p->next;
    }
    return p;
}

Position find_previous(int elem, List l) {
    if(l == NULL) {
        printf("empty linked-list");
        exit(EXIT_FAILURE);
    }
    Position p;
    p = l->next;
    while(p->next != NULL && p->next->element != elem) {
        p = p->next;
    }
    return p;
}

void delete(int elem, List l) {
    Position p, tmp_ptr;
    // find_previous ensures that l is not null
    p = find_previous(elem, l);
    // find element at p
    if(!is_last(p)) {
        tmp_ptr = p->next;
        p->next = tmp_ptr->next;
        free(tmp_ptr);
    }
}

void insert(int elem, List l, Position p) {
    if(p == NULL) {
        if(l == NULL || !is_empty(l)) {
            printf("position must not be a Null pointer");
            exit(EXIT_FAILURE);
        }
    }
    Position tmp_ptr;
    tmp_ptr = (Position)malloc(sizeof(struct Node));
    if(tmp_ptr == NULL) {
        printf("out of memory");
        return;
    }
    tmp_ptr->element = elem;
    if(is_empty(l)) {
        l->next = tmp_ptr;
    } else {
        tmp_ptr->next = p->next;
        p->next = tmp_ptr;
    }
}

void delete_list(List l) {
    if(l == NULL) {
        printf("must not be used on a NULL pointer");
        exit(EXIT_FAILURE);
    }
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
