#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int arr[100];
    int n;
    float sum=0,count=0;
    cin>>n;

    for (int i = 0; i < n; i++)
    {
       cin>>arr[i];
       sum+=arr[i];
    }

    sort(arr,arr+n);

    float k=sum/2;
    float taken=0;

    for (int i = n-1; i >= 0; i--)
    {
        taken += arr[i];
        count++;

        if (taken > sum-taken)
        {
            break;
        }
    }

    cout<<count<<endl;

    return 0;
}