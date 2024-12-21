#include<bits/stdc++.h>

using namespace std;
#define int long long int
using vi = vector<int>;
using vvi = vector<vi>;
using vc = vector<char>;
using vvc = vector<vc>;
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()

bool cmp(string a, string b){
    for(int i = 0; i < min(a.size(), b.size()); i++){
        if (a[i] == b[i]) continue;
        if (tolower(a[i]) > tolower(b[i])){
            return false;
        }else if (tolower(a[i]) < tolower(b[i])){
            return true;
        }
    }
    for(int i = 0; i < min(a.size(), b.size()); i++){
        if (tolower(a[i] == tolower(b[i]))){
            if (a[i] > b[i]) return false;
            else if (b[i] > a[i]) return true;
        }
    }
    return true;
}

signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    while(true){
        int n,m;
        cin >> n >> m;
        if (n == 0 && m == 0) return 0;
        vector<string> a(m, "");
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                char c;
                cin >> c;
                a[j]+=c;
            }
        }
        sort(all(a), cmp);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cout << a[j][i];
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}