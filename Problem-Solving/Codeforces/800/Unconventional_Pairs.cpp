#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int t;
    cin >> t;
    
    while (t--)
    {
       int n;
       cin >> n;
       int arr[n];
       for (int i = 0; i < n; i++)
       {
           cin >> arr[i];
       }
       
       sort(arr, arr + n);
       
       int max_diff = 0;
       for (int i = 0; i < n; i += 2)
       {
           int current_diff = arr[i+1] - arr[i];
           if (current_diff > max_diff) 
           {
               max_diff = current_diff;
           }
       }
       
       cout << max_diff << "\n";
    }
    
    return 0;
}