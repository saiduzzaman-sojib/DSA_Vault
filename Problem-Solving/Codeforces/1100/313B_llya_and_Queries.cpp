#include<iostream>
using namespace std;

int const N=1e5+10;
int pf[N];
int arr[N];

int main()
{
    string str;
    cin>>str;

    for (int i = 1; i < str.size(); i++)
    {
        if(str[i]==str[i-1])
        {
            arr[i]=1;
        }
        else
        {
            arr[i]=0;
        }
    }

    for (int i = 1; i < str.size(); i++)
    {
        pf[i]=arr[i]+pf[i-1];
    }

    int n;
    cin>>n;

    while (n--)
    {
        int l,r;
        cin>>l>>r;

        cout<<pf[r-1]-pf[l-1]<<endl;
    }

    return 0;
}