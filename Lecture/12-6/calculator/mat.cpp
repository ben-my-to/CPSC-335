#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define N mem.size()

using namespace std;

struct mat {
	size_t row, col;

	mat() : row(1), col(1) {}
	mat(const size_t& r, const size_t& c) : row(r), col(c) {}
};

struct save { size_t v; size_t p; };
struct pos { size_t row, col; };
queue<pos> q;
vector<vector<size_t>> M, D;
vector<vector<string>> _D;
vector<size_t> d;

mat A1(4, 5), A2(5, 3), A3(3, 4), A4(4, 4);
vector<mat> mem = { A1, A2, A3, A4 };

void getD() {
	for (int i = 0; i < N; ++i) {
		if (i == N-1) {
			d.push_back(mem[i].row);
			d.push_back(mem[i].col);
		}
		else d.push_back(mem[i].row);
	}
}

void fill(vector<vector<size_t>>& a, size_t n) {
	for (int i = 0; i < n; ++i) {
		a.push_back({0});
		for (int j = 1; j < n; ++j) a[i].push_back(0);
	}
}

void fill(vector<vector<string>>& a, size_t n) {
	for (int i = 0; i < n; ++i) {
		a.push_back({""});
		for (int j = 1; j < n; ++j) a[i].push_back("");
	}
}

void init() {
	q.push({ 4, 1 });
	q.push({ 3, 1 });
	q.push({ 4, 2 });
	q.push({ 2, 1 });
	q.push({ 3, 2 });
	q.push({ 4, 3 });
	q.push({ 1, 1 });
	q.push({ 2, 2 });
	q.push({ 3, 3 });
	q.push({ 4, 4 });
	q.push({ 1, 2 });
	q.push({ 2, 3 });
	q.push({ 3, 4 });
	q.push({ 1, 3 });
	q.push({ 2, 4 });
	q.push({ 1, 4 });
}

save getmin(const vector<save>& R) {
	save min = R[0];
	for (save r : R) {
		if (r.v <= min.v) min = r;
	}
	return min;
}

string getmat(int i, int j) {
	return "A" + to_string(i) + " . " + "A" + to_string(j);
}

void setD(size_t i, size_t j, size_t t) {
	size_t k;
	for (k = 0; k < d.size(); ++k) {
		if (d[k] == t) break;
	}
	_D[i][j] = "d" + to_string(k);
	_D[i][j] += " = " + to_string(t);
}

void makeTable() {
	for (int asdf = 0; asdf < N*N; ++asdf) {
		int i = q.front().row, j = q.front().col;
		// below or on main diagonal
		if (i == j || i > j) goto HERE;
		if (j-i == 1) {
			size_t t = mem[i-1].row * mem[i-1].col * mem[j-1].col;
			setD(i-1, j-1, d[j-1]);
			cout << "M[" << i << "][" << j << "] = " << getmat(i, j) << " = " << mem[i-1].row << " * " << mem[i-1].col << " * " << mem[j-1].col << " = " << t << ", with " << _D[i-1][j-1] << " = D[" << i << ", " << j << "]\n";
			M[i-1][j-1] = t;
			D[i-1][j-1] = d[j-1];
		}
		else {
			vector<save> R = {};
			for (int k = i; k < j; ++k) {
				size_t a = (M[i-1][k-1] + M[k][j-1]) + (d[i-1] * d[k] * d[j]);
				cout << "M[" << i << "][" << j << "] = (M[" << i << "][" << k << "] + M[" << k+1 << "][" << j << "]) + (d[" << i-1 << "] * d[" << k << "] * d[" << j << "]) = "
				<< "(" << M[i-1][k-1] << " + " << M[k][j-1] << ") + (" << d[i-1] << " * " << d[k] << " * " << d[j] << ") = " << a << endl;
				R.push_back({a, d[k]});
			}
			save _save = getmin(R);
			setD(i-1, j-1, _save.p);
			cout << "        = min( ";
			for (save r : R) cout << r.v << " ";
			cout << ") = " << _save.v << ", with " << _D[i-1][j-1] << " = D[" << i << ", " << j << "]\n";
			M[i-1][j-1] = _save.v;
			D[i-1][j-1] = _save.p;
		}
		HERE: q.pop();
	}
}

int main(int argc, char** argv) {
	fill(M, N);
	fill(D, N);
	fill(_D, N);
	init();

	getD();

	for (int i = 0; i < d.size(); ++i) {
		cout << "d" << i << " = " << d[i] << ((i+1 != d.size()) ? ", " : "");
	}
	cout << "\n\n";

	makeTable();

	cout << endl;
	for (vector<size_t> m : M) {
		for (size_t t : m) {
			cout << t << " ";
		}
		cout << endl;
	}

	cout << endl;
	for (vector<size_t> m : D) {
		for (size_t t : m) {
			cout << t << " ";
		}
		cout << endl;
	}

	return 0;
}
