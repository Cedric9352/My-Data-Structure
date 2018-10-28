#ifndef BS_TREE_H
#define BS_TREE_H
struct TreeNode;
typedef struct TreeNode* Position;
typedef struct TreeNode* SearchTree;

SearchTree make_empty(SearchTree t);
Position find(int elem, SearchTree t);
Position find_min(SearchTree t);
Position find_max(SearchTree t);
SearchTree insert(int elem, SearchTree t);
SearchTree delete(int elem, SearchTree t);
int delete_min(SearchTree t);
#endif // BS_TREE_H

struct TreeNode
{
    int element;
    SearchTree left;
    SearchTree right;
};
