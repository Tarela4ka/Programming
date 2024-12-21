#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define fr(i, a, b) for(int i = (a); i <= (b); i++)
#define rf(i, a, b) for(int i = (a); i >= (b); i--)
#define fe(c, a) for(auto& c : a)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
template <typename T>
using v = vector<T>;
using ii = pair<int, int>;

int n, p;

int getDiagVal(int y, int x){
    if (x == y){
        bool f = (x<=p);
        return (2*(p-x)+f)*(2*(p-x)+f)+!f;
    }
    if (x+y == n-1){
        int m;
        if (x <= p) m = 2*(p-x)+1;
        else m = 2*(p-y);
        return m*m-m+1;
    }
    return 0;
}

void getDiag(int tr, int sp, int& y, int& x){
    if (tr == 3){
        y = p+sp;
        x = p-sp;
    }else if (tr == 0){
        y = p-sp;
        x = p+sp;
    }else if (tr == 1){
        y = p+sp;
        x = p+sp;
    }else if (tr == 2){
        y = p-sp;
        x = p-sp;
    }
}

int getVal(int y, int x){
    if (getDiagVal(y, x) != 0){
        return getDiagVal(y, x);
    }
    int tr = (x>n-y-1)+2*(y>x);
    int sp = max(abs(p-x), abs(p-y));
    int dy, dx; getDiag(tr, sp, dy, dx);
    if (tr == 3 || tr == 0)
        return (getDiagVal(dy, dx) - abs(dx-x));
    else
        return (getDiagVal(dy, dx) - abs(dy-y));
    
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> n;
    p = (n/2);
    int x,y; cin >> y >> x;
    y--; x--;
    cout << getVal(y, x);
    return 0;
}