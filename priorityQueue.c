#include <stdio.h>
#define MAX_SIZE 5

struct PriorityQueue {
    int queue[MAX_SIZE];
    int priority[MAX_SIZE];
    int rear;
};

void initQueue(struct PriorityQueue *pq) {
    pq->rear = -1;
}

int isFull(struct PriorityQueue *pq) {
    return pq->rear == MAX_SIZE - 1;
}

int isEmpty(struct PriorityQueue *pq) {
    return pq->rear == -1;
}

void enQueue(struct PriorityQueue *pq, int element, int priority) {
    if (isFull(pq)) {
        printf("Queue Overflow! Cannot add element %d with priority %d\n", element, priority);
        return;
    }

    int i;
    for (i = pq->rear; i >= 0 && pq->priority[i] < priority; i--) {
        pq->queue[i + 1] = pq->queue[i];
        pq->priority[i + 1] = pq->priority[i];
    }

    pq->queue[i + 1] = element;
    pq->priority[i + 1] = priority;
    pq->rear++;
}

void deQueue(struct PriorityQueue *pq, int priority) {
    if (isEmpty(pq)) {
        printf("Queue Underflow! Queue is already empty.\n");
        return;
    }

    int i;
    for (i = 0; i <= pq->rear; i++) {
        if (pq->priority[i] == priority) {
            printf("Element %d with priority %d removed.\n", pq->queue[i], pq->priority[i]);
            for (; i < pq->rear; i++) {
                pq->queue[i] = pq->queue[i + 1];
                pq->priority[i] = pq->priority[i + 1];
            }
            pq->rear--;
            return;
        }
    }

    printf("Element with priority %d not found.\n", priority);
}

void displayQueue(struct PriorityQueue *pq) {
    if (isEmpty(pq)) {
        printf("Queue is empty!\n");
        return;
    }

    printf("Priority Queue:\n");
    for (int i = 0; i <= pq->rear; i++) {
        printf("Element: %d, Priority: %d\n", pq->queue[i], pq->priority[i]);
    }
}

int main() {
    struct PriorityQueue pq;
    initQueue(&pq);

    enQueue(&pq, 45, 2);
    enQueue(&pq, 24, 1);
    enQueue(&pq, 85, 3);
    enQueue(&pq, 12, 2);
    enQueue(&pq, 76, 4);

    displayQueue(&pq);

    deQueue(&pq, 3);
    deQueue(&pq, 2);

    displayQueue(&pq);

    return 0;
}
