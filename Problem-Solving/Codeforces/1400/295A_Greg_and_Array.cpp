
#include <iostream>
using namespace std;

const int N = 1e5 + 10;

long long arr[N];
long long diff[N];

struct Data {
    int l;
    int r;
    int d;
};

struct Query {
    int s;
    int p;
};

void update(long long diff[], int l, int r, long long val) {
    diff[l] += val;
    diff[r + 1] -= val;
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    Data operation[m + 1];

    for (int i = 1; i <= m; i++) {
        cin >> operation[i].l
            >> operation[i].r
            >> operation[i].d;
    }

    long long operationDiff[m + 2] = {0};

    for (int i = 1; i <= k; i++) {
        int s, p;
        cin >> s >> p;

        operationDiff[s]++;
        operationDiff[p + 1]--;
    }

    long long operationCount = 0;

    for (int i = 1; i <= m; i++) {
        operationCount += operationDiff[i];

        update(
            diff,
            operation[i].l,
            operation[i].r,
            operation[i].d * operationCount
        );
    }

    long long current = 0;

    for (int i = 1; i <= n; i++) {
        current += diff[i];
        arr[i] += current;
    }

    for (int i = 1; i <= n; i++) {
        cout << arr[i] << " ";
    }

    cout << '\n';

    return 0;
}
```
