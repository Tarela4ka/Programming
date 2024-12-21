#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n, k;

int main(){
    cin >> n >> k;
    vector<int> a(n);
    for(auto& c : a) cin >> c;
    sort(a.begin(), a.end());

    int l = 1, r = *(a.end()-1)+1;
    int middle;
    while(true){
        middle = (r+l)/2;
        if (l>r) break;
        int c = 1, min = a[0];
        for(int i = 0; i < n; i++){
            if (a[i] >= min + middle){
                min = a[i];
                c++;
            }
        }
        if (c >= k){
            l = middle+1;
        } else {
            r = middle-1;
        }
    } 
    cout << middle;
}