#include<bits/stdc++.h>

using namespace std;

int main(){
    int T; cin >> T;
    for(int t = 0; t < T; t++){
        int a,b,c;
        cin >> a >> b >> c;
        if (a <= 20 && b <= 20 && c <= 20){
            printf("Case %d: good\n", t+1);
        }else{
            printf("Case %d: bad\n", t+1);
        }
    }
    return 0;
}