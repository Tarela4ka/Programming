#include<bits/stdc++.h>

using namespace std;

int main(){
    int n, dir;
    cin >> n;
    string s, sp;
    cin >> sp >> s;
    if (sp < s) dir = 1;
    if (sp > s) dir = 2; 
    sp = s;
    for(int i = 0; i < n-2; i++){
        cin >> s;
        if (dir == 2){
            if (sp < s) {
                dir = 0;
                cout << sp << " " << s << endl;
            }
        }
        if (dir == 1){
            if (sp > s) {
                dir = 0;
                cout << sp << " " << s << endl;
            }
        }
        sp = s;
    }
    if (dir == 0) cout << "NEITHER";
    else if (dir == 2) cout << "DECREASING";
    else cout << "INCREASING";
    return 0;
}