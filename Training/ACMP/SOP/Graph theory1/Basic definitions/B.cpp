#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> count(n, 0);
    int a, b;

    for (int i = 0; i < m; i++){
        cin >> a >> b;
        count[a-1]++;
        count[b-1]++;
    }
    for (int i = 0; i < n; i++){
        cout << count[i] << " ";
    }
}