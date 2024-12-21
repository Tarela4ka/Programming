#include<iostream>
#include<cmath>

using namespace std;

int main(){
    int a,b,c,n;
    cin >> a >> b >> c >> n;
    if (a && b && c && n>=3 && a+b+c>=n) cout << "YES";
    else cout << "NO";
    return 0;
}