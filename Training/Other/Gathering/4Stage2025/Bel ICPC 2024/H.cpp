#include<bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

using namespace std;
#define int long long int
#define lll __int128_t
#define fr(i, a, b) for (int i = (a); i <= (b); ++i)
#define rf(i, a, b) for (int i = (a); i >= (b); --i)
#define fe(x, y) for (auto& x : y)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define mk(a,b) make_pair(a,b)
#define lc(S) ((S<<1)+1)
#define rc(S) ((S<<1)+2)
using ii = pair<int, int>;
using ic = pair<int, char>;
template <typename T>
using v = vector<T>;
using vi = v<int>;
using vvi = v<vi>;

const int MOD = 998244353;
const int INF = 1e9+10;

signed main(){
    ios::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);
    #ifdef DEBUG
    clock_t t1,t2;
    t1=clock();
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    // int t; cin >> t;
    // while(t--){
        string s; getline(cin, s);
        cout << "What is the name of your team?\nOur name is " << s << ".\n";
        cout << "My apologies, I did not understand. What is your team name?\nWe are team " << s << ".\n";
        fe(c, s){
            if (c >= 'a' && c <= 'z') {
                c-='a';
                c+='A';
            }
        }
        cout << "I am really sorry. Could you please repeat it once again?\nWE ARE TEAM " << s << "!!!\n";    
        cout << "Oh, now I see. Here are your badges. Good luck!";
    // }

    #ifdef DEBUG
    t2=clock();
    float diff ((float)t2-(float)t1);
    cout << '\n' << diff << "ms\n";
    #endif
}