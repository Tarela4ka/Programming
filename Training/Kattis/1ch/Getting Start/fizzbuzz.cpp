#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<map>
#include<vector>

using namespace std;
using ll = long long;

int main(){
    int a,b,n;
    cin >> a >> b >> n;
    for(int i = 1; i <= n; i++){
        if (!(i%a)) cout << "Fizz";
        if (!(i%b)) cout << "Buzz";
        if (i%a && i%b) cout << i;
        cout << '\n';
    }
    return 0;
}