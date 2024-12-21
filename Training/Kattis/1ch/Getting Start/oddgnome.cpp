#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<map>
#include<vector>

using namespace std;
using ll = long long;

int main(){
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        vector<int> g(n);
        for(auto& c : g) cin >> c;
        int ind;
        int m1 = *min_element(g.begin(), g.end());
        int m2 = *max_element(g.begin(), g.end());
        for(int i = 0; i < n; i++)
            if (i!=0 && i != n-1 && (g[i] == m1 || g[i] == m2))
                ind = i+1;
        cout << ind << '\n';
    }
    return 0;
}