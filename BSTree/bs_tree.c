#include <stddef.h>
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
    if(t != NULL) {
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
