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

    signed main(){
        ios::sync_with_stdio(false); 
        cin.tie(NULL); cout.tie(NULL);
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        int t; cin >> t; 
        while(t--){
            int n,m;
            cin >> n >> m;
            cout << 19*m + (n+239)*(n+366)/2 << endl;
        }
        return 0;
    }