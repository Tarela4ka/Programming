#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
using ll = long long;

int main(){
    ll n;
    cin >> n;
    vector<ll> nums(n), evens, odds;
    for(auto& c : nums) {
        cin >> c;
        if (c%2 == 0) evens.push_back(c);
        else odds.push_back(c);
    }
    sort(evens.begin(), evens.end());
    sort(odds.rbegin(), odds.rend());
    for(auto c : evens) cout << c << " ";
    for(auto c : odds) cout << c << " ";
    return 0;
}