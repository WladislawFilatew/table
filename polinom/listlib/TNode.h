#pragma once

/*!
* Выполнил: Филатьев В.
* Класс ячейки для списка
*/
template<class T>
struct Node
{
	T value; ///< Хранимое значение
	Node<T>* pNext; ///< Ссылка на следующую ячейку
	Node<T>* pPrev; ///< Ссылка на предедущую ячейку
	/*!
	* Конструктор иницилизации
	*/
	Node(T value,Node<T>* pPrev = nullptr,Node<T>* pNext = nullptr) {
		this->value = value;
		this->pNext = pNext;
		this->pPrev = pPrev;
	}
};
