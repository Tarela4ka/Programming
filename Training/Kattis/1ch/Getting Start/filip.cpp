#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<map>
#include<vector>

using namespace std;
using ll = long long;

int main(){
    string s1,s2;
    cin >> s1 >> s2;
    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());
    if (s1 > s2) {
        cout << s1;
    } else {
        cout << s2;
    }
    return 0;
}             
