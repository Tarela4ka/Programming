#include<bits/stdc++.h>
main(){
    int c,a=0,i=0;for(;std::cin>>c;a+=!c,i++);std::cout<<std::min(a,i-1-a);
}