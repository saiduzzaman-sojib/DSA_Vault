#include <stdio.h>
#include <stdlib.h>

#define size 6
int arr[size];
int top=-1;

void push(){
    if (top==size-1)
    {
       printf("Overflow\n");
    }
    else
   
    {
        int value;
        printf("Enter the value:\n");
        scanf("%d",&value);
        top=top+1;
        arr[top]=value;
    }

}
void pop(){
    if (top==-1)
    {
       printf("Underflow\n");
    }
    else
    {
        top=top-1;
    }
    
}
void show(){
    if (top==-1)
    {
        printf("The stack is empty \n");
    }
    else 
    {
        for (int  i = top; i >=0; i--)
        {
            printf("%d\n",arr[i]);
        }
        
    }
    
}
int main() { 
    
    int choice;
    
    while (1)
    {  printf("1.Push item\n2.pop item\n3.show item\n4.Exit\n");
       printf("Enter your choice\n");
       scanf("%d",&choice);
       switch (choice)
       {
       case 1:push();break;
       case 2:pop();break;
       case 3:show();break;
       case 4:exit(0);
       default:printf("Enter a valid point\n");


       }
    }

}
