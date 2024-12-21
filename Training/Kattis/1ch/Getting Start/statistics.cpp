#include<iostream>
#include<cmath>

using namespace std;

int main(){
    int n; 
    for(int caseN = 1; cin >> n; caseN++){
        int minE = 1e9, maxE = -1e9;
        for(int i = 0; i < n; i++){
            int c;
            cin >> c;
            minE = min(minE, c); maxE = max(maxE, c);
        }
        printf("Case %d: %d %d %d\n", caseN, minE, maxE, maxE-minE);   
    }
    return 0;
}