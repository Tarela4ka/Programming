#include<iostream>
#include<string>

using namespace std;

int main(){
    int n,p;
    scanf("%d%d", &n, &p);
    char s[101];
    scanf("%100s", &s);
    for(int i = 0; i < n; i++) 
        scanf("%100s", &s);
    
    printf("%d", p);
    return 0;
}