#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    for(int cn = 1; cin >> n; cn++){
        if (!n)break;
        int sum = 0;
        for(int i = 0; i < n; i++){
            int c;
            cin >> c;
            if (c != 0) sum++;
            else sum--;
        }
        printf("Case %d: %d\n", cn, sum);
    }
    return 0;
}