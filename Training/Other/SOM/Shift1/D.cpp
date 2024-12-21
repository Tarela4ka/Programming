#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
        cout << (i%2 ? n/2+i/2+1 : n/2-i/2+1) << " ";
    return 0;
}