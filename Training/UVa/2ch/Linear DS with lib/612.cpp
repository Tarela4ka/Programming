#include<bits/stdc++.h>

using namespace std;
#define int long long int
using vi = vector<int>;
using vvi = vector<vi>;
using vc = vector<char>;
using vvc = vector<vc>;
using vs = vector<string>;
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()

int n, m;

bool cmp(pair<int, string> a, pair<int, string> b){
    return (a.first < b.first);
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    int T; cin >> T;
    while(T--){
        cin >> m >> n;
        vs a(n);
        vector<pair<int, string>> s;
        for(auto& c : a) cin >> c;
        for(auto c : a){
            string temp = c;
            int inv = 0;
            for(int i = 0; i < m; i++){
                for(int j = 1; j < m; j++){
                    if (temp[j-1] > temp[j]){
                        swap(temp[j-1], temp[j]);
                        inv++;
                    }
                }
            }
            s.push_back({inv, c});
        }
        stable_sort(all(s), cmp);
        for(auto [i, l] : s){
            cout << l << endl;
        }
        if (T>0) cout << endl;
    }
    return 0;
}