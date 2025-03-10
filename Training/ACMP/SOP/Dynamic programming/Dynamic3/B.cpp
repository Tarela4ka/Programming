#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<iomanip>
#include<ctime>
#include<map>
 
using namespace std;
 
#define int long long int
#define fr(i, a, b) for (int i = (a); i <= (b); ++i)
#define rf(i, a, b) for (int i = (a); i >= (b); --i)
#define fe(x, y) for (auto& x : y)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define mk(a,b) make_pair(a,b)
using ii = pair<int, int>;
template <typename T>
using v = vector<T>;
 
const int MOD = 1000000007;
const int INF = 1e9;
 
struct bigInt{
    int num[40] = {};
    int len = 1;
    int sign = 0;
};
bigInt toBigInt(string s){
    bigInt res;
    int i = 0;
    while(i < s.length()){
        res.num[i] = s[s.length()-i-1] - '0';
        i++;
    }
    res.len = i;
    return res;
}
 
bigInt toBigInt(int x){
    bigInt res;
    int i = 0;
    while(x){
        res.num[i] = x%10;
        x/=10;
        i++;
    }
    res.len = i;
    return res;
}
 
void printBigInt(bigInt x){
    rf(i, x.len-1, 0) cout << x.num[i];
}
 
int comp(bigInt a, bigInt b){
    if (a.sign && !b.sign) return 0;
    if (!a.sign && b.sign) return 1;
    rf(i, max(a.len, b.len)-1, 0){
        if (a.sign && b.sign){
            if (a.num[i] > b.num[i]) return 0;
            if (a.num[i] < b.num[i]) return 1;
        }else{
            if (a.num[i] > b.num[i]) return 1;
            if (a.num[i] < b.num[i]) return 0;
        }
    }
    return 2;
}
 
bool comp(string a, string b){
    if (a.length() > b.length()) return 1;
    if (a.length() < b.length()) return 0;
 
    if (a.length() == 0) return 0;
    fr(i, 0, a.length()-1){
        if (a[i] > b[i]) return 1;
        if (a[i] < b[i]) return 0;
    }
    return 0;
}
 
void shift1(bigInt& a){
    int i = 0;
    for(i = 0; i < a.len; i++){
        a.num[i+1] += a.num[i]/10;
        a.num[i] %= 10;
    } 
    while(!a.num[a.len-1] && a.len >= 2) a.len--;
}
  
 
void shift2(bigInt& a){
    if (a.len >= 2)
        fr(i, 1, a.len-2){
            if (a.num[i-1] < 0){
                a.num[i-1]+=10;
                a.num[i]--;
            }
        }
    while(!a.num[a.len-1] && a.len >= 2) a.len--;
}
 
string bigIntToStr(bigInt a){
    string res = "";
    fr(i, 0, a.len-1) {
        do{
            res+=(a.num[i]%10)+'0';
            a.num[i] /= 10;
        }while(a.num[i]);
    }
    reverse(all(res));
    return res;
}
 
bigInt sumBigInt(bigInt a, bigInt b){
    fr(i, 0, max(a.len, b.len)-1)
        a.num[i] += b.num[i];
    a.len = max(a.len, b.len)+1;
    // a = toBigInt(bigIntToStr(a));
    shift1(a);
    return a;
}
 
bigInt multBigInt(bigInt a, bigInt b){
    bigInt res;
    res.len = a.len+b.len+1;
    fr(i, 0, a.len-1){
        fr(j, 0, b.len-1){
            res.num[i+j] += a.num[i]*b.num[j];
        }
    }
    shift1(res);
    return res;
}
 
bigInt subBigInt(bigInt a, bigInt b){
    if (!comp(a, b)){
        swap(a, b);
        a.sign = 1;
    }
    fr(i, 0, a.len-1)
        a.num[i] -= b.num[i];
    shift2(a);
    return a;
}
 
void cyclicShift(string& s){
    string res = "";
    if (s.length() >= 1){
        res += s[s.length()-1];
        if (s.length() >= 2){
            fr(i, 0, s.length()-2){
                res += s[i];
            }
        }
    }
    s = res;
}
 
bool nice(string s){
    if (s.length() == 0) return 0;
    if (s[0] == '0')
        return 0;
    return 1;
}
 
