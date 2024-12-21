#include<bits/stdc++.h>

using namespace std;

int main(){
    map<char, int> r;
    int ans = 0, count = 0;
    int pen; char task; string wr;
    while(true){
        cin >> pen; 
        if (pen == -1) break;
        cin >> task >> wr;
        r[task]++;
        if (wr == "right") {
            count++;
            ans += pen + (r[task]-1)*20;
        }
    }
    cout << count << " " << ans << '\n';
    return 0;
}