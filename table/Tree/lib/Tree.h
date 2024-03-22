#include <iostream>
#include "table.h"
#include <stack>
using namespace std;
/*!
* Выполнила: Соловьева Елизавета
* \param[in] входной параметр Key - ключ для строки
* \param[in] входной параметр Value - значение строки
*/

template <class Key, class Value>
struct Treese {
    Key key; // поле для хранения ключа узла
    Value* value; // указатель на значение узла
    Treese* left, * right; // указатели на левого и правого потомка узла

    Treese(Key key, Value* value, Treese* l, Treese* r) // конструктор структуры, инициализирующий поля узла с переданными значениями
        : key(key), value(value), left(l), right(r) {} // инициализация полей узла значениями из переданных аргументов конструктора
    Treese* GetLeft() const { // метод для получения указателя на левого потомка узла
        return left;
    }
    Treese* GetRight() const { // метод для получения указателя на правого потомка узла
        return right;
    }
};

template <class Key, class Value>
class Tree : public table<Key, Value> {
private:
    Treese<Key, Value>* koren; // указатель на корень дерева
    Treese<Key, Value>** yka; // указатель на указатель
    Treese<Key, Value>* tec; // указатель на текущий узел дерева
    int tecushaya; // переменная для хранения текущей позиции в дереве
    stack<Treese<Key, Value>*> team; // стек, содержащий указатели на узлы дерева


public:
    /*!
    * 1. Поиск элемента по ключу (Find)
    * 2. Вставка нового элемента (Insert)
    * 3. Удаление элемента по ключу (Delete)
    * 4. Получение ключа текущего элемента (GetKey)
    * 5. Получение указателя на значение текущего элемента (GetValuePtr)
    * 6. Сброс текущей позиции в таблице (Reset)
    * 7. Проверка указателя на конец таблицы (IsTabEnded)
    * 8. Переход к следующему элементу в таблице (GoNext)
    * 9. Проверка на полноту дерева (IsFull)
    */

    Value* Find(Key key) override;
    virtual bool Insert(Key key, Value value) override;
    virtual bool Delete(Key key) override;

    Key GetKey(void) const override;
    Value GetValuePtr(void) override;

    void Reset(void) override;
    bool IsTabEnded(void) override;
    void GoNext(void) override;

    Tree() {
        koren = nullptr;
        yka = nullptr;
        tec = nullptr;
        tecushaya = 0;
    }
    ~Tree() {}

};

template<class Key, class Value>
inline Value* Tree<Key, Value>::Find(Key key)
{
    Treese<Key, Value>* see = koren;
    yka = &koren;
    while (see != nullptr) {

        if (see->key == key) break;
        if (see->key < key)
            yka = &see->right;
        else
            yka = &see->left;
        see = *yka;
    }
    if (see == nullptr)
        return nullptr;
    return see->value;
}

template<class Key, class Value>
inline bool Tree<Key, Value>::Insert(Key key, Value value)
{
    if (Find(key) != nullptr) {
        return false;
    }
    Treese<Key, Value>* see = koren;
    Treese<Key, Value>** yka = &koren;

    while (see != nullptr) {

        if (see->key == key) {
            delete see->value;
            see->value = new Value(value);
            return true;
        }

        if (see->key < key) {
            yka = &see->right;
            see = see->right;
        }

        else {
            yka = &see->left;
            see = see->left;
        }
    }
    *yka = new Treese<Key, Value>(key, new Value(value), nullptr, nullptr);
    count++;
}

template<class Key, class Value>
inline bool Tree<Key, Value>::Delete(Key key)
{
    if (koren == nullptr)
        return false;

    if (Find(key) != nullptr) {
        Treese<Key, Value>* see = *yka;

        if (see->left == nullptr && see->right == nullptr) {
            *yka = nullptr;
        }
        else if (see->left == nullptr) {
            *yka = see->right;
        }
        else if (see->right == nullptr) {
            *yka = see->left;
        }
        else {
            Treese<Key, Value>** tmp = &see->left;

            while ((*tmp)->right != nullptr) {
                tmp = &((*tmp)->right);
            }

            see->key = (*tmp)->key;
            delete see->value;
            see->value = (*tmp)->value;
            Treese<Key, Value>* toDelete = *tmp;
            *tmp = (*tmp)->left;
            delete toDelete;
        }
        count--;
    }
    else
        return false;
}

template<class Key, class Value>
inline Key Tree<Key, Value>::GetKey(void) const
{
    if (tec != nullptr) {
        return tec->key;
    }
    else {
        return Key();
    }
}

template<class Key, class Value>
inline Value Tree<Key, Value>::GetValuePtr(void)
{
    if (tec != nullptr) {
        return *(tec->value);
    }
    else {
        return Value();
    }
}

template<class Key, class Value>
inline void Tree<Key, Value>::Reset(void)
{
    Treese<Key, Value>* see = tec = koren;
    while (!team.empty()) team.pop();
    tecushaya = 0;
    while (see != nullptr) {
        team.push(see);
        tec = see;
        see = see->GetLeft();
    }
}

template<class Key, class Value>
inline bool Tree<Key, Value>::IsTabEnded(void)
{
    return tecushaya >= count;
}

template<class Key, class Value>
inline void Tree<Key, Value>::GoNext(void)
{
    team.pop();
    Treese<Key, Value>* see = tec->right;
    while (see && !IsTabEnded()) {
        team.push(see);
        see = see->left;
    }
    if (!team.empty()) {
        tec = team.top();
    }
    else
        tec = nullptr;
    tecushaya++;
}


