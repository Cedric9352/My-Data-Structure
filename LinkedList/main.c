#include <stdio.h>
#include <stdlib.h>
#include <linked_list.h>

int main()
{
    printf("start to construct head of linked-list\n");
    List head = create_list();
    printf("construct complete\n");
    printf("now insert element \"1\"\n");
    insert(1, head, NULL);
    printf("the first element is %d\n", head->next->element);
    return 0;
}
