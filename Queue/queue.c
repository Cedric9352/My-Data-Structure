#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <queue.h>

int is_empty(Queue q) {
    return q->size == 0;
}

int is_full(Queue q) {
    return q->size == q->capacity;
}

void make_empty(Queue q) {
    q->size = 0;
    q->rear = 0;
    q->front = 1;
}

Queue create_queue(int max_elements) {
    Queue q;
    q = (Queue)malloc(sizeof(struct QueueRecord));
    if(q == NULL) {
        printf("memory out of space");
        return NULL;
    }
    q->array = (int*)malloc(sizeof(int)*max_elements);
    if(q->array == NULL) {
        printf("memory out of space");
        return NULL;
    }
    q->capacity = max_elements;
    make_empty(q);
    return q;
}

void enqueue(int x, Queue q) {
    if(is_full(q)) {
        printf("full queue");
        return;
    } else {
        ++q->size;
        if(q->capacity == ++q->rear) {
            q->rear = 0;
        }
        q->array[q->rear] = x;
    }
}

void dequeue(Queue q) {
    if(is_empty(q)) {
        printf("empty queue");
        return;
    } else {
        --q->size;
        q->front = q->front+1 == q->capacity ? 0 : q->front+1;
    }
}

int *peek(Queue q) {
    if(is_empty(q)) {
        printf("empty queue");
        return NULL;
    } else {
        return &(q->array[q->front]);
    }
}
