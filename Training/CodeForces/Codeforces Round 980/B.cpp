#include<bits/stdc++.h>

using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n,k, ans = 0;
        cin >> n >> k;
        vector<int> a(n);
        for(auto& c : a) cin >> c;
        sort(a.begin(), a.end());
        int minN = a[0], minC = 0, pminN = 0;
        for(int i = 0; i < a.size(); i++){
            if (minN == a[i]) minC++;
            else {
                if (k >= (minN-pminN)*n){
                    ans += (minN-pminN)*n;
                    k -= (minN-pminN)*n;
                    if (k > 0) {
                        pminN++;
                        k += minC;
                    }
                }else{
                    ans += k;
                    k -= k;
                    break;
                }
                pminN = minN;
                n-=minC;
                minC = 1;
                minN = a[i];
            }
        }
        ans += k;
        cout << ans << endl;
    }
    return 0;
}