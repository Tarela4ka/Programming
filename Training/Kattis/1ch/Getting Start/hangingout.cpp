#include<bits/stdc++.h>

using namespace std;

int main(){
    int m, n, cur = 0, ans = 0;
    cin >> m >> n;
    for(int i = 0; i < n; i++){
        string s; int c;
        cin >> s >> c;
        if (s == "enter"){
            if (cur + c <= m){
                cur += c;
            }else {
                ans++;
            }
        } else {
            cur -= c;
        }
    }
    cout << ans;
    return 0;
}
