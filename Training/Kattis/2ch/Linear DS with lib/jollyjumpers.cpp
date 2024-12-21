#include<bits/stdc++.h>

using namespace std;
// #define int long long int
// #define all(a) a.begin(), a.end()

signed main(){
    int n;  
    while(cin >> n){
        multiset<int> s;
        int c, c1; cin >> c1;
        for(int i = 0; i < n-1; i++){
            cin >> c;
            s.insert(abs(c-c1));
            c1 = c;
        }
        if (n == 1){
            cout << "Jolly\n";
            continue;
        }
        int i = 1;
        bool f = true;
        for(auto a : s){
            // cout << a << " " << i << endl;
            if (a != i){
                f = false;
                break;
            }
            i++;
        }
        if (f){
            cout << "Jolly\n";
        }else{
            cout << "Not jolly\n";
        }
    }
    return 0;
}