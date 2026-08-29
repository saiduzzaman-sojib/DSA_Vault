#include<iostream>
#include<algorithm>
using namespace std;
int arr[100];
int main()
{
    int n;
    cin>>n;
    while (n--)
    {
       cin>>arr[0]>>arr[1]>>arr[2];
       if (arr[0]==arr[1]||arr[1]==arr[2]||arr[0]==arr[2])
       {
       cout<<0<<endl;
       }
       else{
       sort(arr,arr+3);
       cout<<min(arr[1] - arr[0], arr[2] - arr[1])<<endl;
       }
       
    }
    
    return 0;
}