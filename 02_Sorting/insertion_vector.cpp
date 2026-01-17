#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int n, i, j, key;
    cin >> n;
    vector<int> arr(n);
    
    for(i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Current element" << endl;
    for(i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    for(i = 1; i < n; i++)
    {
        key = arr[i];
        for(j = i - 1; j >= 0 && arr[j] > key; j--)
        {
            arr[j + 1] = arr[j];
        }
        arr[j + 1] = key;
    }

    cout << endl;
    cout << "Sorted Array";
    for(i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
