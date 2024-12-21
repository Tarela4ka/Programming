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

    vector<int> colors(n);
    for (int i = 0; i < n; i++){
        cin >> colors[i];
    }

    for (int i = 0; i < n; i++){
        for (int j = i; j < n; j++){
            if (graph[i][j] == 1 && colors[i] != colors[j]){
                count++;
            }
        }
    }
    cout << count;
}