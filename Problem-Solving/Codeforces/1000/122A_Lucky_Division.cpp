#include<iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    bool lucky=false;
    int arr[]={4,7,44,77,47,74,444,777,447,474,774,747,477,744};
    for (int i = 0; i < 14; i++)
    {
       if (n%arr[i]==0)
       {
        lucky=true;
        break;
       }
       
    }
    if (lucky)
    {
        cout<<"YES";
    }
    else
    {
        cout<<"NO";
    }
    
    return 0;
}