#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    int sum = 0, count = 0;
    for(int i = 0; i < n; i++){
        int c;
        cin >> c;
        if (c != -1){
            sum+=c; count++;
        }
    }
    printf("%.4f", (double)sum/count);
    return 0;
}