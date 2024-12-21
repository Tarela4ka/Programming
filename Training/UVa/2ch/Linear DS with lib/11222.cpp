#include<bits/stdc++.h>

using namespace std;
// #define int long long int
// #define all(a) a.begin(), a.end()

const int N = 1e4+5;

signed main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int cases; cin >> cases;
    for(int caseN = 1; caseN <= cases; caseN++){
        int n1, n2, n3;
        vector<int> p1(N), p2(N), p3(N);
        cin >> n1;
        for(int i = 0; i < n1; i++){
            int c; cin >> c;
            p1[c]++;
        }
        cin >> n2;
        for(int i = 0; i < n2; i++) {
            int c; cin >> c;
            p2[c]++;
        }
        cin >> n3;
        for(int i = 0; i < n3; i++) {
            int c; cin >> c;
            p3[c]++;
        }
        vector<int> ans1, ans2, ans3;
        for(int i = 0; i < N; i++){
            if (p1[i] && !p2[i] && !p3[i]) ans1.push_back(i);
            if (!p1[i] && p2[i] && !p3[i]) ans2.push_back(i);
            if (!p1[i] && !p2[i] && p3[i]) ans3.push_back(i);
        }
        int a = ans1.size(), b = ans2.size(), c = ans3.size();
        printf("Case #%d:\n", caseN);
        if (a >= b && a >= c){
            cout << 1 << " " << a;
            for(auto z : ans1)
                cout << " " << z;
            cout << endl;
        }
        if (b >= a && b >= c){
            cout << 2 << " " << b;
            for(auto z : ans2)
                cout << " " << z;
            cout << endl;
        }
        if (c >= a && c >= b){
            cout << 3 << " " << c;
            for(auto z : ans3)
                cout << " " << z;
            cout << endl;
        }
        
    }

    return 0;
}