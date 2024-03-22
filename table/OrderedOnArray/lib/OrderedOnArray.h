#include <iostream>
#include "table.h"
#include <algorithm>
using namespace std;

/*!
* Выполнила: Соловьева Елизавета
 класс OrderedOnArray - линейная таблица на массиве
* \param[in] входной параметр Key - ключ для строки
* \param[in] входной параметр Value - значение строки
*/

template <class Key, class Value>
class OrderedOnArray : public table<Key, Value> {
private:
    vector <Line> arr; ///<Массив строк
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
inline Value* OrderedOnArray<Key, Value>::Find(Key key)
{
    bool fl = false;
    int l = 0, r = (count - 1);
    int c;
    while (l <= r) {
        c = (r + l) / 2;
        if (arr[c].key == key) {
            fl = true;
            break;
        }
        if (arr[c].key > key) {
            r = c - 1;
        }
        if (arr[c].key < key) {
            l = c + 1;
        }
    }
    if (!fl) return nullptr;
    return &arr[c].value;
}

template<class Key, class Value>
inline bool OrderedOnArray<Key, Value>::Insert(Key key, Value value)
{
    int l = 0, r = count - 1, pos = count;
    int c;
    if (this->IsFull()) {
        return false;
    }
    while (l <= r) {
        c = (r + l) / 2;;
        if (arr[c].key == key) return false;
        if (arr[c].key > key) {
            pos = c;
            r = c - 1;
        }
        if (arr[c].key < key) {
            l = c + 1;
        }
    }
    if (pos == count) {
        arr.push_back({ key, value });
    }
    else {
        arr.insert(arr.begin() + pos, { key, value });
    }
    count++;
    return true;
}

template<class Key, class Value>
inline bool OrderedOnArray<Key, Value>::Delete(Key key)
{
    bool fl = false;
    int l = 0, r = (count - 1);
    int c;
    if (this->IsEmpty()) {
        return false;
    }
    while (l <= r) {
        c = (r + l) / 2;
        if (arr[c].key == key) {
            arr.erase(arr.begin() + c);
            count--;
            return true;
        }
        if (arr[c].key > key) {
            r = c - 1;
        }
        if (arr[c].key < key) {
            l = c + 1;
        }
    }
    return false;
}

template<class Key, class Value>
inline Key OrderedOnArray<Key, Value>::GetKey(void) const
{
    return arr[index].key;
}

template<class Key, class Value>
inline Value OrderedOnArray<Key, Value>::GetValuePtr(void)
{
    return arr[index].value;
}

template<class Key, class Value>
inline void OrderedOnArray<Key, Value>::Reset(void)
{
    index = 0;
}

template<class Key, class Value>
inline bool OrderedOnArray<Key, Value>::IsTabEnded(void)
{
    return index == count;
}

template<class Key, class Value>
inline void OrderedOnArray<Key, Value>::GoNext(void)
{
    if (index == count)
        index = 0;
    else {
        index++;
    }
}
