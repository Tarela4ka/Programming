#include<bits/stdc++.h>

using namespace std;
// #define int long long int
#define all(a) a.begin(), a.end()

signed main(){
    int n, k; 
    cin >> n >> k;
    int maxP = 0;
    int l = 0,r = 0;
    vector<int> z(n);
    for(auto& c : z) cin >> c;
    sort(all(z));
    for(int i = 0; i < n; i++){
        r = i;
        while(z[r]-z[l] >= 1000)l++;
        maxP = max(r-l, maxP);
    }
    cout << ceil((double)(maxP+1)/k);
    return 0;
}