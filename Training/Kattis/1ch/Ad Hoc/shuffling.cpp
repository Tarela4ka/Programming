#include<iostream>
#include<cmath>
#include<algorithm>
#include<string>
#include<vector>
#include<set>
#include<unordered_map>

using namespace std;

int main(){
    int n; cin >> n;
    string s; cin >> s;
    vector<int> a(n), start;
    for(int i = 0; i < n; i++) a[i] = i+1;
    start = a;
    int ans = 0;
    // for(auto c : start){
    //     cout << c << " ";
    // } cout << endl;
    for (;true;){
        vector<int> temp;
        for(int i = 0; i < n/2; i++){
            if (s == "out"){
                temp.push_back(a[i]);
                if (n%2 == 1){
                    temp.push_back(a[i+n/2+1]);
                } else {
                    temp.push_back(a[i+n/2]);
                }
            }else{
                temp.push_back(a[i+n/2]);
                temp.push_back(a[i]);
            }
        }
        if (n%2) {
            if (s == "out") temp.push_back(a[n/2]);
            else temp.push_back(a[n-1]);
        }
        ans++;
        if (temp == start) break;
        a = temp;
    }
    
    cout << ans;
}