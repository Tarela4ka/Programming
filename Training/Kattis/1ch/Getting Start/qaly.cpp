#include<iostream>
#include<cmath>

using namespace std;

int main(){
    int n;
    cin >> n;
    double ans = 0;
    for(int i = 0; i < n; i++){
        double a,b;
        cin >> a >> b;
        ans += a*b;
    }
    printf("%.3f", ans);
}