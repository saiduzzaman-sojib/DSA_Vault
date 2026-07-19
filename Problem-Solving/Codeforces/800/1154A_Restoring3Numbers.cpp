#include<iostream>
#include<vector>
#include<algorithm>

//Sort 
using namespace std;

int main()
{
    vector<int>vec;
    int n=4;
    int x;
    while (n--)
    {
        cin>>x;
       vec.push_back(x);
    }
    sort(vec.begin(),vec.end());

    for (int i = 2; i >= 0; i--)
    {
       cout<<vec[3]-vec[i]<<" ";
    }
    
    return 0;
}
