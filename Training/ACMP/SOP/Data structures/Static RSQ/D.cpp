#include<iostream> 
// #include<string>
#include<vector>
// #include<algorithm>
// #include<queue>
// #include<map>
// #include<cmath>

using ll = long long;
using namespace std;

int n, m, k;
const int INF = 1e9;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    vector<vector<int>> nums(n, vector<int>(m));
    for(auto& c : nums)
        for(auto& v : c)
            cin >> v;

    vector<vector<ll>> sums(n, vector<ll>(m));
    sums[0][0] = nums[0][0];
    for(int i = 1; i < n; i++)
        sums[i][0] = sums[i-1][0] + nums[i][0];
    for(int i = 1; i < m; i++)
        sums[0][i] = sums[0][i-1] + nums[0][i];
    for(int i = 1; i < n; i++)
        for(int j = 1; j < m; j++)
            sums[i][j] = sums[i-1][j] + sums[i][j-1] - sums[i-1][j-1] + nums[i][j];
    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < m; j++){
    //         cout << sums[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    ll maxSum = -INF;
    for(int y1 = 0; y1 < n; y1++){
        for(int x1 = 0; x1 < m; x1++){
            for(int y2 = y1; y2 < n; y2++){
                for(int x2 = x1; x2 < m; x2++){
                    ll sum = sums[y2][x2];
                    if (x1-1 >= 0)
                        sum -= sums[y2][x1-1];
                    if (y1-1 >= 0)
                        sum -= sums[y1-1][x2];
                    if (y1-1 >= 0 && x1-1 >= 0)
                        sum += sums[y1-1][x1-1];
                    maxSum = max(sum, maxSum);
                }
            }
        }
    }

    cout << maxSum;
    return 0;
}