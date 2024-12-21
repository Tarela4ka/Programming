#include<iostream>

using namespace std;

int main(){
    double x,y;
    cin >> x >> y;
    y--;
    if (x == 0) {
        cout << "IMPOSSIBLE";
        return 0;
    }
    if (y == 1) {
        cout << "ALL GOOD";
        return 0;
    }
    printf("%.7f", double(x/y)*-1);
    return 0;
}