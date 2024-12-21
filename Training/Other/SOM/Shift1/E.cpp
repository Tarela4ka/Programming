#include<bits/stdc++.h>

using namespace std;

int N = 1e6+2;
int main(){
    string s;
    getline(cin, s);
    vector<int> vis(N, 1);
    vis[0] = 0; vis[1] = 0;
    for(int i = 2; i < N; i++)
        if (vis[i])
            for(int j = i+i; j < N; j+=i)
                vis[j] = 0;

    int z = 0,p = 0;
    for(int i = 0; i < s.size(); i+=2){
        int c = 1;
        if (vis[i/2+1]) c = 2;
        if (s[i] == '0') p += c;
        else z += c;
    }
    cout << (z - p);
    return 0;
}