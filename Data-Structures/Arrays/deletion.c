#include <stdio.h>

int main() { 
    int size,position,n;
    printf("Enter the array size:");
    scanf("%d",&size);
    int arr[size];
    printf("Enter the number of element:");
    scanf("%d",&n);
    printf("Enter the value of the array :\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Youe current array is :\n");
    for (int  i = 0; i < n; i++)
    {
       printf("%d\n",arr[i]);
    }
    printf("Enter the position you want to delet value :\n");
    scanf("%d",&position);
    
    for (int i = position-1; i < n-1; i++)
    {
        arr[i]=arr[i+1];
    }
    printf("New array is :\n");
    for (int i = 0; i < n-1; i++)
    {
        printf("%d\n",arr[i]);
    }
    
    return 0;
}
