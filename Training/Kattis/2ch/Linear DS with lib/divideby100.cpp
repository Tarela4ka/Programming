#include<bits/stdc++.h>

using namespace std;
#define all(a) a.begin(), a.end()

signed main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    string s1,s2;
    cin >> s1 >> s2;
    int n1 = s1.length(), n2 = s2.length();
    if (n1 < n2) {
        reverse(all(s1));
        for(int i = 0; i < n2-n1; i++) s1+='0';
        reverse(all(s1));
        n1 = s1.length();
    }
    string preans = "";
    for(int i = 0; i < n1; i++){
        if (i == n1-n2+1) preans+='.';
        preans+=s1[i];
    }
    reverse(all(preans));
    int k = 0;
    while(true){
        if (preans[k] == '0') k++;
        else if (preans[k] == '.'){
            k++;
            break;
        } else break;
    }
    // cout << preans << " " << k << endl;
    string ans = preans.substr(k, n1+1);
    reverse(all(ans));
    cout << ans;
    return 0;
}