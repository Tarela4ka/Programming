#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    int count = 0, a;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> a;
            count += (a == 1) ? (1) : (0);
        }
    }
    cout << count / 2;
}