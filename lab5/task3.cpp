// task3
//  1. Implement a C++ function sumTail(int n, int total) that calculates the sum
//  of numbers from 1 to n using tail recursion. The recursive call should be the last
//  operation in the function.
//  2. Implement another function sumNonTail(int n) that calculates the same sum
//  using non-tail recursion. This function should perform an operation (e.g., addition) after
//  the recursive call returns. Compare the two implementations and explain the difference
//  in their call stacks.

#include <iostream>
using namespace std;

// Non-tail recursion
int sumNonTail(int n)
{
    if (n == 0)
    {
        return 0;
    }
    else
    {
        return sumNonTail(n - 1) + n;
    }
}

// Tail recursion
int sumTail(int n, int total)
{
    if (n == 0)
    {
        return total;
    }
    else
    {
        return sumTail(n - 1, total + n);
    }
}

int main()
{
    cout << "Non-tail sum (1 to 5): " << sumNonTail(5) << endl;
    cout << "Tail sum (1 to 5): " << sumTail(5, 0) << endl;
}
