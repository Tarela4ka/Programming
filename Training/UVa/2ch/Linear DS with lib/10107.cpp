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
    vi a; int n;
    int len = 0;
    while(cin >> n){
        a.push_back(n);
        len++;
        if (len%2){
            auto m = a.begin()+len/2;
            nth_element(a.begin(), m, a.end());
            cout << a[len/2] << endl;
        }else{
            auto m = a.begin()+len/2;
            nth_element(a.begin(), m, a.end());
            nth_element(a.begin(), m-1, a.end());
            cout << (a[len/2]+a[len/2-1])/2 << endl;
            
        }
    }
}