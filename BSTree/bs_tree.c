#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <bs_tree.h>

SearchTree make_empty(SearchTree t) {
    if(t != NULL) {
        make_empty(t->left);
        make_empty(t->right);
        free(t);
    }
    return NULL;
}

Position find(int elem, SearchTree t) {
    if(t == NULL) {
        return NULL;
    }
    if(t->element < elem) {
        return find(elem, t->right);
    } else if(t->element > elem) {
        return find(elem, t->left);
    } else {
        return t;
    }
}

Position find_min(SearchTree t) {
    if(t == NULL) {
        return NULL;
    } else if(t->left == NULL) {
        return t;
    } else {
        return find_min(t->left);
    }
}

Position find_max(SearchTree t) {
    if(t != NULL) {
        while(t->right != NULL) {
            t = t->right;
        }
    }
    return t;
}

SearchTree insert(int elem, SearchTree t) {
    if(t == NULL) {
        t = (SearchTree)malloc(sizeof(struct TreeNode));
        if(t == NULL) {
            printf("out of memory");
            return NULL;
        } else {
            t->element = elem;
            t->left = NULL;
            t->right = NULL;
        }
    } else if(elem < t->element) {
        t->left = insert(elem, t->left);
    } else if(elem > t->element) {
        t->right = insert(elem, t->right);
    }
    return t;
}

SearchTree delete(int elem, SearchTree t) {
    if(t == NULL) {
        printf("element not found");
        exit(EXIT_FAILURE);
    } else if(elem < t->element) {
        t->left = delete(elem, t->left);
    } else if(elem > t->element) {
        t->right = delete(elem, t->right);
    // now find the element
    } else {
        if(t->left == NULL || t->right == NULL) {
            // node to free
            Position tmp = t;
            t = t->left == NULL ? t->right : t->left;
            free(tmp);
        // have two children
        } else {
            t->element = delete_min(t->right);
        }
    }
    return t;
}

int delete_min(SearchTree t) {
    if(t == NULL) {
        printf("t cannot be NULL");
        exit(EXIT_FAILURE);
    } else {
        while(t->left != NULL) {
            t = t->left;
        }
        int elem = t->element;
        free(t);
        t = NULL;
        return elem;
    }
}
