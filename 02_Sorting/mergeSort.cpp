#include<iostream>
#include<vector>
using namespace std;

// Function to merge two sorted sub-arrays back together
void merge (vector<int>&arr,int start,int mid,int end)
{
    vector<int>temp;
    int i=start, j=mid+1;
    while(i<=mid && j<=end)
    {
        if(arr[i]<=arr[j])//control accending or decending
        {
            temp.push_back(arr[i]);
            i++;
        }else {
            temp.push_back(arr[j]);
            j++;
        }
    }
    while(i<=mid)// If left sub-array has remaining elements
    {
        temp.push_back(arr[i]);
        i++;
    }
    while(j<=end)// If right sub-array has remaining elements
    {
        temp.push_back(arr[j]);
        j++;
    }
    // Copy the merged elements back into the original array
    for(int idx=0;idx<temp.size();idx++)
    {
        arr[idx+start]= temp[idx];
    }
}

// Recursive function to divide the array
void mergeSort (vector<int> &arr,int start,int end)
{
    if(start<end)
    {
        int mid=start+(end-start)/2;
        mergeSort(arr,start,mid);//Left half
        mergeSort(arr,mid+1,end);//Right half
        merge(arr,start,mid,end);
    }
}

int main()
{
    vector<int>arr={7,6,5,9,2,3,4,6,9,8,6,5,7,8};
    mergeSort(arr,0,arr.size()-1);
    for(int val : arr)
    {
        cout<< val << " ";
    }
    cout<<endl;
    return 0;
}
