#include<iostream>
#include<string>

using namespace std;

int main(){
    int caseN = 0;
    while(true){
        caseN++;
        string s;
        getline(cin, s);
        if (s == "#") break;
        cout << "Case " << caseN << ": ";
        if (s == "HELLO") cout << "ENGLISH";
        else if (s == "HOLA") cout << "SPANISH";
        else if (s == "HALLO") cout << "GERMAN";
        else if (s == "BONJOUR") cout << "FRENCH";
        else if (s == "CIAO") cout << "ITALIAN";
        else if (s == "ZDRAVSTVUJTE") cout << "RUSSIAN";
        else cout << "UNKNOWN";
        cout << '\n';
    }
    return 0;
}