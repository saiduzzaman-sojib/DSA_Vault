#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int arr[7];
    int sum=0;
    while(n--){
    for (int i = 0; i < 7; i++)
    {
        cin>>arr[i];
        sum+=arr[i];
    }
    int mx=*max_element(arr,arr+7);
    cout<<-sum+(2*mx)<<endl;
    sum=0;

}
    
    return 0;
}