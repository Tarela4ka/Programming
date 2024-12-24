#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<string>
#include<set>
#include<map>

using namespace std;
#define int long long int
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
using vi = vector<int>;
using vvi = vector<vi>;
using vs = vector<string>;
using ii = pair<int, int>;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while(t--){
        string s1, s2;
        cin >> s1 >> s2;
        sort(all(s2));
        int n1 = s1.length(), n2 = s2.length();
        if ((double) n1/n2 != n1/n2) {cout << "No\n"; continue;}
        bool f = true;
        for(int i = 0; i < n1/n2; i++){
            sort(s1.begin()+i*n2, s1.begin()+(i+1)*n2);
            for(int j = i*n2; j < (i+1)*n2; j++){
                if (s1[j] != s2[j%n2]) {
                    f = false;
                    break;
                }
            } 
            if (!f) break;
        }
        if (f) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}
