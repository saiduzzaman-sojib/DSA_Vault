#include<iostream>
using namespace std;

int main()
{
    int i, j, minindex, n, temp;
    cin >> n;
    int arr[n];

    for (i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (i = 0; i < n - 1; i++)
    {
        minindex = i;
        for (j = i + 1; j < n; j++)
        {
            if (arr[minindex] > arr[j])
            {
                minindex = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[minindex];
        arr[minindex] = temp;
    }

    for (i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
