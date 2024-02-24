#pragma once
/**
*Выполнил: Филатьев В.
*Ксласс стек, внутри реализован одностороний список и реализованны основные методы стека
*/
template<class T>
class MyStack {

public:
	/**
	Конструктор класса
	*/
	MyStack() noexcept;
	/*!
	Метод возврашает пустой ли стек
	\param[out] выходной параметр типа bool
	*/
	bool empty() noexcept;
	/*!
	Добавление элемента в начало стека
	\param[in] входной параметр типа T 
	*/
	void push(T value);
	/*!
	Удаление элемента из начала стека
	*/
	void pop();
	/*!
	Очистка стека
	*/
	void clear();
	/*!
	Функция возврашает количество эллементов в стеке
	\param[out] выходной параметр типа int
	*/
	size_t size() noexcept { return sz; }
	/*!
	Функция возврашает ссылку на вершину стека
	\param[in] входной параметр типа T&
	*/
	T& top();
	/*!
	Диструктор
	*/
	~MyStack();

private:
	/**
	*Внитриний класс ячейки стека, хранит в себе два поля значение и ссылку на следующую ячейку
	*/
	template<class T>
	class Note {
	public:
		T value; ///<Значение хранящиеся в ячейке
		Note* next;///<Ссылка на следующую ячейку
		/*!
		Конструктор
		\param[in] value входной параметр T значение которое будет хранится в этой ячейке
		\param[in] входной параметр ссылка на следующий элемент
		*/
		Note(T value = T(),Note* next = nullptr) {
			this->value = value;
			this->next = next;
		}
	};

	Note<T>* head; ///<Ссылка на начало стека
	size_t sz; ///<Количесто элементов в стеке
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
		throw std::exception("Отсутствуют элементы в стеке");
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
		throw std::exception("Отсутствуют элементы в стеке");
	return head->value;
}

template<class T>
inline MyStack<T>::~MyStack()
{
	this->clear();
}
