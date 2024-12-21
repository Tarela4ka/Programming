#include<bits/stdc++.h>
using namespace std;
int n,a,b,x=0;
int main(){
    cin >> n;
    map<int,int>r;
    for(;cin>>a>>b;)r[a]++,r[b]++;
    for (auto c:r)x+=(c.second>=2 ? 1 : 0);
    cout<<x;
}