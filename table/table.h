#pragma once
#include "TPolinom.h"
#include <vector>
using namespace std;


template <class Key, class Value>
class table{
protected:
    int count = 0;
    struct Line
    {
        Key key;
        Value value;
    };
    int MaxSize = 10000;
public:
    // информационные методы
    int Count(); // количество записей
    bool IsEmpty() const;  // пуста?


    bool IsFull();                       // заполнена?



    // основные методы
    virtual Value* Find(Key key) = 0;         // найти запись
    virtual bool Insert(Key key, Value value) = 0; // вставить
    virtual bool Delete(Key key) = 0;         // удалить запись



    //// доступ
    virtual Key GetKey(void) const = 0;
    virtual Value GetValuePtr(void) = 0;


   

    // навигация
    virtual void Reset(void) = 0; // установить на первую запись
    virtual bool IsTabEnded(void) = 0; // таблица завершена?
    virtual void GoNext(void) = 0; // переход к следующей записи


    //Печать
    friend ostream& operator<<(ostream& os, table& tab)
    {
        cout << "Table printing" << endl;
        for (tab.Reset(); !tab.IsTabEnded(); tab.GoNext())
        {
            os << " Key: " << tab.GetKey() << " Val: " << tab.GetValuePtr() << endl;
        }
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
