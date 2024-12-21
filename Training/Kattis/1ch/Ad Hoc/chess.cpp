#include<bits/stdc++.h>

using namespace std;
// #define int long long int

signed main(){
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        char a,b; int x1,x3,y1,y3; 

        cin >> a >> y1 >> b >> y3;

        x1 = a -'A'+1; x3 = b -'A'+1;
        if ((x1+y1)%2 != (x3+y3)%2) 
            cout << "Impossible\n";
        else if(x1 == x3 && y1 == y3)
            printf("0 %c %d\n", b, y3);
        else if(abs(x1 - x3) == abs(y1 - y3))
            printf("1 %c %d %c %d\n", a, y1, b, y3);
        else{
            bool f = true;
            for(int x2 = 1; x2 <= 8 && f; x2++){
                for(int y2 = 1; y2 <= 8 && f; y2++){
                    if (abs(x2-x1) == abs(y2-y1) && abs(x2-x3) == abs(y2-y3)){
                        printf("2 %c %d %c %d %c %d\n", a, y1, 'A'+x2-1, y2, b, y3);
                        f = false;
                    }
                }
            }
        }
    }
    return 0;
}