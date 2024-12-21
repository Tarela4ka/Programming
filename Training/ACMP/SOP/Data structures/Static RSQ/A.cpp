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
    for(;m--;){
        string s; int l, r;
        cin >> s;
        if (s == "rsq"){
            cin >> l >> r; l--; r--;
            int sum = 0;
            for(int i = l; i <= r; i++) sum+=nums[i];
            cout << sum << "\n";
        } else if (s == "update"){
            cin >> l >> r; l--; r--;
            int x; cin >> x;
            for(int i = l; i <= r; i++) nums[i]=x;
        } else if (s == "rmq"){
            cin >> l >> r; l--; r--;
            int m = 1e9;
            for(int i = l; i <= r; i++) m = min(m, nums[i]); 
            cout << m << "\n";
        } else if (s == "add"){
            cin >> l >> r; l--; r--;
            int x; cin >> x;
            for(int i = l; i <= r; i++) nums[i]+=x;
        } else if (s == "get"){ 
            int x; cin >> x; x--;
            // for(int i = 0; i < n; i++) cout << nums[i] << " ";
            cout << nums[x] << "\n";
        }

    }
    
    return 0;
}