#include<iostream>
#include<vector>

using namespace std;
#define int long long int

signed main(){
    // ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int n; cin >> n;
    vector<bool> s(n+1, 1);
    int ans = 0;
    ans++; 
    for(int j = 4; j <= n; j+=2){
        s[j] = 0;
    }
    for(int i = 3; i <= n; i+=2){
        if(!s[i]) continue;
        ans++; 
        for(int j = i*3; j <= n; j+=2*i) s[j] = 0;
    }
    cout << ans;
    return 0;
}