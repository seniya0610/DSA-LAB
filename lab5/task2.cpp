#include <iostream>
using namespace std;

int printrecur(int n){
    if (n==0){
        return 0;
    }else{
        printrecur(n-1);
        cout<<n<<endl;
        return n;
    }
}

int main(){
    printrecur(5);
    return 0;
}
