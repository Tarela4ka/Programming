#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>

using namespace std;
// #define int long long int
#define all(a) a.begin(), a.end()
using vi = vector<int>;
using vvi = vector<vi>;
using vc = vector<char>;
using vvc = vector<vc>;
using vs = vector<string>;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    map<pair<int, pair<int, int>>, string> r;
    for(int i = 0; i < n; i++){
        string s; int d,m,y;
        cin >> s >> d >> m >> y;
        r[{y,{m, d}}] = s;
    }
    cout << (*r.rbegin()).second << endl << (*r.begin()).second << endl;
}