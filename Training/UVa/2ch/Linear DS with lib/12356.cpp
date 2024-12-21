#include<bits/stdc++.h>

using namespace std;
// #define int long long int
// #define all(a) a.begin(), a.end()

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    while(true){
        int n,m;
        cin >> n >> m;
        if (n == 0 && m == 0) break;
        set<int> s;
        for(int i = 1; i <= n; i++) s.insert(i);
        for(int i = 0; i < m; i++){
            int l,r;
            cin >> l >> r;
            auto left = s.find(l), right = s.find(r); right++;
            s.erase(left, right);
                
            auto it = s.lower_bound(l); 
            if (it != s.begin()) {
                it--;
                cout << *it << " ";
                it++;
            }else cout << "* ";

            if (it != s.end()) cout << *it << "\n";
            else cout << "*\n";
        }
        cout << "-\n";
    }
    return 0;
}
