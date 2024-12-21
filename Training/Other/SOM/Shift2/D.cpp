#include<bits/stdc++.h>

using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using vc = vector<char>;
using vvc = vector<vc>;
using vs = vector<string>;
#define int long long int
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()

const int inf = 1e9 + 10; 
int n, m; 
vi a;

// int bs(int x){
//     int l = 0, r = n+1;
//     int g = 0;
//     while(l <= r){
//         int mid = (l+r)/2;
//         if (a[mid] < x){
//             l = mid+1;
//         }else if (a[mid] > x){
//             r = mid-1;
//         }else{
//             if (l == r){
//                 g = mid;
//                 break;
//             }
//             if (a[r] == x) return r;
//             if (a[l] == x) return l;
//             l = mid;
//         }
//         g = mid;
//     }
//     return g;
// }

signed main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    cin >> n;
    a.resize(n);
    for(auto& c : a) cin >> c;
    sort(all(a)); 
    cin >> m; 

    for(int i = 0; i < m; i++){
        int minA, maxB, g1, g2;
        cin >> minA >> maxB;

        int l = 0, r = n, x = minA;
        while(l <= r){
            int mid = (l+r)/2;
            if (a[mid] >= x) r = mid;
            else l = mid;
            if (l == r) {g1 = mid; break;};
            if (l == mid) l = mid+1;
        }
        l = 0, r = n, x = maxB;
        while(l <= r){
            int mid = (l+r)/2;
            if (a[mid] <= x) l = mid;
            else r = mid;
            if (l == r) {g2 = mid; break;};
            if (l == mid) l = mid+1;
        }
        // cout << g1 << " " << g2 << endl;
        cout << g2 - g1 << endl;
    }
    return 0;
}
