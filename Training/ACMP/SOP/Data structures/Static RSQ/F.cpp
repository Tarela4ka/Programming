#include<iostream>
#include<vector>
#include<cmath>

using namespace std;
int n,m,q,h;
using vi = vector<int>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;

int main(){
    cin >> h >> n >> m >> q;
    vvvi T(h, vvi(n, vi(m)));
    for(int k = 0; k < h; k++)
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++){
                char c;
                cin >> c;
                T[k][i][j] = c - '0';
            }

    vvvi sums(h, vvi(n, vi(m)));
    // for(int k = 0; k < h; k++){
    //     for(int i = 0; i < n; i++){
    //         for(int j = 0; j < m; j++)
    //             cout << T[k][i][j] << " ";
    //         cout << endl;
    //     }
    //     cout << endl; 
    // }
    sums[0][0][0] = T[0][0][0];
    for(int i = 1; i < n; i++) sums[0][i][0] = T[0][i][0] + sums[0][i-1][0];
    for(int i = 1; i < m; i++) sums[0][0][i] = T[0][0][i] + sums[0][0][i-1];
    for(int i = 1; i < n; i++)
        for(int j = 1; j < m; j++)
            sums[0][i][j] = T[0][i][j] + sums[0][i-1][j] + sums[0][i][j-1] - sums[0][i-1][j-1];

    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < m; j++)
    //         cout << sums[0][i][j] << " ";
    //     cout << endl;
    // }
    // cout << endl;

    for(int k = 1; k < h; k++)
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++){
                sums[k][i][j] = T[k][i][j];
                if (j == 0 && i != 0){
                    sums[k][i][j] += sums[k][i-1][j];
                } else if (i == 0 && j != 0){
                    sums[k][i][j] += sums[k][i][j-1];
                } else if (i != 0 && j != 0){
                    sums[k][i][j] += sums[k][i-1][j] + sums[k][i][j-1] - sums[k][i-1][j-1];
                }
            }

    for(int k = 1; k < h; k++)
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                sums[k][i][j] += sums[k-1][i][j];

    // for(int k = 0; k < h; k++){
    //     for(int i = 0; i < n; i++){
    //         for(int j = 0; j < m; j++)
    //             cout << sums[k][i][j] << " ";
    //         cout << endl;
    //     }
    //     cout << endl;
    // }

    for(;q--;){
        int x1,x2,y1,y2,z1,z2, t;
        cin >> z1 >> y1 >> x1 >> z2 >> y2 >> x2; 
        x1--;y1--;z1--;x2--;y2--;z2--;
        t = max(x1, x2);
        x1 = min(x1, x2); x2 = t;
        t = max(y1, y2);
        y1 = min(y1, y2); y2 = t;
        t = max(z1, z2);
        z1 = min(z1, z2); z2 = t;

        long long sum = sums[z2][y2][x2];
        if (x1-1 >= 0)
            sum -= sums[z2][y2][x1-1];
        if (y1-1 >= 0)
            sum -= sums[z2][y1-1][x2];
        if (x1-1 >= 0 && y1-1 >= 0)
            sum += sums[z2][y1-1][x1-1];

        if (z1-1 >= 0){
            sum -= sums[z1-1][y2][x2];
            if (x1-1 >= 0)
                sum += sums[z1-1][y2][x1-1];
            if (y1-1 >= 0)
                sum += sums[z1-1][y1-1][x2];
            if (x1-1 >= 0 && y1-1 >= 0)
                sum -= sums[z1-1][y1-1][x1-1];
        }
        cout << sum << endl;
    }
}