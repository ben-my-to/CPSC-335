#include <pthread.h>
#include "LinkedList.h"

using namespace std;
using T = int;

LinkedList<T> list, result;

void* even(void* arg) {
	Node<T>* curr = static_cast<Node<T>*>(arg);
	while (curr) {
		if (curr->data % 2 == 0) result.insertAfter(curr->data);
		curr = curr->next;
	}
	pthread_exit(0);
}

void* odd(void* arg) {
	Node<T>* curr = static_cast<Node<T>*>(arg);
	while (curr) {
		if (curr->data % 2 != 0) result.insertBack(curr->data);
		curr = curr->next;
	}
	pthread_exit(0);
}

int main() {
	// generates 10 random numbers between 10 and 40 and allocate them in the list
	for (int i = 0; i < 10; ++i) list.insertBack(rand() % 40 + 10);
	cout << "Original list ALL: "; list.print(list.head);

	pthread_t p1, p2; // create two concurrent threads
	Node<T>* input = list.head;
	pthread_create(&p1, NULL, even, input);
    pthread_create(&p2, NULL, odd, input);

	pthread_join(p1, NULL);
	pthread_join(p2, NULL);

	cout << "New list ALL: "; result.print(result.head);
	return 0;
}
