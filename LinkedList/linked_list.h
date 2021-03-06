#ifndef LINKED_LIST_H
#define LINKED_LIST_H
struct Node;
typedef struct Node* PtrToNode;
typedef struct Head* PtrToHead;
typedef PtrToHead List;
typedef PtrToNode Position;

int is_empty(List l);
int is_last(Position p);
List create_list();
List make_empty(List l);
Position find(int elem, List l);
Position find_previous(int elem, List l);
void delete(int elem, List l);
void insert(int elem, List l, Position p);
void delete_list(List l);
#endif // LINKED_LIST_H

struct Node {
    int element;
    Position next;
};

struct Head {
    Position next;
};
