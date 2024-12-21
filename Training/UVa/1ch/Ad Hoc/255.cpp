#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<set>

using namespace std;
using ii = pair<int, int>;
#define mp(a,b) make_pair(a,b);
#define all(a) a.begin(), a.end();

int main(){
    int ks, qs, qf, t = 0;
    while(cin >> ks >> qs >> qf){
        t++;
        ii k =  mp(ks/8, ks%8); 
        ii q1 = mp(qs/8, qs%8);
        ii q2 = mp(qf/8, qf%8);
        // cout << t << ": " << ks << " " << qs << " " << qf << ": ";
        if (ks == qs){
            cout << "Illegal state\n"; continue;
        }
        set<ii> queen, king, nam;
        for(int i = 1; q1.first+i < 8; i++){ 
            if (k.first == q1.first+i && k.second == q1.second) {
                nam.insert({k.first-1, k.second});
                break;
            }
            queen.insert({q1.first+i, q1.second});
        }
        for(int i = 1; q1.first-i >= 0; i++){
            if (k.first == q1.first-i && k.second == q1.second) {
                nam.insert({k.first+1, k.second});
                break;
            }
            queen.insert({q1.first-i, q1.second});
        }
        for(int i = 1; q1.second-i >= 0; i++){
            if (k.first == q1.first && k.second == q1.second-i) {
                nam.insert({k.first, k.second+1});
                break;
            }
            queen.insert({q1.first, q1.second-i});
        }
        for(int i = 1; q1.second+i < 8; i++){
            if (k.first == q1.first && k.second == q1.second+i) {
                nam.insert({k.first, k.second-1});
                break;
            }
            queen.insert({q1.first, q1.second+i});
        }
        if (k.first > 0) king.insert({k.first-1, k.second});
        if (k.second > 0) king.insert({k.first, k.second-1});
        if (k.first < 7) king.insert({k.first+1, k.second});
        if (k.second < 7) king.insert({k.first, k.second+1});
        if (queen.find(q2) == queen.end()){
            cout << "Illegal move\n";
            continue;
        }
        if (!(king.find(q2) == king.end())){
            cout << "Move not allowed\n";
            continue;
        }
        set<ii> queen2;
        for(int i = 1; q2.first+i < 8; i++){ 
            if (k.first == q2.first+i && k.second == q2.second) break;
            queen2.insert({q2.first+i, q2.second});
        }
        for(int i = 1; q2.first-i >= 0; i++){
            if (k.first == q2.first-i && k.second == q2.second)break;
            queen2.insert({q2.first-i, q2.second});
        }
        for(int i = 1; q2.second-i >= 0; i++){
            if (k.first == q2.first && k.second == q2.second-i)break;
            queen2.insert({q2.first, q2.second-i});
        }
        for(int i = 1; q2.second+i < 8; i++){
            if (k.first == q2.first && k.second == q2.second+i) break;
            queen2.insert({q2.first, q2.second+i});
        }
        for(auto [y, x] : queen2){
            king.erase({y,x});
        }
        if (king.size() == 0){
            cout << "Stop\n";
            continue;
        }
        cout << "Continue\n";
    }
    return 0;
}