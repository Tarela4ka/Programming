#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
#define int long long int
#define all(a) a.begin(), a.end()
using vi = vector<int>;
using vvi = vector<vi>;
using vc = vector<char>;
using vvc = vector<vc>;
using vs = vector<string>;

bool comp(string a, string b){
    return (a[0] < b[0]) || (a[0] == b[0] && a[1] < b[1]);
}
 

signed main(){
    int n, k = 0;
    while(true){
        cin >> n;
        if (n == 0) break;
        vector<string> a(n);
        for(auto& c : a) cin >> c;
        // for(auto& c : a) cin >> c;
        stable_sort(all(a), comp);
        for(auto& c : a) cout << c << endl;
        cout << endl;
    }
}