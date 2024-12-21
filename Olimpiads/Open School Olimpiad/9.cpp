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

int ans = 0;
const string ROOT = "";

signed main(){
    ios::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    v<string> l = {"abbcaabbccabcabc", "abbcaabbcccabcabc", "abbcaabbccaabcabc", "abbcaabbccbacabc", "abbcaabbcabcabc", "abbcaabbccabcacb"};
    for(int k = 0; k < 6; k++){
        int n = 5;
        v<string> S;
        for(int i = 0; i < 6; i++) {
            if (i != k){
                S.push_back(l[i]);
            }
        }
        map<string, set<char>> m;
        int i = 0;
        string cur_V = ROOT;
        while( i < n ){
            S[i] = S[i] + '.'; int j = 0;
            while(j < S[i].length()){
                if (m[cur_V].find(S[i][j]) == m[cur_V].end()){
                    m[cur_V].insert(S[i][j]);
                } 
                cur_V = S[i].substr(0, j+1);
                j++;
            }
            i++;
        }
        // fe(p, m){
        //     cout << p.first << ": ";
        //     fe(c, p.second){
        //         cout << c << " ";
        //     }
        //     cout << endl;
        // }
        cur_V = ROOT;
        int ans = 0;
        while(m[cur_V].size() == 1){
            ans++;
            cur_V = cur_V + *(m[cur_V].begin());
        }
        cout << ans << endl;
    }
    return 0;
}