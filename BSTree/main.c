#include <stdio.h>
#include <stddef.h>
#include <bs_tree.h>

int main()
{
    SearchTree t = NULL;
    t = insert(2, t);
    t = insert(1, t);
    t = insert(4, t);
    t = insert(3, t);
    t = insert(5, t);
    printf("%d\n", t->element);
    printf("%d\n", t->left->element);
    printf("%d\n", t->right->element);
    t = delete(4, t);
    printf("%d\n", t->element);
    printf("%d\n", t->right->element);
    printf("%d\n", t->right->left->element);
    return 0;
}
