#include <stdio.h>
#include <stdlib.h>

int front = -1, rear = -1, size = 0;
int Q[100];

void sizeofqueue(int n) {
    size = n;
    front = -1;
    rear = -1;
}

int isFull() {
    return (rear == size - 1);
}

int isEmpty() {
    return (front == -1 || front > rear);
}

void enqueue(int element) {
    if (isFull()) {
        printf("Queue is full!!! Cannot enqueue %d\n", element);
    } else {
        if (front == -1) front = 0;
        rear++;
        Q[rear] = element;
        printf("Enqueued value: %d\n", element);
    }
}

void dequeue() {
    if (isEmpty()) {
        printf("Queue is empty!!! No elements to dequeue!\n");
    } else {
        printf("Dequeued element: %d\n", Q[front]);
        front++;
    }
}

void displayQueue() {
    if (isEmpty()) {
        printf("--Queue is empty-- No elements to display\n");
    } else {
        printf("Queue elements: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", Q[i]);
        }
        printf("\n");
    }
}

void displayFront() {
    if (isEmpty()) {
        printf("Queue is empty! No front element to display\n");
    } else {
        printf("Front element: %d\n", Q[front]);
    }
}

int main() {
    int n, ch, element;
    printf("Enter the size of the queue: ");
    scanf("%d", &n);
    sizeofqueue(n);

    do {
        printf("\nOptions:\n");
        printf("1) Enqueue\n");
        printf("2) Dequeue\n");
        printf("3) Display Front\n");
        printf("4) Display All\n");
        printf("5) Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &element);
                enqueue(element);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                displayFront();
                break;
            case 4:
                displayQueue();
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (ch != 5);

    return 0;
}
