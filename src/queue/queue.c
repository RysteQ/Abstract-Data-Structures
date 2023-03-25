#include <stdio.h>
#include <stdlib.h>

#define dataType int

struct Queue {
    dataType* queuePointer;
    int rear;
    int front;
};


#pragma region declareFuncs

void initQueue(struct Queue *queue);
void traverseQueue(struct Queue queue);
void enqueue(struct Queue *queue, dataType value);
dataType dequeue(struct Queue *queue);

#pragma endregion declareFuncs


int main(int argc, char** argv) {
    struct Queue mainQueue;
    dataType dequeuedValue;

    initQueue(&mainQueue);

    enqueue(&mainQueue, 4);
    enqueue(&mainQueue, 1);
    enqueue(&mainQueue, 5);
    enqueue(&mainQueue, 7);
    enqueue(&mainQueue, 3);
    traverseQueue(mainQueue);

    dequeuedValue = dequeue(&mainQueue);
    dequeuedValue = dequeue(&mainQueue);
    dequeuedValue = dequeue(&mainQueue);
    printf("Dequeued value: %i\n\n", dequeuedValue);
    traverseQueue(mainQueue);

    return 0;
}


#pragma region funcs

void initQueue(struct Queue *queue) {
    queue->queuePointer = malloc(sizeof(dataType));
    queue->rear = queue->front = 0;
}

void traverseQueue(struct Queue queue) {
    for (int i = queue.rear; i < queue.front; i++) {
        printf("Queue value at %i: %i\n", i, *(queue.queuePointer + i));
    }
}

void enqueue(struct Queue *queue, dataType value) {
    queue->queuePointer = realloc(queue->queuePointer, (queue->front - queue->rear) + 2);
    *(queue->queuePointer + (queue->front++)) = value;
}

dataType dequeue(struct Queue *queue) {
    return *(queue->queuePointer + (queue->rear++));
}

#pragma endregion funcs