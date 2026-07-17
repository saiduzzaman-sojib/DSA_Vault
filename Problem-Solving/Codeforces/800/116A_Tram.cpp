#include<iostream>
using namespace std;
 
int main()
{
    int n;
    cin>>n;
    int max=0;
    int total=0;
    int arr[1005][2];
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cin>>arr[i][j];
        }
    }
 
    for (int i = 0; i < n; i++)
    {
        total = total - arr[i][0] + arr[i][1];
        
        if(max < total){
            max = total;
        }
    }
    
    cout<<max;
    
    return 0;
}
