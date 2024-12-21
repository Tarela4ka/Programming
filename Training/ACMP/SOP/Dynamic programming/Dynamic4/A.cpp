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
#define lll __int128
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
    int num[3003] = {};
    int len = 0;
    int sign = 0;
};
bigInt toBigInt(string s){
    bigInt res;
    int i = 0;
    if (s[0] == '-'){
        res.sign = 1;
        i = 1;
    }
    while(i < s.length()){
        res.num[i] = s[s.length()-i-1] - '0';
        i++;
    }
    res.len = i;
    res.len = max(res.len, 1LL);
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
    string res = "";
    if (x.sign) res += '-';
    rf(i, x.len-1, 0) res+=(x.num[i]+'0');
    cout << res;
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
  
void shift1(bigInt& a){
    int i = 0;
    for(i = 0; i < a.len; i++){
        a.num[i+1] += a.num[i]/10;
        a.num[i] %= 10;
    } 
    while(!a.num[a.len-1]) a.len--;
}
  
void shift2(bigInt& a){
    fr(i, 0, a.len-2){
        if (a.num[i] < 0){
            a.num[i]+=10;
            a.num[i+1]--;
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
    a.len = max(a.len, b.len);
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
    res += s[s.length()-1];
    if (s.length() >= 2){
        fr(i, 0, s.length()-2){
            res += s[i];
        }
    }
    s = res;
}
  
bool nice(string s){
    if (s[0] == '0'){
        return 0;
    }
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
 
    int n, a, b;
    cin >> n >> a >> b;
    int k = max(a,b);
    v<v<int>> dp(n+1, v<int>(k+1, 0));
    fr(i, 0, k) dp[0][i] = 1;
    fr(i, 0, n) dp[i][0] = 1;
    fr(i, 1, n){
        fr(j, 1, k){
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }
    printBigInt(multBigInt(toBigInt(dp[n][a]), toBigInt(dp[n][b])));
 
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
// ⠀⠀⠀⠀⠀⠀⠀⠉⣹⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⢻⠀⠀⠀⠀⠀⠀
// ⠀⠀⠀⠀⠀⠀⠀⠀⡿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⡆ Made by @Tarela4ka