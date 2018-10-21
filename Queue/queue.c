#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <queue.h>

int is_empty(Queue q) {
    if(q == NULL) {
        printf("must not be used on a NULL pointer");
        exit(EXIT_FAILURE);
    }
    return q->size == 0;
}

int is_full(Queue q) {
    if(q == NULL) {
        printf("must not be used on a NULL pointer");
        exit(EXIT_FAILURE);
    }
    return q->size == q->capacity;
}

void make_empty(Queue q) {
    if(q == NULL) {
        printf("must not be used on a NULL pointer");
        exit(EXIT_FAILURE);
    }
    q->size = 0;
    q->rear = 0;
    q->front = 1;
}

Queue create_queue(int max_elements) {
    Queue q;
    q = (Queue)malloc(sizeof(struct QueueRecord));
    if(q == NULL) {
        printf("out of memory");
        return NULL;
    }
    q->array = (int*)malloc(sizeof(int)*max_elements);
    if(q->array == NULL) {
        printf("out of memory");
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

int dequeue(Queue q) {
    if(is_empty(q)) {
        printf("empty queue");
        exit(EXIT_FAILURE);
    } else {
        --q->size;
        int tmp = q->array[q->front];
        q->front = q->front+1 == q->capacity ? 0 : q->front+1;
        return tmp;
    }
}

int peek(Queue q) {
    if(is_empty(q)) {
        printf("empty queue");
        exit(EXIT_FAILURE);
    } else {
        return q->array[q->front];
    }
}

void delete_queue(Queue q) {
    if(q == NULL) {
        printf("must not be used on a NULL pointer");
        exit(EXIT_FAILURE);
    }
    free(q->array);
    free(q);
}
