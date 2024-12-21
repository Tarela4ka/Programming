#include<bits/stdc++.h>

using namespace std;
#define int long long int
using vi = vector<int>;
using vvi = vector<vi>;
using vc = vector<char>;
using vvc = vector<vc>;
#define all(a) a.begin(), a.end()

int n = 4, m = 4;

void turn(vvi& a){
    vvi r(4, vi(4));
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            r[j][i] = a[i][n-j-1];
    a = r;
}

void swapZeros(vvi& field){
    for(int i = 0; i < n; i++){
        for(int j = 1; j < m; j++){
            int k = j;
            if (field[i][k-1] == 0) {
                while(field[i][k-1] == 0){
                    swap(field[i][k-1], field[i][k]);
                    k--;
                }
            }
        }
    }
}

void split(vvi& field){
    for(int i = 0; i < n; i++){
        for(int j = 1; j < m; j++){
            if (field[i][j] == field[i][j-1]){
                field[i][j-1] *= 2;
                field[i][j] = 0;
            }
        }
    }
}

signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    vvi field(n, vi(m));
    for(auto& c : field) for(auto& v : c) cin >> v;

    int dir; cin >> dir;

    for(int i = 0; i < dir; i++) turn(field);
    // for(auto& c : field){ for(auto& v : c) cout << v << " "; cout << endl;}
    swapZeros(field);
    split(field);
    swapZeros(field);
    for(int i = 0; i < 4-dir; i++) turn(field);
    
    for(auto& c : field){ for(auto& v : c) cout << v << " "; cout << endl;}

    return 0;
}