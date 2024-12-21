#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>

using namespace std;
#define int long long int
#define all(a) a.begin(), a.end()
using vi = vector<int>;
using vvi = vector<vi>;
using vc = vector<char>;
using vvc = vector<vc>;
using vs = vector<string>;

bool cmp(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b){
    auto [h1, s1] = a;
    auto [w1, l1] = s1;
    auto [h2, s2] = b;
    auto [w2, l2] = s2;
    if (h1 > h2){
        return true;
    }else if (h1 < h2){
        return false;
    }
    return (w1*h1*l1 > w2*h2*l2);
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    vector<pair<int, pair<int, int>>> a;
    while(true){
        int n; cin >> n;
        if (n == 0) break;
        a.resize(n);
        for(auto& [h, s] : a){
            auto& [w, l] = s;
            cin >> w >> l >> h;
        }
        sort(all(a), cmp);
        // for(auto [h, s] : a){
        //     auto [w, l] = s;
        //     cout << w << " " << l << " " << h << endl;
        // }
        // cout << endl;
        auto [h, s] = a[0];
        auto [w, l] = s;
        cout << h*w*l << endl;
    }
}