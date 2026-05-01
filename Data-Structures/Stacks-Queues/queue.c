#include <stdio.h>
#define size 5

int arr[size];
int front = -1, rear = -1;

void insertion(int n)
{
    if (rear == size - 1) {
        printf("Overflow\n");
        return;
    }
    if (front == -1 && rear == -1) { 
        front = rear = 0;

    } else 
    {
        rear++;
    }
    arr[rear] = n;
}

void deletion()
{
    if (front == -1)
     {
        printf("Underflow\n");
        return;
    }

    if (front == rear)
     { 
        front = rear = -1;
    }
     else {
        front++;
    }
}

void display()
{
    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements:\n");
    for (int i = front; i <= rear; i++) {
        printf("%d\n", arr[i]);
    }
}

int main()
{
    insertion(10);
    insertion(20);
    deletion();
    insertion(30);
    deletion();
    display();

    return 0;
}
