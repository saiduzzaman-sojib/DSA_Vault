#include<iostream>
using namespace std;
#include <iomanip>

int main()
{
    double n;
    cin>>n;
    double s=n;
    int sum=0;
    while (s--)
    {
        double a;
        cin>>a;
        sum+=a;
    }
    double avg =sum/n;
    cout<<fixed<<setprecision(12)<<avg;
    return 0;
}