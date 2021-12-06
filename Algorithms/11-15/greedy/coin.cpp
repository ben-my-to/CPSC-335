#include <iostream>

using namespace std;

int coins[] = { 25,5 };

int combo(int amount, int currentCoin) {
	int nCoins = 0;

	if (amount == 0) return 1;
	if (amount < 0)  return 0;
	for (int i = currentCoin; i < sizeof(coins)/sizeof(int); ++i) nCoins += combo(amount - coins[i], i);

	return nCoins;
}
int main() {
	cout << "number of denominations: " << combo(30, 0) << endl;
	return 0;
}
