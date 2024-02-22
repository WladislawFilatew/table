#pragma once

template<class T>
struct Node
{
	T value;
	Node<T>* pNext;
	Node<T>* pPrev;
	Node(T value,Node<T>* pPrev = nullptr,Node<T>* pNext = nullptr) {
		this->value = value;
		this->pNext = pNext;
		this->pPrev = pPrev;
	}
};
