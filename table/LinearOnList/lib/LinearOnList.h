#include <iostream>
#include "table.h"
#include <vector>
using namespace std;

/*!
* Выполнил: Филатьев В.
* класс LinearOnList - линейная таблица на списке
* \param[in] входной параметр Key - ключ для строки
* \param[in] входной параметр Value - значение строки
*/
template <class Key, class Value>
class LinerOnList : public table<Key, Value> {
private:
    
    List<Line> array; ///< Список строк
    Node<Line>* node; ///< Указатель на активную строку
    

public:
    /*!
    * Конструктор
    */
    LinerOnList() {
        node = array.begin();
    };

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
inline Value* LinerOnList<Key, Value>::Find(Key key)
{
    List<Line>::iterator it;
    it = array.begin();
    while (it != array.end()) {
        if ((*it).key == key) {
            return &(*it).value;
        }
        it++;
    }
    return nullptr;
}

template<class Key, class Value>
inline bool LinerOnList<Key, Value>::Insert(Key key, Value value)
{
    if (this->IsFull())
        return false;
    if (Find(key) == nullptr) {
        array.push_back({ key,value });
        count++;
        return true;
    }
    return false;
}

template<class Key, class Value>
inline bool LinerOnList<Key, Value>::Delete(Key key)
{
    if (IsEmpty())
        return false;
    List<Line>::iterator it;
    it = array.begin();
    while (it != array.end()) {
        if ((*it).key == key) {
            array.erase(it);
            count--;
            return true;
        }
        it++;
    }
    return false;
}

template<class Key, class Value>
inline Key LinerOnList<Key, Value>::GetKey(void) const
{
    return (node->value).key;
}

template<class Key, class Value>
inline Value LinerOnList<Key, Value>::GetValuePtr(void)
{
    return (node->value).value;
}

template<class Key, class Value>
inline void LinerOnList<Key, Value>::Reset(void)
{
    node = array.begin();
}

template<class Key, class Value>
inline bool LinerOnList<Key, Value>::IsTabEnded(void)
{
    return node == array.end();
}

template<class Key, class Value>
inline void LinerOnList<Key, Value>::GoNext(void)
{
    if (IsTabEnded())
        Reset();
    node = node->pNext;
}
