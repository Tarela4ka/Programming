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

bool isPalindrome(string s){
    int l = 0, r = s.length()-1;
    while(l <= r){
        if (s[l] != s[r]) return 0;
        l++; r--;
    }
    return 1;
}

signed main(){
    ios::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    string s;
    int n, ans = 0;
    getline(cin, s);
    n = s.length();
    if (isPalindrome(s)){
        int l = n/2 - !(n%2), r = n/2, mid = r;
        if (l == r){
            ans++;
            mid = l;
            l--; r++;
        }
        for(;s[l] == s[mid] && s[r] == s[mid] && l>=0 && r <= n; r++, l--, ans+=2);
    }else{
        int l,r;
        for(l = 0, r = n-1; s[l]==s[r]; r--,l++);
        ans += isPalindrome(s.substr(0,l)+s.substr(l+1, n));
        ans += isPalindrome(s.substr(0,r)+s.substr(r+1, n));
    }

    cout << ans;
    return 0;
}