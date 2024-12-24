#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int t, n, a, x, y, m;

    cin >> t;

    while(t--) {
        cin >> n;

        n *= 2;

        x = 0;
        y = 0;

        while(n--) {
            cin >> a;

            if(a == 0) {
                x++;
            }else {
                y++;
            }
        }

        m = 1;
        if(x % 2 == 0) {
            m = 0;
        }

        cout << m << " " << min(x, y) << endl;
    }
    
    return 0;
}