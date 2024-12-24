// #include<bits/stdc++.h>
#include<iostream>
#include<vector>
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

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n,x,y;
    cin >> n >> y >> x;
    y--; x--;
    int p = (n/2);
    if (x == y){
        if (x <= p){
            cout << (2*(p-x)+1)*(2*(p-x)+1);
        }else{
            cout << (2*(x-p))*(2*(x-p))+1; 
        }
        return 0;
    }
    if (x+y == n-1){
        if (x <= p){
            int m = 2*(p-x)+1;
            cout << m*m-m+1;
        } else{
            int m = 2*(p-y);
            cout << m*m-m+1;
        }
        return 0;
    }
    

    return 0;
}