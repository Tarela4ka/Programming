#include<bits/stdc++.h>

using namespace std;
#define int long long int
#define all(a) a.begin(), a.end()

signed main(){
    int t; cin >> t;
    for(;t--;){
        int n; cin >> n;
        vector<int> a(n);
        for(auto& c : a) cin >> c;
        sort(all(a));
        int ans = 1e9;
        for(int i = 0; i < n; i++){
            int curans = n-i-1;
            int l = 0, r = i, mid = 0;
            while(l <= r){
                mid = (l+r)/2;
                if (a[mid]+a[mid+1] <= a[i]){
                    l = mid+1;
                }else{
                    r = mid-1;
                }
            }
            if (a[mid]+a[mid+1] <= a[i]) mid++;
            // cout << mid << " ";
            curans += mid;
            ans = min(ans, curans);
        }
        cout << endl;
        cout << ans << endl;
    }
    return 0;
}
