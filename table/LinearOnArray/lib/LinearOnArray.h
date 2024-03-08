#include <iostream>
#include "table.h"
#include <vector>
#include <list>
using namespace std;

/*!
* Выполнил: Филатьев В.
* класс LinearOnArray - линейная таблица на массиве
* \param[in] входной параметр Key - ключ для строки
* \param[in] входной параметр Value - значение строки
*/
template <class Key, class Value>
class LinerOnArray : public table<Key,Value> {
private:
    vector<Line> array; ///<Массив строк

    int index = 0; ///< Индекс актуальной строки

public:
    /*!
    * Метод поиска строкм по ключу
    * \param[in] входной параметр Key - ключ строки
    * \param[out] выходной параметр Value - значение строки, если не найден то nullptr
    */
    Value* Find(Key key) override;

    /*!
    * Метод добавление записи в таблицу
    * \param[in] входной параметр Key - ключ строки
    * \param[in] входной параметр value - запись
    * \param[out] выходной параметр bool - true если элемент добавлен успешно
    */
    virtual bool Insert(Key key, Value value) override;

    /*!
    * Метод удаления записи из таблицы
    * \param[in] входной параметр Key - ключ строки
    * \param[out] выходной параметр bool - true если элемент удален успешно
    */
    virtual bool Delete(Key key) override;



    /*!
    * Метод получения ключа актуальной записи
    * \param[out] выходной параметр key - ключ актуальной записи
    */
    Key GetKey(void) const override;

    /*!
     * Метод получения значение актуальной записи
    * \param[out] выходной параметр key - значение актуальной записи
    */
    Value GetValuePtr(void) override;

    /*!
    * Метод установки актуальной записи на начало таблицы
    */
    void Reset(void) override;

    /*!
    * Метод проверки актуальной записи на конец таблицы
    * \param[out] выходной параметр bool - true если актуальная запись указывает на конец таблицы
    */
    bool IsTabEnded(void) override;

    /*!
    * Метод перестановки актуальной записи на следующую строку
    */
    void GoNext(void) override;


};

template<class Key, class Value>
bool LinerOnArray<Key, Value>::Insert(Key key, Value value)
{
    if (this->IsFull())
        return false;
    int pos = -1;
    for (int i = 0; i < count; i++) {
        if (array[i].key == key) {
            pos = i;
            break;
        }
    }
    if (pos != -1)
        return false;
    array.push_back({ key,value });
    count++;
    return true;
}


template<class Key, class Value>
Value* LinerOnArray<Key, Value>::Find(Key key)
{
    for (int i = 0; i < count; i++) {
        if (array[i].key == key) {
            return &array[i].value;
        }
    }
    return nullptr;
}


template<class Key, class Value>
bool LinerOnArray<Key, Value>::Delete(Key key)
{
    if (this->IsEmpty())
        return false;
    int pos = -1;
    for (int i = 0; i < count; i++) {
        if (array[i].key == key) {
            array[i] = array[count - 1];
            array.pop_back();
            count--;
            return true;
        }
    }
    return false;
}


template<class Key, class Value>
inline Key LinerOnArray<Key, Value>::GetKey(void) const
{
    return array[index].key;
}

template<class Key, class Value>
inline Value LinerOnArray<Key, Value>::GetValuePtr(void)
{
    return array[index].value;
}

template<class Key, class Value>
inline void LinerOnArray<Key, Value>::Reset(void)
{
    index = 0;
}

template<class Key, class Value>
inline bool LinerOnArray<Key, Value>::IsTabEnded(void)
{
    return index == count;
}

template<class Key, class Value>
inline void LinerOnArray<Key, Value>::GoNext(void)
{
    if (index == count)
        index = 0;
    else {
        index++;
    }
}
