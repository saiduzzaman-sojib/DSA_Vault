#include<stdio.h>
#include<stdlib.h>

#define size 10

int top = -1;
int stack[size];

int isFull()
{
    if(top == size-1)
       return 1;
    else 
       return 0;
}


int isEmpty()
{

    if(top == -1)
       return 1;
    else return 0;

}

void push() {
    if (isFull()) {
        printf("Stack overflow\n");
    } else {
        int value;
        scanf("%d", &value);
        stack[++top] = value;
        printf("Pushed Value: %d\n", stack[top]);
    }
}

void pop() {
    if (isEmpty()) {
        printf("Stack underflow\n");
    } else {
        printf("Popped Value: %d\n", stack[top--]);
    }
}

void peek() {
    if (isEmpty()) {
        printf("Stack underflow\n");
    } else {
        printf("Top element: %d\n", stack[top]);
    }
}

void display() {
    if (isEmpty()) {
        printf("Stack is empty\n");
    } else {
        for (int i = top; i >= 0; i--) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice;
    while (1) {
        printf("\n1.Push\n2.Pop\n3.Peek\n4.IsFull\n5.IsEmpty\n6.Display\n7.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: peek(); break;
            case 4: printf(isFull() ? "Stack is Full\n" : "Stack is not Full\n"); break;
            case 5: printf(isEmpty() ? "Stack is Empty\n" : "Stack is not Empty\n"); break;
            case 6: display(); break;
            case 7: exit(0);
            default: printf("Wrong Option\n");
        }
    }
}
