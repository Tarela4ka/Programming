#include<iostream>
#include<cmath>

using namespace std;

int main(){
    long long n,m;
    while(cin >> n >> m){
        cout << abs(n-m) << '\n';
    }
    return 0;
}