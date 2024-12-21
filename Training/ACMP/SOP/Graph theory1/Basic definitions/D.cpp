#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, count = 0;
    cin >> n;

    vector<vector<int>> graph;
    graph.resize(n, vector<int>(n));

    
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> graph[i][j];
        }
    }

    int minp = 2147483647;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if (i != j && j != k && i != k){
                    minp = min(minp, graph[i][j] + graph[j][k] + graph[i][k]);
                }
            }
        }
    }

    cout << minp;
}