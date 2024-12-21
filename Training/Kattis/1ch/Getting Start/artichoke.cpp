#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<map>
#include<vector>

using namespace std;
using ll = long long;

int main(){
    int p,a,b,c,d,n;
    cin >> p >> a >> b >> c >> d >> n;
    double ans = 0, maxE = 0;
    for(int i = 1; i <= n; i++){
        double num = p*(sin(a*i+b) + cos(c*i + d) + 2);
        ans = max(maxE - num, ans);
        maxE = max(maxE, num);
    }
    printf("%.8lf\n", ans);
    return 0;
}             
