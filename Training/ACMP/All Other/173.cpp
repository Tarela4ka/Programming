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

bool isPalindrom(string s){
    for(int i = 0; i < s.length()/2; i++){
        if (s[i] != s[s.length()-i-1]){
            return false;
        }
    }
    return true;
}

signed main(){
    ios::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n; cin >> n;
    // string n; cin >> n;
    v<int> ans;
    for(int base = 2; base <= 36; base++){
        int temp = n;
        string s = "";
        while(temp){
            if (temp % base > 9){
                s += char(temp%base + 'A' - 1);
            }else{
                s += (temp%base + '0');
            }
            temp /= base;
        }
        reverse(all(s));
        if (isPalindrom(s)){
            ans.push_back(base);
        }
    }
    if(ans.size() == 1){
        cout << "unique\n";
        cout << ans[0];
    }else if (ans.size() > 1){
        cout << "multiple\n";
        fe(c, ans) cout << c << " ";
    }else{
        cout << "none";
    }
    return 0;
}