#include<iostream>
#include<string>
#include<map>
#include<vector>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, x = 0;
        cin >> n;
        if (n % 2){
            cout << "Kosuke\n";
        }else{
            cout << "Sakurako\n";
        }
    }
    return 0;
}