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
	size_t size;

	DoublyLinkedList() : head(nullptr), tail(nullptr), size(0) {}
	~DoublyLinkedList() { removeList(head); }

	ssize_t getsize() const { return size; }

	friend std::ostream& operator<<(std::ostream& os, const DoublyLinkedList<T>& list) {
		Node<T>* curr = list.head;
		while (curr) {
			os << curr->data << "->";
			curr = curr->next;
		}
		os << "nullptr\n";
		return os;
	}

	friend DoublyLinkedList<T>& operator<<(DoublyLinkedList<T>& list, const size_t& offset) {
		for (size_t i = 0; i < offset; ++i) {
			Node<T>* curr = list.head;
			Node<T>* temp = list.head->next;
			list.head = temp;
			delete curr;
			list.insertBack(0);
		}

		return list;
	}

	void insertBack(const T& value) {
		Node<T>* temp = new Node<T>(value);
		if (!head) head = temp;
		else {
			Node<T>* curr = head;
			while (curr->next != nullptr) curr = curr->next;	
			curr->next = temp;
			tail = temp;
		}
		size++;
	}

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
		size++;
	}

	void removeList(Node<T>* curr) {
		if (!curr) return;
		else removeList(curr->next);
		delete curr;		
	}
};
