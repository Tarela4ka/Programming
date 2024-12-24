#include<iostream>
#include<string>
#include<cmath>
#include<string>
#include<algorithm>
#include<map>
#include<vector>

#include<bits/stdc++.h>

using namespace std;
#define int long long int
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define mk(a,b) make_pair(a,b)
using vi = vector<int>;
using vvi = vector<vi>;
using vc = vector<char>;
using vvc = vector<vc>;
using vs = vector<string>;
using ii = pair<int, int>;
using vii = vector<ii>;

int n, A, B;

int defZone(int t, int cZone){
    if (A==B){
        if(cZone == 0 || cZone == -1){
            if (t <= A) return 0;
            else return 1;
        }
        if (cZone == 1){
            if (t >= A) return 1;
            else return 0;
        }
    }
    if (t > B) return 2;
    if (t < A) return 0;
    if (t > A && t < B) return 1;
    if (cZone == 2){
        if (t == B) return 2;
        else if (t == A) return 1;
    }else if (abs(cZone) == 1){
        return 1;
    }else if (cZone == 0){
        if (t == A) return 0;
        else if (t == B) return 1;
    }
    return -1;
}

signed main(){
    ios::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);
   // freopen("input.txt", "r", stdin);
   // freopen("output.txt", "w", stdout);

    cin >> n >> A >> B;
    int t; cin >> t;
    int Zone = defZone(t, -1); 
    int ans = 0;
    for(int i = 1; i < n; i++){
        cin >> t;
        int nZone = defZone(t, Zone);
        // cout << nZone << " " << Zone << endl;
        ans += abs(Zone-nZone);
        Zone = nZone;
    }
    cout << ans;
    return 0;
}