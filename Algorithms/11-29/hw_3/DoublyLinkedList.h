#pragma once
#include <iostream>

template <typename T>
struct Node {
	T data;
	Node<T> *next, *prev;
	
	Node() : data(0), next(nullptr), prev(nullptr) {}
	Node(const T& d) : data(d), next(nullptr), prev(nullptr) {}
};

template <typename T>
class DoublyLinkedList {
public:
	Node<T> *head, *tail;

	DoublyLinkedList() : head(nullptr), tail(nullptr) {}
	~DoublyLinkedList() { removeList(head); }

	void insert(const T& c) { // insert x at the rear of doubly linked list
		Node<T>* temp = new Node<T>(c);

		if (!head) {
			head = temp;
			tail = temp;
			head->prev = nullptr;
			tail->next = nullptr;
		}
		else {
			Node<T>* curr = head;
			while (curr->next != nullptr) curr = curr->next;
			curr->next = temp;
			temp->prev = curr;
			tail = temp;
		}
	}

	void removeList(Node<T>* curr) {
		if (!curr) return;
		else removeList(curr->next);
		delete curr;		
	}
};
