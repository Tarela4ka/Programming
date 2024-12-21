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

signed main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n; cin >> n;
    int s = sqrt(n);
    vi del;
    for(int i = 2; i <= s; i++){
        while(n%i == 0){
            del.push_back(i);
            n/=i;
        }
    }
    if (n != 1) del.push_back(n);
    cout << del[0];
    for(int i = 1; i < del.size(); i++){
        cout << "*" << del[i];
    }
    return 0;
}