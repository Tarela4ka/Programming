#include<bits/stdc++.h>

using namespace std;
#define int long long int

signed main(){
    int n, sum = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        int numb = stoi(s), tnumb = 0;
        int ns = 2;
        for(auto c : s) if (ns <= c-'0') ns = c-'0'+1;
        int c = 0;
        do{
            tnumb += (numb%10)*pow(ns, c);
            numb /= 10;
            c++;
        } while(numb > 0);
        sum += tnumb;
    }
    cout << sum;
    return 0;
}