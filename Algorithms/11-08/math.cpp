#include <iostream>
#include <cmath>

using namespace std;

// displays all divisors of n (numbers that evenly divide by n)
void findDivisors(int n) {
    for (int i = 1; i <= n; ++i) {
        if (n % i == 0) cout << i << " ";
    }
}

// displays true or false if n is a prime number or not
bool isPrime(int n) {
    bool prime = true;
	// assume n is prime
    for (int i = 2; i < n; ++i) {
        if (n % i == 0) { prime = false; break; }
    }
    return prime;
}

// displays all prime numbers between 2 and n
void writePrimes(int x, int y) {
    for (int i = x; i <= y; ++i) {
        if (isPrime(i)) cout << i << " ";
    }
}

// displays all *prime* numbers that can be evenly divide by n
void primeFactorization(int n) {
    for (int i = 2; i <= n; ++i) {
        while (n % i == 0) {
            cout << i << " * ";
            n /= i;
        }
    }
    cout << "\b\b \n";
}

size_t GCD (size_t m, size_t n) {
    return (n == 0) ? m : GCD(n, m % n);
}

size_t findDigits(size_t m) {
	return (1 + size_t(log10(m)));
}

int convertStringToDigit(string m) {
	int num = 0, digit;
	for (int i = 0; i < m.length(); ++i) {
		digit = m[i] - '0';
		num = num*10 + digit;
	}
	return num;
}

int hornerAlg(int x, int a[], int n) {
	int S = a[0];
	for (int i = 1; i < n; ++i) S = S*x + a[i];
	return S;
}

bool isUgly(int n) {
	while (n % 2 == 0) n /= 2;
	while (n % 3 == 0) n /= 3;
	while (n % 5 == 0) n /= 5;

	return n == 1;	
}

int getNthUgly(int n) {
	int i = 1, count = 0;

	while (i++ <= n) {
		if (isUgly(i)) {
			cout << i << " ";
			count++;
		}
	}
	return count;
}

unsigned long int C(unsigned int n) {
	if (n <= 1) return 1; // C0 = 1, C1 = 1
	unsigned long int r = 0;
	for (int i = 0; i < n ; ++i) r += C(i) * C(n-i+1);
	return r;
}

int main() {
    int n = 3, x = 2, y = 25;
	unsigned int rv = 5;
	int test = 1043;
	string str = "1023";
	int a[5] = { 3, 5, 2, -3, 5 };

    cout << "findDivisors(" << n << ") = ";
    findDivisors(n);
    cout << "\nisPrime(" << n << ") = " << (isPrime(n) ? "true" : "false");
    cout << "\nwritePrimes(" << x << ", " << y << ") = ";
    writePrimes(x, y);
    cout << "\nprimeFactorization(" << n << ") = ";
    primeFactorization(n);
	cout << "findDigits(" << test << ") = " << findDigits(test) << endl;
	cout << "convertStringToDigit(\"" << str << "\") = " << convertStringToDigit(str) << endl;
	cout << "hornerAlg(" << x << ", a, 5) = " << hornerAlg(x, a, 5) << endl;
	cout << "Catalan(" << rv << ") = " << C(rv);
	cout << endl;
}
