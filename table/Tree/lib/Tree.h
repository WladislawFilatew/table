#include <iostream>
#include "table.h"
#include <stack>
using namespace std;
/*!
* ���������: ��������� ���������
* \param[in] ������� �������� Key - ���� ��� ������
* \param[in] ������� �������� Value - �������� ������
*/

template <class Key, class Value>
struct Treese {
    Key key; // ���� ��� �������� ����� ����
    Value* value; // ��������� �� �������� ����
    Treese* left, * right; // ��������� �� ������ � ������� ������� ����

    Treese(Key key, Value* value, Treese* l, Treese* r) // ����������� ���������, ���������������� ���� ���� � ����������� ����������
        : key(key), value(value), left(l), right(r) {} // ������������� ����� ���� ���������� �� ���������� ���������� ������������
    Treese* GetLeft() const { // ����� ��� ��������� ��������� �� ������ ������� ����
        return left;
    }
    Treese* GetRight() const { // ����� ��� ��������� ��������� �� ������� ������� ����
        return right;
    }
};

template <class Key, class Value>
class Tree : public table<Key, Value> {
private:
    Treese<Key, Value>* koren; // ��������� �� ������ ������
    Treese<Key, Value>** yka; // ��������� �� ���������
    Treese<Key, Value>* tec; // ��������� �� ������� ���� ������
    int tecushaya; // ���������� ��� �������� ������� ������� � ������
    stack<Treese<Key, Value>*> team; // ����, ���������� ��������� �� ���� ������


public:
    /*!
    * 1. ����� �������� �� ����� (Find)
    * 2. ������� ������ �������� (Insert)
    * 3. �������� �������� �� ����� (Delete)
    * 4. ��������� ����� �������� �������� (GetKey)
    * 5. ��������� ��������� �� �������� �������� �������� (GetValuePtr)
    * 6. ����� ������� ������� � ������� (Reset)
    * 7. �������� ��������� �� ����� ������� (IsTabEnded)
    * 8. ������� � ���������� �������� � ������� (GoNext)
    * 9. �������� �� ������� ������ (IsFull)
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


