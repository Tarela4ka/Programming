#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main(){
    int n;
    for(; true; ){
        cin >> n;
        if (n == 0) break;
        string s;
        getline(cin, s); getline(cin, s);
        string ans = "+x";
        for(int i = 0; i < s.length(); i+=3){
            if (s[i] == 'N') continue;

            if (ans[1] == 'x') {
                ans[1] = s[i+1]; 
                // cout << s[i+1] << " ";
                // cout << ans << '\n';
                if (s[i+1] != 'x'){
                    ans[0] = (ans[0]=='+' ? s[i] : (s[i] == '-' ? '+' : '-'));
                } else {
                    ans[0] = (ans[0] == '-' ? '+' : '-');
                }
            }else if (ans[1] == 'y'){
                if (s[i+1] == 'y'){
                    ans[1] = 'x';
                    if (ans[0] == s[i]) ans[0] = '-';
                    else ans[0] = '+';
                }
            }else if (ans[1] == 'z'){
                if (s[i+1] == 'x') ans[0] = (ans[0] == '-' ? '+' : '-');
                if (s[i+1] == 'z') {
                    ans[1] = 'x';
                    if (ans[0] == s[i]) ans[0] = '-';
                    else ans[0] = '+';
                }
            }
            // cout << ans << '\n';
        }
        cout << ans << '\n';
    }
    return 0;
}