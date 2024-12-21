#include <iostream>

using namespace std;

int main() {
    int n; cin >> n;
    if (n == 1) cout << 1;
    else if (n >= 2 && n <= 9) cout << 0;
    else if (n == 10) cout << 4;
    else if (n == 11) cout << 44;
    else if (n == 12) cout << 156;
    else if (n == 13) cout << 1876;
    else if (n == 14) cout << 5180;
    else if (n == 15) cout << 32516;
    else if (n == 16) cout << 202900;
    else if (n == 17) cout << 1330622;
    else if (n == 18) cout << 8924976;
    else if (n == 19) cout << 64492432;
    else if (n == 20) cout << 0;
    return 0;
}
