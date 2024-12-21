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

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m >> k;
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
    // for(auto& c : sums){
    //     for(auto& v : c)
    //         cout << v << " ";
    //     cout << endl;
    // }
    for(; k--; ){
        int y1, x1, y2, x2;
        cin >> y1 >> x1 >> y2 >> x2;
        y1-=2; x1-=2; y2--; x2--;
        ll sum = sums[y2][x2];
        // cout << sum << " "; 
        if (y1 >= 0){
            sum -= sums[y1][x2];
        } 
        if (x1 >= 0){
            sum -= sums[y2][x1];
        }
        if (x1 >= 0 && y1 >= 0){
            sum += sums[y1][x1];
        }
        cout << sum << endl;
    }
    return 0;
}