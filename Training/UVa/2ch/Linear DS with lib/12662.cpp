#include<bits/stdc++.h>

using namespace std;
// #define int long long int
// #define all(a) a.begin(), a.end()

signed main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int n; cin >> n;
    vector<string> names(n);
    for(auto& c : names) cin >> c;
    int q; cin >> q;
    for(int i = 0; i < q; i++){
        int p; cin >> p; p--;
        if (names[p] != "?") {
            cout << names[p] << endl; 
            continue;
        }
        for(int k = 1; k < n; k++){
            if (p-k >= 0 && p+k < n){
                if (names[p-k] != "?" && names[p+k] != "?"){
                    printf("middle of ");
                    cout << names[p-k] << " and " << names[p+k];
                    break;
                }
            }
            if (p-k >= 0){
                if (names[p-k] != "?"){
                    for(int j = 0; j < k; j++)
                        printf("right of ");
                    cout << names[p-k];
                    break;
                }
            }
            if (p+k < n){
                if (names[p+k] != "?"){
                    for(int j = 0; j < k; j++)
                        printf("left of ");
                    cout << names[p+k];
                    break;
                }
            }
        }
        cout << endl;
    }
    return 0;
}