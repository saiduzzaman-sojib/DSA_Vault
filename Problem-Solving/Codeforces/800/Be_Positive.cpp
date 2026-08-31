#include<iostream>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        int arr[100];
        int count_minus=0;
        int count_zero=0;
        
        for (int i = 0; i < n; i++)
        {
            cin>>arr[i];
            if(arr[i]==-1)
            {
                count_minus++;
            }
            else if(arr[i]==0)
            {
                count_zero++;
            }
        }
        
        int operations = count_zero;
        
        if (count_minus % 2 != 0)
        {
            operations += 2;
        }
        
        cout<<operations<<"\n";
    }
    
    return 0;
}