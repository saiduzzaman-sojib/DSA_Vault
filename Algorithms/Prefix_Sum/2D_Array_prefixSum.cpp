/* 
Given 2D array a of N*N integers.Given Q quries and in each query 
given a,b,c and d print sum of square represented by (a,b) as top 
left point and (c,d)as bottom right point.
*/

#include<iostream>
using namespace std;
const int N=1e3+10;
int arr[N][N];
long long pff[N][N];
int main()
{
    int n;
    cin>>n;
    for (int  i = 1; i <= n; i++)
    {
        for (int j = 1; j <=n ; ++j)
        {
           cin>>arr[i][j];
           pff[i][j]=arr[i][j]+pff[i-1][j]+pff[i][j-1]-pff[i-1][j-1];
        }
        
    }
    int q;
    cin>>q;
    while (q--)
    {
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        cout<<pff[c][d]-pff[a-1][d]-pff[c][b-1]+pff[a-1][b-1]<<endl;
    }
    
    
    return 0;
}