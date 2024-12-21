#include<bits/stdc++.h>

using namespace std;

int main(){
    vector<int> n(3);
    cin >> n[0] >> n[1] >> n[2];
    sort(n.begin(), n.end());
    if (n[0] == n[1]) {
        cout << n[0] << endl;
    }
    int d = min(n[1]-n[0], n[2]-n[1]);
    int a1 = n[0], a2 = a1+d, a3 = a1+2*d, a4 = a1+3*d;
    if (a2 != n[1] && a2 != n[2]) {
        cout << a2;
        return 0;
    }
    if (a3 != n[1] && a3 != n[2]){
        cout << a3;
        return 0;
    }
    if (a4 != n[1] && a4 != n[2]) {
        cout << a4;
        return 0;
    }
    return 0;
}