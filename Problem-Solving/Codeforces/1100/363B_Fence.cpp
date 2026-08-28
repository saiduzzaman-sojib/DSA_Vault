#include<iostream>
#include <algorithm>
using namespace std;
int const N=2e5+10;
int arr[N];
int pf[N];

int main()
{
    int n,k;
    cin>>n>>k;
    for (int i = 1; i <= n ; i++)
    {
        cin>>arr[i];
        pf[i]=arr[i]+pf[i-1];
    }
    
    for (int i = 0; i <= n-k; i++)
    {
       arr[i]=pf[k+i]-pf[i];
    }
    
    int min=arr[0];
    int index=1;
    for (int i = 0; i <= n-k; i++)
    {
        if (arr[i]<min)
        {
            min=arr[i];
            index=i+1;
        }
    }
    
    cout<<index<<endl;
    
    return 0;
}