#pragma once
#include "TNode.h"
#include <iostream>
using namespace std;

template<class T>
class List {
	Node<T>* head;
	Node<T>* tail;
	size_t size;

	Node<T>* getNode(int index);
public:
	List();
	~List();
	void push_back(T value);
	void push_front(T value);
	void insert(T value, size_t index);
	void pop_back();
	void pop_front();
	void erase(size_t index);
	void clear();
	bool isEmpty() { return size == 0; }
	size_t Size() { return size; }
	T& operator[](size_t index);
	T& at(size_t index);
	T& back() { return tail->value; }
	T& front() { return head->value; }
	bool operator==(const List<T> other);
	
	

public:
	class iterator {
		Node<T>* t;
	public:
		iterator() { t = nullptr; }
		void operator=(Node<T>* note) {
			t = note;
		}
		T& operator*() {
			return t->value;
		}
		void operator++(int k) {
			t = t->pNext;
		}
		void operator--(int k) {
			t = t->pPrev;
		}
		bool operator!=(const Node<T>* note) {
			return t != note;
		}
		Node<T>* getNode() {
			return t;
		}
	};

	Node<T>* begin() { return head; }
	Node<T>* end() { return (tail == nullptr) ? tail : tail->pNext; }

	List(List<T>& other);
	List<T>& operator=(List<T>& other);
	
	void insert(T value, List<T>::iterator it);
};

template<class T>
inline Node<T>* List<T>::getNode(int index)
{
	Node<T>* temp;
	if (index < size / 2) {
		int kol = 0;
		temp = head;
		while (kol != index) {
			temp = temp->pNext;
			kol++;
		}
	}
	else {
		int kol = size - 1;
		temp = tail;
		while (kol != index) {
			temp = temp->pPrev;
			kol--;
		}
	}
	return temp;
}

template<class T>
List<T>::List() {
	head = nullptr;
	tail = nullptr;
	size = 0;
}

template<class T>
inline List<T>::List(List<T>& other):List()
{
	List<T>::iterator it;
	it = other.begin();
	while (it != other.end()) {
		this->push_back(*it);
		it++;
	}
}

template<class T>
inline List<T>& List<T>::operator=(List<T>& other)
{
	if (this == &other) {
		return *this;
	}
	this->clear();
	List<T>::iterator it;
	it = other.begin();
	while (it != other.end()) {
		this->push_back(*it);
		it++;
	}
	return *this;
}

template<class T>
inline List<T>::~List()
{
	clear();
}

template<class T>
inline void List<T>::push_back(T value)
{
	if (size == 0) {
		head = new Node<T>(value);
		tail = head;
	}
	else {
		tail->pNext = new Node<T>(value,tail);
		tail = tail->pNext;
	}
	size++;
}

template<class T>
inline void List<T>::push_front(T value)
{
	if (size == 0) {
		head = new Node<T>(value);
		tail = head;
	}
	else {
		Node<T>* temp = new Node<T>(value, nullptr, head);
		head->pPrev = temp;
		head = temp;
	}
	size++;
}

template<class T>
inline void List<T>::insert(T value, size_t index)
{
	if (index > size)
		throw exception("of range");
	if (index == 0)
		push_front(value);
	else if (index == size)
		push_back(value);
	else {
		Node<T>* temp = getNode(index - 1);
		Node<T>* newNode = new Node<T>(value, temp, temp->pNext);
		temp->pNext->pPrev = newNode;
		temp->pNext = newNode;

		size++;
	}
}

template<class T>
inline void List<T>::insert(T value, List<T>::iterator it)
{
	if (it.getNode() == nullptr)
		push_back(value);
	else if (it.getNode()->pPrev == nullptr)
		push_front(value);
	else {
		Node<T>* temp = it.getNode()->pPrev;
		Node<T>* newNode = new Node<T>(value, temp, temp->pNext);
		temp->pNext->pPrev = newNode;
		temp->pNext = newNode;

		size++;
	}
}

template<class T>
inline void List<T>::pop_back()
{
	Node<T>* temp = tail->pPrev;
	delete tail;
	tail = temp;
	if (temp != nullptr)
		tail->pNext = nullptr;
	size--;
}

template<class T>
inline void List<T>::pop_front()
{
	Node<T>* temp = head;
	if (head != nullptr) {
		head = head->pNext;
	}
	if (head != nullptr) {
		head->pPrev = nullptr;
	}
	else {
		tail = head;
	}
	delete temp;
	size--;
}

template<class T>
inline void List<T>::erase(size_t index)
{
	if (index > size - 1)
		throw exception("of range");
	if (index == 0)
		pop_front();
	else if (index == size - 1)
		pop_back();
	else {
		Node<T>* temp = getNode(index - 1);
		Node<T>* del = temp->pNext;
		del->pNext->pPrev = temp;
		temp->pNext = del->pNext;

		delete del;
		size--;
	}
	
}

template<class T>
inline void List<T>::clear()
{
	while (!isEmpty()) {
		this->pop_back();
	}
	head = tail = nullptr;
}

template<class T>
inline T& List<T>::operator[](size_t index)
{
	return getNode(index)->value;
}

template<class T>
inline T& List<T>::at(size_t index)
{
	if (index > size)
		throw exception("of range");
	return this->operator[](index);
}

template<class T>
inline bool List<T>::operator==(List<T> other)
{
	if (this->size != other.size)
		return false;
	List<T>::iterator it1,it2;
	it1 = this->begin();
	it2 = other.begin();

	while (it1 != this->end()) {
		if (!((*it1) == (*it2)))
			return false;
		it1++;
		it2++;
	}
	return true;
}
