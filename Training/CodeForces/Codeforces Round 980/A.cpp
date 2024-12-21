#include<bits/stdc++.h>

using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int a,b;
        cin >> a >> b;
        if (a >= b){
            cout << a << endl;
            continue;
        }
        cout << max(a-(b*2-a*2)/2, 0) << endl;
    }
    return 0;
}