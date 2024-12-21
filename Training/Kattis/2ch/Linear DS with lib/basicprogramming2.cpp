#include<bits/stdc++.h>

using namespace std;
#define int long long int
using vi = vector<int>;
using vvi = vector<vi>;
using vc = vector<char>;
using vvc = vector<vc>;
#define all(a) a.begin(), a.end()

signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int n,t; cin >> n >> t;
    vi a(n);
    map<int, int> p;
    for(auto& c : a){ 
        cin >> c;
        p[c]++;
    }
    bool f = false;
    if (t == 1){
        for(auto& c : a)
            if (p[7777-c] != 0) f = true;
        if(f) cout << "Yes";
        else cout << "No";
    }
    if (t == 2){
        for(auto [key, val] : p)
            if (val != 1) f = true;
        if (!f) cout << "Unique";
        else cout << "Contains duplicate";
    }
    if (t == 3){
        int k = -1;
        for(auto [key, val] : p)
            if (val > n/2) k = key;
        cout << k;
    }
    if (t == 4){
        sort(all(a));
        if (n % 2 == 1) cout << a[n/2];
        else printf("%d %d", a[n/2-1], a[n/2]);
    }
    if (t == 5){
        for(int i = 100; i < 1000; i++){
            while(p[i] != 0){
                cout << i << " ";
                p[i]--;
            }
        }
    }
    return 0;
}