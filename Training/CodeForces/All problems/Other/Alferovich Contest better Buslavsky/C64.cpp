#include<bits/stdc++.h>

using namespace std;
#define int long long int
#define lll __int128_t
#define fr(i, a, b) for (int i = (a); i <= (b); ++i)
#define rf(i, a, b) for (int i = (a); i >= (b); --i)
#define fe(x, y) for (auto& x : y)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define mk(a,b) make_pair(a,b)
using ii = pair<int, int>;
using ic = pair<int, char>;
template <typename T>
using v = vector<T>;
using vi = v<int>;
using vvi = v<vi>;

const int INF = 1e18+10;

int maxn, maxm;

int sumV(int m){
    int a1 = 2*((m-1)*maxn+maxm*(maxn*maxn-maxn)/2);
    return (a1-maxn*(m-2))*(m-1)/2;
}
int sumH(int n){
    n--; 
    return ((maxm*maxm+maxm)/2*n+maxm*maxm*(n*n-n)/2);
}

signed main(){
    ios::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);
    #ifdef DEBUG
    clock_t t1,t2;
    t1=clock();
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int t; cin >> t;
    while(t--){
        int n, m; cin >> maxn >> maxm;
        n = maxn; m = maxm;
        int maxH = (m*(n*n+n)-n*(m-1))/2*m;
        int maxV = (m*m+m + m*m*(n-1))/2*n;
        int l = 1, r = n+1;
        int ansH = INF, i1, i2;
        while(r-l > 100){
            int mid = (l+r)/2;
            int res = sumH(mid);
            if (maxH - 2*res < 0){
                r = mid;
            }else{
                l = mid;
            }
            if (ansH > abs(maxH - 2*res)){
                ansH = abs(maxH - 2*res);
                i1 = mid;
            }
        }
        fr(i, l, r){
            int res = sumH(i);
            if (ansH > abs(maxH - 2*res)){
                ansH = abs(maxH - 2*res);
                i1 = i;
            }
        }
        l = 1, r = m+1;
        int ansV = INF;
        while(r-l > 100){
            int mid = (l+r)/2;
            int res = sumV(mid);
            if (maxV - 2*res < 0){
                r = mid;
            }else{
                l = mid;
            }
            if (ansV > abs(maxV - 2*res)){
                ansV = abs(maxV - 2*res);
                i2 = mid;
            }
        }
        fr(i, l, r){
            int res = sumV(i);
            if (ansV > abs(maxV - 2*res)){
                ansV = abs(maxV - 2*res);
                i2 = i;
            }
        }
        // cout << ansV << " " << ansH;
        if (ansV < ansH){
            cout << "V " << i2 << "\n";
        }else{
            cout << "H " << i1 << "\n";
        }
    }


    #ifdef DEBUG
    t2=clock();
    float diff ((float)t2-(float)t1);
    cout << '\n' << diff << "ms\n";
    #endif
}