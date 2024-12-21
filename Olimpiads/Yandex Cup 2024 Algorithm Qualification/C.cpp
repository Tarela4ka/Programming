#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int max_dance_width(const string& S) {
    int pos = 0, ans1, ans2;
    int min_pos = 0;
    int max_pos = 0;
    
    for (char ch : S) {
        if (ch == 'R') {
            pos += 1;
        } else if (ch == 'L') {
            pos -= 1;
        } else if (ch == '?') {
            pos += 1;
        }
        min_pos = min(min_pos, pos);
        max_pos = max(max_pos, pos);
    }
    ans1 = max_pos - min_pos;
    pos = 0; min_pos = 0; max_pos = 0;
    for (char ch : S) {
        if (ch == 'R') {
            pos += 1;
        } else if (ch == 'L') {
            pos -= 1;
        } else if (ch == '?') {
            pos -= 1;
        }
        min_pos = min(min_pos, pos);
        max_pos = max(max_pos, pos);
    }
    ans2 = max_pos - min_pos;
    return max(ans1, ans2);
}

int main() {
    string S;
    cin >> S;
    cout << max_dance_width(S) << endl;
    return 0;
}