#pragma once
#include "TPolinom.h"
#include <vector>
using namespace std;

/*!
* Выполнил: Филатьев В.
* класс table - шаблонный класс для описания таблиц
* \param[in] входной параметр Key - ключ для строки
* \param[in] входной параметр Value - значение строки
*/
template <class Key, class Value>
class table{
protected:
    int count = 0; ///< Колчество строк в таблице

    /*!
    * Структура для описание строки таблицы
    * Key - ключ для строки
    * Value - значение строки
    */
    struct Line
    {
        Key key;
        Value value;
    };

    int MaxSize = 10000; ///< Максимальное число строк в таблице
public:
    
    /*!
    * Метод возврашает количество строк в таблице
    * \param[out] выходной параметр int - количество строк
    */
    int Count();

    /*!
    * Метод определяет пустая ли таблица
    * \param[out] выходной параметр bool - true если таблица пуста
    */
    bool IsEmpty() const;

    /*!
    * Метод определяет заполнена ли таблица
    * \param[out] выходной параметр bool - true если таблица заполнена
    */
    bool IsFull();

    /*!
    * Метод поиска строкм по ключу
    * \param[in] входной параметр Key - ключ строки
    * \param[out] выходной параметр Value - значение строки, если не найден то nullptr
    */
    virtual Value* Find(Key key) = 0;

    /*!
   * Метод добавление записи в таблицу
   * \param[in] входной параметр Key - ключ строки
   * \param[in] входной параметр value - запись
   * \param[out] выходной параметр bool - true если элемент добавлен успешно
   */
    virtual bool Insert(Key key, Value value) = 0;

    /*!
    * Метод удаления записи из таблицы
    * \param[in] входной параметр Key - ключ строки
    * \param[out] выходной параметр bool - true если элемент удален успешно
    */
    virtual bool Delete(Key key) = 0;



    /*!
    * Метод получения ключа актуальной записи
    * \param[out] выходной параметр key - ключ актуальной записи
    */
    virtual Key GetKey(void) const = 0;

    /*!
    * Метод получения значение актуальной записи
    * \param[out] выходной параметр key - значение актуальной записи
    */
    virtual Value GetValuePtr(void) = 0;

    /*!
    * Метод установки актуальной записи на начало таблицы
    */
    virtual void Reset(void) = 0;

    /*!
    * Метод проверки актуальной записи на конец таблицы
    * \param[out] выходной параметр bool - true если актуальная запись указывает на конец таблицы
    */
    virtual bool IsTabEnded(void) = 0;

    /*!
    * Метод перестановки актуальной записи на следующую строку
    */
    virtual void GoNext(void) = 0;


    /*!
    * Метод печати таблицы в консоле
    */
    friend ostream& operator<<(ostream& os, table& tab)
    {
        cout << "Table printing" << endl;
        int key_lenght = 0;
        int value_lenght = 0;

        for (tab.Reset(); !tab.IsTabEnded(); tab.GoNext())
        {
            if (tab.GetKey().size() >= key_lenght)
                key_lenght = tab.GetKey().size();
            if (tab.GetValuePtr().ToString().size() >= value_lenght)
                value_lenght = tab.GetValuePtr().ToString().size();
        }
        for (int i = 0; i < key_lenght + value_lenght + 17;i++) {
            os << "-";
        }
        os << "\n";

        for (tab.Reset(); !tab.IsTabEnded(); tab.GoNext())
        {
            os << "| Key: ";
            os.setf(ios::left);
            os.width(key_lenght);
            os << tab.GetKey();
            os << " | Val: ";
            os.width(value_lenght);
            os << tab.GetValuePtr().ToString() << " |" << endl;
        }
        for (int i = 0; i < key_lenght + value_lenght + 17; i++) {
            os << "-";
        }
        os << "\n";
        return os;
    }

};









template<class Key, class Value>
int table<Key, Value>::Count()
{
    return count;
}

template<class Key, class Value>
bool table<Key, Value>::IsEmpty() const
{
    return count == 0;
}

template<class Key, class Value>
inline bool table<Key, Value>::IsFull()
{
    return count == MaxSize;
}
