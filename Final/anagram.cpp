#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

bool isAnagram(string st1, string st2) {
	// converting to lower-case
	for (int i = 0; i < st1.length(); ++i) st1[i] = tolower(st1[i]);
	for (int i = 0; i < st2.length(); ++i) st2[i] = tolower(st2[i]);

	if (st1.length() != st1.length()) return false;
	
	sort(st1.begin(), st1.end());
	sort(st2.begin(), st2.end());

	for (int i = 0; i < st1.length(); ++i) {
		if (st1[i] != st2[i]) return false;
	}

	return true;
}

int main() {
	string f, s;
	string ans = "n";

	do {
		cout << "\nEnter a string: "; getline(cin, f);
		cout << "Enter another string: "; getline(cin, s);
		bool b = isAnagram(f, s);
		cout << "\n\"" << f << "\" and \"" << s << "\"" << (b ? " are anagrams" : " are not anagrams") << endl;
		cout << "CONTINUE (y/n)? ";
	} while (getline(cin, ans) && ans != "n");

	return 0;
}
