#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    string s;
    getline(cin, s);
    while(t--){
        getline(cin, s);
        if (s == "P=NP"){
            cout << "skipped\n";
            continue;
        }
        int a = stoi(s.substr(0, s.find('+')) ), b = stoi(s.substr(s.find('+')+1, s.size()-s.find('+')));
        cout << a + b << endl;
    }
}