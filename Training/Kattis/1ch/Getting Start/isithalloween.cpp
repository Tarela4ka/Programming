#include <iostream>
#include <string>
using namespace std;

int main(){
    string s;
    getline(cin, s);
    if (s == "OCT 31" || s == "DEC 25") cout << "yup";
    else cout << "nope";
}