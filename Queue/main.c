#include <stdio.h>
#include <queue.h>

int main()
{
    Queue q = create_queue(5);
    enqueue(1, q);
    enqueue(2, q);
    enqueue(3, q);
    printf("%d\n", *(peek(q)));
    dequeue(q);
    printf("%d\n", *(peek(q)));
    dequeue(q);
    printf("%d\n", *(peek(q)));
    printf("now the size of queue is: %d\n", q->size);
    return 0;
}
