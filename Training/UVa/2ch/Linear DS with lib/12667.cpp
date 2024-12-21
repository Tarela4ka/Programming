#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, t, m;
    cin >> n >> t >> m;
    map<char, pair<int, int>> task;
    map<char, map<int, int>> vis;
    for(int i = 0; i < m; i++){
        int time, team;
        char p; string ver;
        cin >> time >> team >> p >> ver;
        if (ver == "Yes"){
            if (task[p].first <= time && vis[p][team] == 0){
                vis[p][team] = 1;
                task[p].first = time;
                task[p].second = team;
            }
        }     
    }
    for(auto i = 'A'; i < 'A'+n; i++){
        if (task[i] == make_pair(0, 0)){
            cout << i << " - -\n"; 
        }else{
            cout << i << " " << task[i].first << " " << task[i].second << '\n';
        }
    }
}