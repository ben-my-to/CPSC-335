#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define N I.size() + 1

using namespace std;

struct pos { size_t row, col; };
queue<pos> q;

void init() {
	q.push({ 0, 2 });
	q.push({ 1, 3 });
	q.push({ 2, 4 });
	q.push({ 0, 3 });
	q.push({ 1, 4 });
	q.push({ 0, 4 });
}

struct cell { size_t base, pow; };

struct item {
	size_t data, cost;

	item() : data(0), cost(1) {}
	item(const size_t& d, const size_t& c) : data(d), cost(c) {}
};

item A(5, 4), B(6, 2), C(8, 6), D(20, 3);
vector<item> I = { A, B, C, D };
vector<vector<cell>> T;

void fill(vector<vector<cell>>& a) {
	for (int i = 0; i < N; ++i) {
		a.push_back({{0, 0}});
		for (int j = 1; j < N; ++j) a[i].push_back({0, 0});
	}
}

cell getmin(vector<cell> ans) {
	cell save = ans[0];
	for (int i = 1; i < ans.size(); ++i) {
		if (ans[i].base < save.base) save = ans[i];
		else if (ans[i].base == save.base) {
			if (ans[i].pow < save.pow) save = ans[i];
		}
	}
	return save;
}

void foo(vector<vector<cell>>& T, size_t i, size_t j) {
	cout << i << " < k <= " << j << endl;; 
	vector<cell> ans;
	for (size_t k = i+1; k <= j; ++k) {	
		cout << "C[" << i << ", " << j << "] = { " 
		<< "C[" << i << ", " <<  k-1 << "] + C[" << k << ", " << j << "] + V[" << i+1 << ", " << j << "] } = ";

		size_t temp = T[i][k-1].base + T[k][j].base;

		cout << T[i][k-1].base;
		cout << " + ";
		cout << T[k][j].base;
		cout << " + ("; 
		for (int t = i; t < j; ++t) {
			temp += I[t].cost;
			cout << I[t].cost;
			if (t+1 != j) cout << " + ";
		}
		cout << ") = " << temp << endl;

		ans.push_back({ temp, k });
	}

	cout << "\nmin { ";
	for (int a = 0; a < ans.size(); ++a) {
		cout << ans[a].base << "^" << ans[a].pow;
		if (a+1 != ans.size()) cout << ", ";
	}
	cell b = getmin(ans);
	cout << " } = " << b.base << "^" << b.pow << endl << endl;
	T[i][j] = { b.base, b.pow };
}

void make() {
	for (size_t m = 0; m < N; ++m) {
		for (size_t r = 0; r < N; ++r) if (r-m == 1) T[m][r] = { I[m].cost, r };
	}

	while (!q.empty()) {
		size_t i = q.front().row, j = q.front().col;	
		foo(T, i, j);
		q.pop();
	}
}

int main() {
	fill(T);
	init();

	make();

	cout << endl;
	for (vector<cell> m : T) {
		for (cell t : m) {
			cout << t.base << "^" << t.pow << " ";
		}
		cout << endl;
	}

	return 0;
}
