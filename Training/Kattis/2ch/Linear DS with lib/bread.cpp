#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
// #define int long long int
#define all(a) a.begin(), a.end()
using vi = vector<int>;
using vvi = vector<vi>;
using vc = vector<char>;
using vvc = vector<vc>;
using vs = vector<string>;

int inv = 0;
vi a;

vi mergeSort(int l, int r){
    if (l == r){
        return {a[l]};
    } else if (r - l == 1){
        if (a[l] > a[r]) {inv++; return {a[r], a[l]};}
        return {a[l], a[r]};
    }
    vi sorted;
    int mid = (l+r)/2;
    vi a1 = mergeSort(mid+1, r), a2 = mergeSort(l, mid);

    int i1 = 0, i2 = 0;
    int n1 = a1.size(), n2 = a2.size();
    while(i1 < n1 || i2 < n2){
        if (i1 < n1){
            if (i2 < n2){
                if (a1[i1] < a2[i2]){
                    sorted.push_back(a1[i1]);
                    inv += (n2 - i2);
                    i1++;
                }else{
                    sorted.push_back(a2[i2]);
                    i2++;
                }
            }else{
                sorted.push_back(a1[i1]);
                inv += (n2 - i2);
                i1++;
            }
        } else if (i2 < n2){
            sorted.push_back(a2[i2]);
            i2++;
        }
    }
    return sorted;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    a.resize(n);
    for(auto& c : a) cin >> c;
    mergeSort(0, n-1);
    int inv1 = inv; inv = 0;

    for(auto& c : a) cin >> c;
    mergeSort(0, n-1);
    int inv2 = inv;

    if (abs(inv2 - inv1) % 2 == 0){
        cout << "Possible";
    }else{
        cout << "Impossible";
    }
}