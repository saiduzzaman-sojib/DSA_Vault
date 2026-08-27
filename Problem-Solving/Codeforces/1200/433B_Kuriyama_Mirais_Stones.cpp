#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 1e5 + 10;
long long arr[N], temp[N];
long long pf1[N], pf2[N];

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        temp[i] = arr[i];
    }

    sort(temp + 1, temp + n + 1);

    for (int i = 1; i <= n; i++)
    {
        pf1[i] = pf1[i - 1] + arr[i];
        pf2[i] = pf2[i - 1] + temp[i];
    }
    
    int q;
    cin >> q;
    while (q--)
    {
        int a, b, c;
        cin >> a >> b >> c;

        if (a == 1)
        {
            cout << pf1[c] - pf1[b - 1] << "\n";
        }
        else
        {
            cout << pf2[c] - pf2[b - 1] << "\n";
        }
    }
    
    return 0;
}