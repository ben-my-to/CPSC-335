#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
using namespace std;

class HuffmanCodes {
	struct Node {
		char data;
		size_t freq;
		Node* left;
		Node* right;

		Node(char data, size_t freq)
            : data(data), freq(freq), left(nullptr), right(nullptr) {}

		~Node() {
			delete left;
			delete right;
		}
	};

	struct compare {
		bool operator()(Node* l, Node* r) {
			return (l->freq > r->freq);
		}
	};

	Node* top;

	void printCode(Node* root, std::string str)	{
		if (root == nullptr) return;

		if (root->data == '$') {
			printCode(root->left, str + "0");
			printCode(root->right, str + "1");
		}

		if (root->data != '$') {
			cout << root->data << " : " << str << "\n";
			printCode(root->left, str + "0");
			printCode(root->right, str + "1");
		}
	}

public:
	HuffmanCodes() {};
	~HuffmanCodes() { delete top; }

	void GenerateCode(vector<char>& data, vector<size_t>& freq, size_t size) {
		Node* left;
		Node* right;
		priority_queue<Node*, std::vector<Node*>, compare > minHeap;

		for (size_t i = 0; i < size; ++i) {
			minHeap.push(new Node(data[i], freq[i]));
		}

		while (minHeap.size() != 1) {
			left = minHeap.top();
			minHeap.pop();

			right = minHeap.top();
			minHeap.pop();

			top = new Node('$', left->freq + right->freq);
			top->left = left;
			top->right = right;
			minHeap.push(top);
		}
		printCode(minHeap.top(), "");
	}
};

int main() {
	HuffmanCodes set1;
	vector<char> data({ 'd', 'e', 'b', 'c', 'a', 'f' });
	vector<size_t> freq({ 16, 9, 13, 12, 45, 5 });
	size_t size = data.size();
	set1.GenerateCode(data, freq, size);

	return 0;
}