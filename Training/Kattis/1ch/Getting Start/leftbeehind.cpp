#include<iostream>
#include<cmath>

using namespace std;

int main(){
    for(; true;){
        int a,b;
        cin >> a >> b;
        if (a == 0 && b == 0) break;
        if (a+b == 13) {
            cout << "Never speak again.\n";
            continue;
        }
        if (a>b) cout << "To the convention.\n";
        if (a<b) cout << "Left beehind.\n";
        if (a==b) cout << "Undecided.\n";
    }
}