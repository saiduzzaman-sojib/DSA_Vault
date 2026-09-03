#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    int arr[200];
    int t;
    cin >> t;
    while (t--)
    {
       int n;
       cin >> n;
       bool check = true;
       for (int i = 0; i < n; i++)
       {
           cin >> arr[i];
       }
       for (int i = 0; i < n - 1; i++)
       {
           int diff = abs(arr[i] - arr[i + 1]);
           if (diff != 5 && diff != 7)
           {
              check = false;
              break;
           }
       }
        
       if (check)
       {
           cout << "YES" << endl;
       }
       else
       {
           cout << "NO" << endl;
       }
    }
    
    return 0;
}