#include<bits/stdc++.h>

using namespace std;
// #define int long long int
#define fr(i, a, b) for (int i = (a); i <= (b); ++i)
#define rf(i, a, b) for (int i = (a); i >= (b); --i)
#define fe(x, y) for (auto& x : y)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define mk(a,b) make_pair(a,b)
using ii = pair<int, int>;
template <typename T>
using v = vector<T>;

bool f1(int A, int B, int C) {return A && B || !A && C;}
bool f2(int A, int B, int C) {return A && C || !B && C;}
bool f3(int A, int B, int C) {return C || A && B;}
bool f4(int A, int B, int C) {return C || !A || !B;}
bool f5(int A, int B, int C) {return C || !(B || !A);}
bool f6(int A, int B, int C) {return !(B || !C) || A;}
bool f7(int A, int B, int C) {return B || !(C || !A);}
bool f8(int A, int B, int C) {return (A || B) && (B || C);}

int sim(bool func1(int a, int b, int c), bool func2(int a, int b, int c)){
    int ans = 0;
    int t = 0;
    for(int A = 0; A <= 1; A++){
        for(int B = 0; B <= 1; B++){
            for(int C = 0; C <= 1; C++){
                if (func1(A, B, C) == func2(A, B, C)){
                    ans = ans || (1 << t);
                }
                t++;
            }
        }
    }
    return ans;
}

signed main(){
    ios::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    auto funcs = vector{f1, f2, f3, f4, f5, f6, f7, f8};
    // cout << sim(funcs[0], funcs[1]);

    map<int, int> results;
    int maxR = 0;
    for(int i = 0; i < 1 << 8; i++){
        int bitmask = i;

        int simil = (1<<8)-1;
        int k = 0;
        for(int i = 0; i < 8; i++){
            if (bitmask & (1 << i))k++;
            for(int j = i+1; j < 8; j++){
                if ((bitmask & (1 << i)) && (bitmask & (1<<j))){
                    int bm = sim(funcs[i], funcs[j]);
                    simil = (simil & bm);
                }
            }
        }
        if (k < 2)continue;

        int res = 0;
        while(simil){
            if (simil & 1) {
                res++;
            }
            simil >>= 1;
        }
        // cout << endl;
        results[i] = res;
        maxR = max(maxR, res);
    }
    fe(p, results){
        if (p.second == maxR){
            int bm = p.first;
            for(int i = 0; i < 8; i++){
                cout << (bm & 1); 
                bm >>= 1;
            }
            cout << ": ";
            cout << p.second << endl;
        }
    }
    return 0;
}