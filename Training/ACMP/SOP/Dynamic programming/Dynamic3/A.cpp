#include<iostream>
#include<vector>
#include<cstdio>
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

int mem[1003];

int p(int x){
    if (mem[x]) return mem[x];
    mem[x] = p(x-2) + p(x/2);
    return mem[x];
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int x; cin >> x;
    mem[1] = 1;
    mem[2] = mem[3] = 2;
    cout << p(x);
    return 0;
}