#include<iostream> 
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>
#include<cmath>

using ll = long long;
using namespace std;

int n, m;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    vector<int> nums(n);
    for(auto& c : nums) cin >> c;
    cin >> m;
    vector<ll> sum(n+1, 0);
    sum[1] = nums[0];
    for(int i = 0; i < sum.size()-1; i++){
        sum[i+1] = sum[i]+nums[i];
        // cout << sum[i+1] << " ";
    }
    // cout << endl;
    for(int j = 0; j < m; j++){
        int l, r;
        cin >> l >> r;
        cout << sum[r] - sum[l-1] << " ";
    }
    
    return 0;
}