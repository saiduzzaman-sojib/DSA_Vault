#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        int odd = 0;
        int e1 = 0;
        int e2 = 0;

        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;

            if (x % 2 == 1)
                odd++;
            else if (x % 4 == 0)
                e1++;
            else
                e2++;
        }

        cout << max({odd, e1, e2}) << '\n';
    }

    return 0;
}