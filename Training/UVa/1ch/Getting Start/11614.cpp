#include <iostream>
#include <cmath>

using namespace std;
using ll = long long;

int main(){
    ll t, n;
    scanf("%lld", &t);
    while(t--){
        scanf("%lld", &n);
        printf("%lld\n", int(sqrt(8*n+1)-1)/2);
    }
}