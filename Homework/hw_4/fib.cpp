#include <bits/stdc++.h>

using namespace std;

#define ODD (n & 1)
 
int mem[100] = {0};
 
int fib(int n) {
    if (n == 0) return 0;
    if (n == 1 || n == 2) return (mem[n] = 1);
    if (mem[n]) return mem[n];
 
    int k = (n & 1)? (n+1)/2 : n/2;
 
    mem[n] = (n & 1) ? (fib(k) * fib(k) + fib(k-1) * fib(k-1))
		: (2 * fib(k-1) + fib(k)) * fib(k);
 
    return mem[n];
}
 
int main(int argc, char** argv) {
	if (argc != 2) {
		std::cout << "usage: ./<binary> <integer>\n";
		exit(1);
	}

	if (atoi(argv[1]) < 0) {
		std::cout << "instance must be >= 0\n";
		exit(1);
	}

	std::cout << fib(atoi(argv[1])) << std::endl;

	return 0;
}