signed main(){
    ios::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);
    #ifdef DEBUG
    clock_t t1,t2;
    t1=clock();
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
     
    // printBigInt(sumBigInt(toBigInt("2"), toBigInt("8")));
 
    int x; cin >> x;
    v<v<bigInt>> dp(10, v<bigInt>(x+1));
    map<int, v<int>> r;
    r[0] = {4, 6};
    r[1] = {6, 8};
    r[2] = {7, 9};
    r[3] = {4, 8};
    r[4] = {3, 9, 0};
    r[5] = {};
    r[6] = {0, 7, 1};
    r[7] = {2, 6};
    r[8] = {1, 3};
    r[9] = {2, 4};
    fr(i, 0, 9) if (i != 8 && i != 0) dp[i][0] = toBigInt(1);
    fr(i, 1, x-1){
        fr(d, 0, 9){
            fe(c, r[d]){
                dp[c][i] = sumBigInt(dp[c][i], dp[d][i-1]);
            }
        }
    }
    bigInt ans = toBigInt(0);
    fr(d, 0, 9){
        ans = sumBigInt(ans, dp[d][x-1]);
        // printBigInt(dp[d][x-1]); cout << " ";
        // printBigInt(ans); cout << endl;
    }
    printBigInt(ans);
 
    #ifdef DEBUG
    t2=clock();
    float diff ((float)t2-(float)t1);
    cout << '\n' << diff << "ms";
    #endif
    return 0;
}
 
// ⠀⢸⠂⠀⠀⠀⠘⣧⠀⠀⣟⠛⠲⢤⡀⠀⠀⣰⠏⠀⠀⠀⠀⠀⢹⡀
// ⠀⡿⠀⠀⠀⠀⠀⠈⢷⡀⢻⡀⠀⠀⠙⢦⣰⠏⠀⠀⠀⠀⠀⠀⢸⠀
// ⠀⡇⠀⠀⠀⠀⠀⠀⢀⣻⠞⠛⠀⠀⠀⠀⠻⠀⠀⠀⠀⠀⠀⠀⢸⠀
// ⠀⡇⠀⠀⠀⠀⠀⠀⠛⠓⠒⠓⠓⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⠀
// ⠀⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣸⠀
// ⠀⢿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣀⣀⣀⣀⠀⠀⢀⡟⠀
// ⠀⠘⣇⠀⠘⣿⠋⢹⠛⣿⡇⠀⠀⠀⠀⣿⣿⡇⠀⢳⠉⠀⣠⡾⠁⠀
// ⣦⣤⣽⣆⢀⡇⠀⢸⡇⣾⡇⠀⠀⠀⠀⣿⣿⡷⠀⢸⡇⠐⠛⠛⣿⠀
// ⠹⣦⠀⠀⠸⡇⠀⠸⣿⡿⠁⢀⡀⠀⠀⠿⠿⠃⠀⢸⠇⠀⢀⡾⠁⠀
// ⠀⠈⡿⢠⢶⣡⡄⠀⠀⠀⠀⠉⠁⠀⠀⠀⠀⠀⣴⣧⠆⠀⢻⡄⠀⠀
// ⠀⢸⠃⠀⠘⠉⠀⠀⠀⠠⣄⡴⠲⠶⠴⠃⠀⠀⠀⠉⡀⠀⠀⢻⡄⠀
// ⠀⠘⠒⠒⠻⢦⣄⡀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣀⣤⠞⠛⠒⠛⠋⠁⠀
// ⠀⠀⠀⠀⠀⠀⠸⣟⠓⠒⠂⠀⠀⠀⠀⠀⠈⢷⡀⠀⠀⠀⠀⠀⠀⠀
// ⠀⠀⠀⠀⠀⠀⠀⠙⣦⠀⠀⠀⠀⠀⠀⠀⠀⠈⢷⠀⠀⠀⠀⠀⠀⠀
// ⠀⠀⠀⠀⠀⠀⠀⣼⣃⡀⠀⠀⠀⠀⠀⠀⠀⠀⠘⣆⠀⠀⠀⠀⠀⠀
// ⠀⠀⠀⠀⠀⠀⠀⠉⣹⠃