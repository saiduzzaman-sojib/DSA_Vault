#include<iostream>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while (t--)
    {
       int n,s,x;
       int sum=0;
       int arr[1000];
       cin>>n>>s>>x;
       for (int i = 0; i < n; i++)
       {
        cin>>arr[i];
        sum+=arr[i];
       }
       int k=s-sum;
       if (sum==s)
       {
       cout<<"YES"<<endl;
       }
       else if(sum>s){
        cout<<"NO"<<endl;
       }
       else if(k%x==0){
        cout<<"YES"<<endl;
       } else cout<<"NO"<<endl;
    }
    
    return 0;
}