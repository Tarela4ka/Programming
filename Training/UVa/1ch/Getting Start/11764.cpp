#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    for(int caseN = 1; caseN <= t; caseN++){
        int n, t1 = 0, t2 = 0, h = 0, l = 0;
        cin >> n >> t1;
        for(int i = 0; i < n-1; i++){
            cin >> t2;
            if (t1 > t2) l++;
            if (t1 < t2) h++;
            t1 = t2;
        }
        printf("Case %d: %d %d\n", caseN, h, l);
    }
    return 0;
}