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

int n;

signed main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    while(true){
        cin >> n;
        if (n == 0) break;
        vi a(n);
        for(auto& c : a) cin >> c;
        sort(all(a));
        cout << a[0];
        for(int i = 1; i < n; i++) cout << " " << a[i];
        cout << endl;
    }
    return 0;
}