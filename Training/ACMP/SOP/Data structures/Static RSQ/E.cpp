#include<iostream> 
// #include<string>
#include<vector>
#include<algorithm>
// #include<queue>
// #include<map>
#include<cmath>

using ll = long long;
using namespace std;

int n, m, q;
unsigned int nc, np;
const int t31 = 2147483648;
const int t15 = 65536;

void nextNum(){
    nc = (np*1103515245)%t31+12345;
    np = nc;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> q;
    vector<unsigned int> sums(n+1);
    cin >> np;
    sums[0] = np/t15;
    for(int i = 1; i <= n; i++) {
        nextNum();
        sums[i] = (sums[i-1] + nc/t15) & 2147483647;
    }

    nextNum();
    ll sum = 0;
    for(int i = 0; i < q; i++){
        nc = (np*1103515245 & 2147483647)+12345;
        int n1 = (np/t15 & (n-1)), n2 = (nc/t15 & (n-1));
        int l = min(n1, n2), r = max(n1, n2);
        r++;
        sum += sums[r]-sums[l];
        np = nc;
        nextNum();
    }
    cout << sum % t31;
    return 0;
}