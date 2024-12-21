#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <stack>

using namespace std;

signed main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int ind = 0, m = 0, sum = 0;
        bool f = false;
        for(int i = 0; i < n; i++){
            int c; cin >> c;
            sum += c;
            if (m < c){
                f = true;
                m = c;
                ind = i+1;
            } else if (m == c) f = false;
        }
        if (!f){
            printf("no winner\n");
        } else {
            if (sum < m*2){
                printf("majority ");
            }else {
                printf("minority ");
            }
            printf("winner %d\n", ind);
        }
    }
}