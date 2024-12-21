#include<iostream>
#include<cmath>

using namespace std;

int main(){
    long long n, c = 2;
    cin >> n;
    for(int i = 1; i <= n; i++){
        c+=c-1;
    }
    cout << c*c;
    return 0;
}