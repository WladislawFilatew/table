#pragma once
#include "TNode.h"
#include <iostream>
using namespace std;

/*!
* Выполнил: Филатьев В.
* Класс список, реализован двухстороний список на ссылках
*/
template<class T>
class List {
	Node<T>* head; ///< Ссылка на первый элемент списка
	Node<T>* tail; ///< Ссылка на последний элемент списка
	size_t size; ///< Размер списка

	/*!
	* Функция получения ячейки по индексу 
	* \param[in] входной параметр int - индекс элемента
	* \param[out] выходной параметр Node - ссылка на ячейку
	*/
	Node<T>* getNode(int index);
public:
	/*!
	* Конструктор
	*/
	List();
	/*!
	* Диструктор
	*/
	~List();
	/*!
	* Добавление элемента в конец списка
	* \param[in] входной параметр T - значение ячейки
	*/
	void push_back(T value);
	/*!
	* Добавление элемента в начала списка
	* \param[in] входной параметр T - значение ячейки
	*/
	void push_front(T value);
	/*!
	* Добавление элемента в список
	* \param[in] входной параметр T - значение ячейки
	* \param[in] входной параметр int - индекс в который требуется вставить ячейку
	*/
	void insert(T value, size_t index);
	/*!
	* Удале элемента с конца списка
	*/
	void pop_back();
	/*!
	* Удале элемента с начала списка
	*/
	void pop_front();
	/*!
	* Удале элемента из списка
	* \param[in] входной параметр int - индекс из которой необходимо удалить ячейку
	*/
	void erase(size_t index);
	/*!
	* Очистка списка
	*/
	void clear();
	/*!
	* Функция проверки спписка на пустоту
	* \param[out] выходной параметр bool
	*/
	bool isEmpty() { return size == 0; }
	/*!
	* Функция возврашает количество элементов в списке
	* \param[out] выходной параметр size_t - размер списка
	*/
	size_t Size() { return size; }
	/*!
	* Функция возврашает ссылку на элемент под индексом без проверки
	* param[in] входной параметр int - индекс элемента
	* \param[out] выходной параметр T - ссылка на элемент
	*/
	T& operator[](size_t index);
	/*!
	* Функция возврашает ссылку на элемент под индексом с проверкой
	* param[in] входной параметр int - индекс элемента
	* \param[out] выходной параметр T - ссылка на элемент
	*/
	T& at(size_t index);
	/*!
	* Функция возврашает ссылку на последний элемент
	* \param[out] выходной параметр T - ссылка на элемент
	*/
	T& back() { return tail->value; }
	/*!
	* Функция возврашает ссылку на первый элемент
	* \param[out] выходной параметр T - ссылка на элемент
	*/
	T& front() { return head->value; }
	/*!
	* Оператор сравнения двух списков
	* \param[out] выходной параметр bool - true если два списка равны
	* \param[in] входной параметр list - список с которым сравнится исходный
	*/
	bool operator==(const List<T> other);
	
	

public:
	/*!
	* Внутриний класс итерато, предназначен для об
	*/
	class iterator {
		Node<T>* t; ///< Указатель на ячейку
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
	/*!
	* Получить указатель на первый элемен списка
	* \param[out] выходной параметр Note - указатель на первый элемент списка
	*/
	Node<T>* begin() { return head; }
	/*!
	* Получить указатель на последний элемен списка
	* \param[out] выходной параметр Note - указатель на последний элемент списка
	*/
	Node<T>* end() { return (tail == nullptr) ? tail : tail->pNext; }

	/*!
	* Конструктор копирования
	*/
	List(List<T>& other);
	/*!
	* Опиратор сравнения
	*/
	List<T>& operator=(List<T>& other);
	
	/*!
	* Добавление элемента в список
	* \param[in] входной параметр T - значение ячейки
	* \param[in] входной параметр iterator - итератор по которому требуется вставить ячейку
	*/
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
