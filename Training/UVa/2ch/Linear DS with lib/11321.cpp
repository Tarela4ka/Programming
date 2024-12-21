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

bool cmp(int a, int b){
    if (a % m < b % m){
        return true;
    }else if (a % m > b % m){
        return false;
    }
    if (abs(a % 2) > abs(b % 2)){
        return true;
    }else if (abs(a % 2) < abs(b % 2)){
        return false;
    }
    if (abs(a % 2) == 1){
        return a > b;
    }else{
        return b > a;
    }
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    while(true){
        cin >> n >> m;
        cout << n << " " << m << endl;
        if (n == 0 && m == 0) break;
        vi a(n);
        for(auto& c : a) cin >> c;
        sort(all(a), cmp);
        for(auto c : a) cout << c << endl;
    }
    return 0;
}