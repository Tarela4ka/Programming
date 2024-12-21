#include<bits/stdc++.h>

using namespace std;
#define int long long int
#define fr(i, a, b) for (int i = (a); i <= (b); ++i)
#define rf(i, a, b) for (int i = (a); i >= (b); --i)
#define fe(x, y) for (auto& x : y)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define mk(a,b) make_pair(a,b)
using ii = pair<int, int>;
template <typename T>
using v = vector<T>;

int ans = 0;

int mod(int x, int p){
    if (x > p) 
        ans++;
    if (x>=0) 
        return x%p;
    else {
        ans++;
        return (p+(x%p));
    }
}

signed main(){
    ios::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int dir = -1, x = 1, pos = 1;
    for(int i = 0; i < 3000; i++){
        dir = -dir;
        pos = mod(pos + (dir*x), 20);
        cout << pos << " " << ans << endl;
        x++;
        if (x == 20) x = 1;
    }
    cout << ans;
    return 0;
}