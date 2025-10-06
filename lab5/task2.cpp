#include <iostream>
using namespace std;

int indirectprint(int n);

int printrecur(int n){
    if (n==0){
        return 0;
    }else{
        indirectprint(n-1);
        cout<<n<<endl;
        return n;
    }
}

int indirectprint(int n){
    return printrecur(n);
}

int main(){
    printrecur(5);
    return 0;
}
