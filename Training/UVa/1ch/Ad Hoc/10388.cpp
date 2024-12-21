#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    int t; cin >> t;
    while(t--){
        string fdg, fdb, fug = "", fub = "";
        cin >> fdg >> fdb;
        // cout << fdg << " " << fdb << endl;
        int step = 0;
        int l1 = 0, l2 = 0, n1 = fdg.size(), n2 = fdb.size();
        while(step < 1000){
            fug += fdg[l1]; fub += fdb[l2]; 
            step++;
            // cout << fug << " " << fub << " " << l1 << " " << l2 << " " << fdg.size() << " " << fdb.size() << endl;
            if (fdg[l1] == fdb[l2]){
                if (!(rand()/141%2)){
                    fug += fub;
                    fub = "";
                    reverse(fug.begin(), fug.end());
                    cout << "Snap! for Jane: " << fug << endl; 
                    reverse(fug.begin(), fug.end());
                }else {
                    fub += fug;
                    fug = "";
                    reverse(fub.begin(), fub.end());
                    cout << "Snap! for John: " << fub << endl; 
                    reverse(fub.begin(), fub.end());
                }
            }
            if (l1 >= fdg.size()-1){
                fdg = fug;
                fug = "";
                l1 = -1;
            }
            if (l2 >= fdb.size()-1){
                fdb = fub;
                fub = "";
                l2 = -1;
            }
            l1++; l2++;
            if (fdb == ""){
                cout << "Jane wins.\n";
                break;
            }
            if (fdg == ""){
                cout << "John wins.\n";
                break;
            }
        }
        if (step >= 1000){
            cout << "Keeps going and going ...\n";
        }
        // cout << endl;
    }
}
