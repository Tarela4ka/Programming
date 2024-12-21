#include<iostream>
#include<vector>
#include<cmath>
#include<queue>

using namespace std;

#define int long long int
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
using vi = vector<int>;
using vvi = vector<vi>;
using vc = vector<char>;
using vvc = vector<vc>;
using vs = vector<string>;

int n, A,B,C,X,Y;
vi a;

void radixSort(){
    int l = 0;
    for(;C;C/=10)l++;
    vector<queue<int>> q(10);
    int p = 1; 
    for(int i = 0; i <= l; i++){
        for(int j = 0; j < n; j++){
            int d = (a[j]/p)%10;
            q[d].push(a[j]);
        }
        vi next;
        for (int j = 0; j < 10; j++){
            while(!q[j].empty()){
                next.push_back(q[j].front());
                q[j].pop();
            }
        }
        a = next;
        p*=10;
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int T; cin >> T;    
    while(T--){
        cin >> n;
        cin >> A >> B >> C;
        cin >> X >> Y;
        a.resize(n);
        a[0] = A;
        for(int i = 1; i < n; i++) {
            int x = (a[i-1]*B + A);
            a[i] = x-C*(x/C);
        }
        
        radixSort();
        int V = 0;
        for(int i = 0; i < n; i++) {
            int x = (V*X+a[i]);
            V = x-Y*(x/Y);
        }
        cout << V << "\n";
    }
}