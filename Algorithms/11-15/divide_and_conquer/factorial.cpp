#include <iostream>

using namespace std;

int factorial(int n) {
    BS: if (n == 0) return 1;
    RR: int r = factorial(n-1);
    GLU: return r * n;
    /* Stack Call
        * ----------
        * 1  * 1 = 1
        * 1  * 2 = 2
        * 2  * 3 = 6
        * 6  * 4 = 24
        * 24 * 5 = 120
        * 
    */
}

size_t fibonacci(size_t n) {
    return (n <= 1) ? n : fibonacci(n-1) + fibonacci(n-2);
}