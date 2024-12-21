#include<iostream>
#include<cmath>

using namespace std;

int main(){
    int x, n, ans;
    cin >> x >> n;
    ans = x * (n+1);
    for(int i = 0; i < n; i++){
        int m;
        cin >> m;
        ans -= m;
    }
    cout << ans;
    return 0;
}