#include <iostream>
#include <vector>
using namespace std;


template<class T>
class MyStack {

public:
	MyStack() noexcept;
	bool empty() noexcept;
	void push(T value);
	void pop();
	void clear();
	size_t size() noexcept { return sz; }
	T& top();
	~MyStack();

private:
	template<class T>
	class Note {
	public:
		T value;
		Note* next;
		Note(T value = T(),Note* next = nullptr) {
			this->value = value;
			this->next = next;
		}
	};

	Note<T>* head;
	size_t sz;
};



template<class T>
inline MyStack<T>::MyStack() noexcept
{
	head = nullptr;
	sz = 0;
}

template<class T>
bool MyStack<T>::empty() noexcept
{
	if (sz == 0)
		return true;
	return false;
}

template<class T>
void MyStack<T>::push(T value)
{
	if (head == nullptr)
		head = new Note<T>(value);
	else {
		Note<T>* temp =  new Note<T>(value,head);
		this->head = temp;
	}
	sz++;
}

template<class T>
void MyStack<T>::pop()
{
	if (this->empty())
		throw exception("Отсутствуют элементы в стеке");
	Note<T>* temp = head;
	head = head->next;
	delete temp;
	sz--;
}

template<class T>
inline void MyStack<T>::clear()
{
	while (!this->empty())
		this->pop();
}

template<class T>
T& MyStack<T>::top()
{
	if (this->empty())
		throw exception("Отсутствуют элементы в стеке");
	return head->value;
}

template<class T>
inline MyStack<T>::~MyStack()
{
	this->clear();
}
