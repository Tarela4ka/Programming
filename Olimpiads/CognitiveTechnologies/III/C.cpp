#include<bits/stdc++.h>

using namespace std;
#define int long long int
#define fr(i, a, b) for (int i = (a); i <= (b); ++i)
#define rf(i, a, b) for (int i = (a); i >= (b); --i)
#define fe(x, y) for (auto& x : y)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define mk(a,b) make_pair(a,b)
using ii = pair<int, int>;
template <typename T>
using v = vector<T>;

const int MOD = 1000000007;
const int INF = 1000000007;

signed main(){
    ios::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);
    #ifdef DEBUG
    clock_t t1,t2;
    t1=clock();
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        string s; cin >> s;
        stack<char> q;
        q.push(s[0]);
        fr(i, 1, n-1){
            if (s[i] + 1 == q.top()){
                while(!q.empty() && char(s[i] + 1) == q.top()) q.pop();

                if (!q.empty()){
                    if (char(s[i] - 1) != q.top())
                        q.push(s[i]);
                }else q.push(s[i]);
            }else{ 
                if (char(s[i] - 1) != q.top())
                    q.push(s[i]);
            }
        }
        string ans = "";
        while(!q.empty()){
            ans += q.top();
            q.pop();
        }
        reverse(all(ans));
        cout << ans << endl;
    }

    #ifdef DEBUG
    t2=clock();
    float diff ((float)t2-(float)t1);
    cout << '\n' << diff << "ms";
    #endif
    return 0;
}