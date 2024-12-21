#include<bits/stdc++.h>

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
    int num[1000] = {};
    int len = 0;
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

bool bigger(bigInt a, bigInt b){
    rf(i, max(a.len, b.len)-1, 0){
        if (a.num[i] > b.num[i]) return true;
        if (a.num[i] < b.num[i]) return false;
    }
    return false;
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
    while(!a.num[a.len-1]) a.len--;
}

bigInt sumBigInt(bigInt a, bigInt b){
    fr(i, 0, max(a.len, b.len)-1)
        a.num[i] += b.num[i];

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
    if (bigger(a, b)){
        fr(i, 0, a.len-1){
            a.num[i] -= b.num[i];
        }
    }
    shift2(a);
    return a;
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

    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    bigInt a = toBigInt(s1);
    bigInt b = toBigInt(s2);
    bigInt c = toBigInt(s3);
    if (bigger(c, b) && bigger(c, a)) printBigInt(c);
    else if (bigger(b, a)) printBigInt(b);
    else printBigInt(a);

    #ifdef DEBUG
    t2=clock();
    float diff ((float)t2-(float)t1);
    cout << '\n' << diff << "ms";
    #endif
    return 0;
}