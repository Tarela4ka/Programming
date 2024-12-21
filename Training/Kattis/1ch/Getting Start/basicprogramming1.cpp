#include<bits/stdc++.h>

using namespace std;

int main(){
    long long t,n; cin >> n >> t;
    vector<long long> a(n);
    for(auto& c : a) cin >> c;
    if (t == 1) cout << 7;
    if (t == 2) {
        if (a[0] > a[1]) cout << "Bigger";
        if (a[0] < a[1]) cout << "Smaller";
        if (a[0] == a[1]) cout << "Equal";
    }
    if (t == 3){
        vector<long long> b;
        for(long long i = 0; i < 3; i++) b.push_back(a[i]);
        sort(b.begin(), b.end());
        cout << b[1];
    }
    if (t == 4){
        long long sum = 0;
        for(auto c : a) sum+=c;
        cout << sum;
    }
    if (t == 5){
        long long sum = 0;
        for(auto c : a) if (!(c % 2)) sum += c;
        cout << sum;
    } 
    if (t == 6) for(auto c : a) cout << char('a'+c%26);
    if (t == 7){
        vector<long long> visited(n, 0);
        long long i = 0;
        visited[0] = 1;
        while(true){
            i = a[i];
            if (visited[i]) {
                cout << "Cyclic";
                break;
            }
            if (i >= n) {
                cout << "Out";
                break;
            }else if (i == n-1){
                cout << "Done";
                break;
            }
            visited[i] = 1;
        }
    }
    return 0;
}