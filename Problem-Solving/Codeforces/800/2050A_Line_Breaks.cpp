#include<iostream>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while (t--)
    {
       int n,s;
       cin>>n>>s;
       string str[1000];
       
       int sum=0;
       int ans=n; 
       
       for (int i = 0; i < n; i++)
       {
        cin>>str[i];
        sum+=str[i].length();
        
        if (sum>s && ans==n) 
        {
            ans = i; 
        }
       }
       
       cout<<ans<<endl; 
    }
    
    return 0;
}