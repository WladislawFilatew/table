#pragma once
/**
*��������: �������� �.
*������ ����, ������ ���������� ������������ ������ � ������������ �������� ������ �����
*/
template<class T>
class MyStack {

public:
	/**
	����������� ������
	*/
	MyStack() noexcept;
	/*!
	����� ���������� ������ �� ����
	\param[out] �������� �������� ���� bool
	*/
	bool empty() noexcept;
	/*!
	���������� �������� � ������ �����
	\param[in] ������� �������� ���� T 
	*/
	void push(T value);
	/*!
	�������� �������� �� ������ �����
	*/
	void pop();
	/*!
	������� �����
	*/
	void clear();
	/*!
	������� ���������� ���������� ���������� � �����
	\param[out] �������� �������� ���� int
	*/
	size_t size() noexcept { return sz; }
	/*!
	������� ���������� ������ �� ������� �����
	\param[in] ������� �������� ���� T&
	*/
	T& top();
	/*!
	����������
	*/
	~MyStack();

private:
	/**
	*��������� ����� ������ �����, ������ � ���� ��� ���� �������� � ������ �� ��������� ������
	*/
	template<class T>
	class Note {
	public:
		T value; ///<�������� ���������� � ������
		Note* next;///<������ �� ��������� ������
		/*!
		�����������
		\param[in] value ������� �������� T �������� ������� ����� �������� � ���� ������
		\param[in] ������� �������� ������ �� ��������� �������
		*/
		Note(T value = T(),Note* next = nullptr) {
			this->value = value;
			this->next = next;
		}
	};

	Note<T>* head; ///<������ �� ������ �����
	size_t sz; ///<��������� ��������� � �����
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
		throw std::exception("����������� �������� � �����");
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
		throw std::exception("����������� �������� � �����");
	return head->value;
}

template<class T>
inline MyStack<T>::~MyStack()
{
	this->clear();
}
