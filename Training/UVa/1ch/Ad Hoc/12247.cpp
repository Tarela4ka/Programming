#include<iostream>
#include<cmath>
#include<algorithm>
#include<string>
#include<vector>
#include<set>

using namespace std;

bool win(int winned, set<int> used, vector<int>& a, vector<int>& b){
    bool f = true;
    if (winned >= 2) return true;
    if (used.size() == 6 && winned < 2) return false;  
    // cout << winned << " " << endl;
    // for(auto c : used){
    //     cout << c << " ";
    // } cout << endl << endl;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if (used.find(i) == used.end() && used.find(j+3) == used.end()){
                if (a[i] < b[j]) winned++;
                used.insert(i); used.insert(j+3);
                f = min(f, win(winned, used, a, b));
                // cout << f << endl;
                used.erase(i); used.erase(j+3);
                if (a[i] < b[j]) winned--;
            }
        }
    }
    return f;
}

int main(){
    vector<int> p1(3), p2(3);
    for(; true;){
        cin >> p1[0] >> p1[1] >> p1[2] >> p2[0] >> p2[1];
        if (p1[0] == 0) break;
        bool f = true;
        for(int c = 1; c <= 52; c++){
            p2[2] = c;
            if (c == p1[0] || c == p1[1] || c == p1[2] || c == p2[0] || c == p2[1]) continue;
            if (win(0, {}, p1, p2)){
                cout << c << "\n";
                f = false;
                break;
            }
        }
        if (f) cout << -1 << "\n";
    }
}