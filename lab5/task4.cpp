#include <iostream>
using namespace std;

int Ackermann(int m, int n) {
    if (m == 0)
        return n + 1;
    else if (m > 0 && n == 0)
        return Ackermann(m - 1, 1);
    else
        return Ackermann(m - 1, Ackermann(m, n - 1));
}

int main() {
    cout << "Ackermann(2, 3): " << Ackermann(2, 3) << endl;
    cout << "Ackermann(3, 4): " << Ackermann(3, 4) << endl;
}
//tf does this do??
