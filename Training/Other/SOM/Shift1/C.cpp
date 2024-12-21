#include<bits/stdc++.h>

using namespace std;

int main(){
    string s = "", temp;
    char a, b, c;
    cin >> a >> b >> c;
    s += a; s += b; s += c;
    int maxE = -1;
    temp = s;
    do{
        if (s[0] != '0')
            if (((s[2]-'0') % 2 == 0) && maxE < stoi(s))
                maxE = stoi(s);
        next_permutation(s.begin(), s.end());
    }while (s != temp);
    cout << maxE;
    return 0;
}