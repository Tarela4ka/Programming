#include<bits/stdc++.h>

using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using vc = vector<char>;
using vvc = vector<vc>;
using vs = vector<string>;
#define int long long int
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()

signed main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    while(true){
        int n; cin >> n;
        if (n == 0) break;
        vs a(n);
        for(auto& c : a) cin >> c;
        sort(all(a));
        string s1 = a[n/2-1], s2 = a[n/2];
        // cout << s1 << " " << s2 << "\n";
        string ans = ""; int k = 0;
        while(s1[k]==s2[k]){
            ans += s1[k];
            k++;
            if (k >= s1.length() || k >= s2.length()) break;
        }
        int l = ans.length()-1;
        while(true){
            if (ans >= s1 && ans < s2) break;
            ans += 'A';
            l++;
            char let; bool f = false;
            for(int i = 'A'; i <= 'Z'; i++){
                ans[l] = i;
                if (ans >= s1 && ans < s2) break;
                if (!f){
                    if (l < s1.length() && l < s2.length()){
                        if (ans[l] >= s1[l] && ans[l] < s2[l]){
                            let = i;
                            f = true;
                        }
                    }else if (l < s1.length()){
                        if (ans[l] >= s1[l]) {
                            let = i;
                            f = true;
                        }
                    }else if (l < s2.length()){
                        if (ans[l] < s2[l]) {
                            let = i;
                            f = true;
                        }
                    }
                }
            }
            if (ans >= s1 && ans < s2) break;
            ans[l] = let;
            if (l >= s1.length()) break;
        }
        cout << ans << endl;
    }

    // cout << ('C' <= 'C' && "C" > "D");
    return 0;
}