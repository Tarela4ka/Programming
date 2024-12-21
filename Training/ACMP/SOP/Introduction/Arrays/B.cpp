#include<bits/stdc++.h>

using namespace std;
const int N = 1e5+4;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n,m; cin >> n >> m;
    vector<int> p1(N), p2(N);
    for(int i = 0; i < n; i++){
        int c; cin >> c;
        p1[c]++;
    }
    for(int i = 0; i < m; i++){
        int c; cin >> c;
        p2[c]++;
    }
    for(int num = 0; num <= N; num++){
        if (p1[num] && p2[num]){
            cout << num << " ";
        }
    }
    return 0;
}