#include<iostream>
#include<string>
#include<map>
#include<vector>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n; cin >> n;
        vector<vector<int>> field(n, vector<int>(n));
        for(auto& v : field)
            for(auto& c : v) cin >> c;
        int ans = 0;
        for(int i = 0; i < n; i++){
            int minP = 0;
            for(int j = 0; j < n-i; j++)
                minP = min(minP, field[i+j][j]);
            if (minP < 0){
                ans += abs(minP);
            }
        }
        for(int i = 1; i < n; i++){
            int minP = 0;
            for(int j = 0; j < n-i; j++)
                minP = min(minP, field[j][i+j]);
            if (minP < 0){
                ans += abs(minP);
            }
        }
        cout << ans << endl;
    }
    return 0;
}