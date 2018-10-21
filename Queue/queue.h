#ifndef QUEUE_H
#define QUEUE_H
struct QueueRecord;
typedef struct QueueRecord *Queue;

int is_empty(Queue q);
int is_full(Queue q);
void make_empty(Queue q);
Queue create_queue(int max_elements);
void enqueue(int x, Queue q);
int dequeue(Queue q);
int peek(Queue q);
void delete_queue(Queue q);
#endif // QUEUE_H

struct QueueRecord
{
    int capacity;
    int front;
    int rear;
    int size;
    int *array;
};
