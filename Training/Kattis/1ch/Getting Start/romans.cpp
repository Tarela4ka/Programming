#include<iostream>
#include<cmath>

using namespace std;

int main(){
    double n;
    cin >> n;
    cout << int(round(n / 4854 * 5280 * 1000));
    return 0;
}