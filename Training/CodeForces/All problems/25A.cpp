#include<bits/stdc++.h>

using namespace std;
#define int long long int
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define mk(a,b) make_pair(a,b)
using vi = vector<int>;
using vvi = vector<vi>;
using vc = vector<char>;
using vvc = vector<vc>;
using vs = vector<string>;
using ii = pair<int, int>;
using vii = vector<ii>;

signed main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int n; cin >> n;
    int c1 = 0, c2 = 0, n1, n2;
    for(int i = 0; i < n; i++){
        int c;
        cin >> c;
        if (c % 2 == 0){
            c1++; n1 = i;
        } else{
            c2++; n2 = i;
        }
    }
    if (c1 > c2){
        cout << n2+1;
    }else{
        cout << n1+1;
    }
    return 0;
}