#include<iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;

        string s;
        cin >> s;

        int ans = 0;

        for (int i = 0; i < n; i += k)
        {
            bool ok = true;

            for (int j = i; j < i + k; j++)
            {
                if (s[j] == '0')
                {
                    ok = false;
                    break;
                }
            }

            if (ok)
                ans++;
        }

        cout << ans << '\n';
    }

    return 0;
}