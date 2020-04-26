#include <iostream>

using namespace std;
bool iloczyn_dwoch(int n){
    int p=2; ile=0;
    while(p*p<=n){
        while(!(n%p)){
            ++ile;
            n/=p;
        }
        ++p;
    }
    if(n>1){
        ++ile;
    }

    if(ile==2){
        return 1;
    }
    else{
        return 0;
    }
}
bool potega_dwojki(int n){
    //czy liczba jest potega danej liczby?
}
int main(){

    return 0;
}
