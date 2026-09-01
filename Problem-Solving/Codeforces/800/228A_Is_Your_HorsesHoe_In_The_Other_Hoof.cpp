#include<iostream>
#include<algorithm>
using namespace std;

const int N=1e5+10;
int arr[N];

int main()
{
    int s1,s2,s3,s4;
    for (int i = 0; i < 4; i++)
    {
       cin>>arr[i];
    }
    
    sort(arr, arr + 4);
    
    int count=0;
    int init=arr[0];
    for (int i = 1; i < 4; i++)
    {
        if (init!=arr[i])
        {
           init=arr[i];
        }
        else{
            count++;
        }
    }
    cout<<count<<endl;
    
    return 0;
}