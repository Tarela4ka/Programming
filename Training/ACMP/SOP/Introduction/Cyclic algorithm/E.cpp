#include<bits/stdc++.h>
int main(){
    int n;
    std::cin>>n;
    if (n < 0){
        std::cout << (-1*int(n*(n-1)/2) + 1);
    } else if (n == 0){
        std::cout << 1;
    } else {   
        std::cout << int(n*(n+1)/2);
    }
}