#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// first sort this to ascending order to remove the complexity 
//then just check the most least group by group (n numbers)

int main()
{
    int n, m;
    cin >> n >> m;
    
    vector<int> vec(m);
    for (int i = 0; i < m; i++)
    {
        cin >> vec[i];
    }
    
    sort(vec.begin(), vec.end());
    
    int least = vec[n - 1] - vec[0];
    
    for (int i = 1; i <= m - n; i++)
    {
        if (vec[i + n - 1] - vec[i] < least)
        {
            least = vec[i + n - 1] - vec[i];
        }
    }
    
    cout << least << endl;
    
    return 0;
}
