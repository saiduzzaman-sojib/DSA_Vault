#include<iostream>
using namespace std;

int main()
{
    int t;
    cin>>t;
    string str;
    while (t--)
    {
        int n;
        cin>>n;
        int f=0,l=0;
        cin>>str;
        for (int i = 0; i < n; i++)
        {          
            if (str[i]=='(')
            {
                f++;
            }else l++;
            
        }
    
        if(f==l){
            cout<<"YES"<<endl;
        }else cout<<"NO"<<endl;
    
        f=0;
        l=0;
    }
    
    return 0;
}