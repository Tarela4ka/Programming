#include<bits/stdc++.h>

using namespace std;
#define int long long int
using vi = vector<int>;
using vvi = vector<vi>;
using vc = vector<char>;
using vvc = vector<vc>;
#define all(a) a.begin(), a.end()

signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    vvc field(5, vc(5));
    int count = 0;
    for(auto& c : field) for(auto& v : c){
        cin >> v;
        if (v == 'k') count++;
    }
    if (count != 9){
        cout << "invalid";
        return 0;
    }
    vi dx{1,1,-1,-1,2,2,-2,-2}, dy{2,-2,2,-2,1,-1,1,-1};
    bool f = true;
    for(int y = 0; y < 5; y++){
        for(int x = 0; x < 5; x++){
            if (field[y][x] == '.') continue;
            for(int i = 0; i < dx.size(); i++){
                int ty = y + dy[i], tx = x + dx[i];
                if (ty >= 0 && tx >= 0 && ty < 5 && tx < 5 && field[ty][tx] == 'k') f = false;
            }
        }
    }
    if(f){
        cout << "valid";
    }else{
        cout << "invalid";
    }
    return 0;
}