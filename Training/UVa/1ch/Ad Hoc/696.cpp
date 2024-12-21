#include<iostream>
#include<string>
#include<cmath>
#include<vector>
#include<algorithm>
#include<set>

using namespace std;

int main(){
    while(true){
        int n,m,ans;
        cin >> n >> m;
        if (n == 0 && m == 0) break;
        if (n >= 4 && m >= 4) ans = ceil((double)n*m/2);
        else if (m==0 || n==0) ans = 0;
        else if (n==1 || m == 1) ans = max(n,m);
        else if (n==2 || m == 2 || n == 3 || m == 3) ans = ((max(n,m)/4)*4+2*(min(max(n,m)%4, 2)));
        printf("%d knights may be placed on a %d row %d column board.\n", ans, n, m); 
    }
    return 0;
}