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
	cout << "Original list ALL: " << list;

	pthread_t p1, p2; // create two concurrent threads
	pthread_create(&p1, NULL, even, list.head);
    pthread_create(&p2, NULL, odd, list.head);

	pthread_join(p1, NULL);
	pthread_join(p2, NULL);

	cout << "New list ALL: " << result;

	result << 2;
	cout << "New list ALL: " << result;

	result >> 2;
	cout << "New list ALL: " << result;


	return 0;
}
