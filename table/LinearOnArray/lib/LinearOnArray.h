#include <iostream>
#include "table.h"
#include <vector>
#include <list>
using namespace std;

/*!
* ��������: �������� �.
* ����� LinearOnArray - �������� ������� �� �������
* \param[in] ������� �������� Key - ���� ��� ������
* \param[in] ������� �������� Value - �������� ������
*/
template <class Key, class Value>
class LinerOnArray : public table<Key,Value> {
private:
    vector<Line> array; ///<������ �����

    int index = 0; ///< ������ ���������� ������

public:
    /*!
    * ����� ������ ������ �� �����
    * \param[in] ������� �������� Key - ���� ������
    * \param[out] �������� �������� Value - �������� ������, ���� �� ������ �� nullptr
    */
    Value* Find(Key key) override;

    /*!
    * ����� ���������� ������ � �������
    * \param[in] ������� �������� Key - ���� ������
    * \param[in] ������� �������� value - ������
    * \param[out] �������� �������� bool - true ���� ������� �������� �������
    */
    virtual bool Insert(Key key, Value value) override;

    /*!
    * ����� �������� ������ �� �������
    * \param[in] ������� �������� Key - ���� ������
    * \param[out] �������� �������� bool - true ���� ������� ������ �������
    */
    virtual bool Delete(Key key) override;



    /*!
    * ����� ��������� ����� ���������� ������
    * \param[out] �������� �������� key - ���� ���������� ������
    */
    Key GetKey(void) const override;

    /*!
     * ����� ��������� �������� ���������� ������
    * \param[out] �������� �������� key - �������� ���������� ������
    */
    Value GetValuePtr(void) override;

    /*!
    * ����� ��������� ���������� ������ �� ������ �������
    */
    void Reset(void) override;

    /*!
    * ����� �������� ���������� ������ �� ����� �������
    * \param[out] �������� �������� bool - true ���� ���������� ������ ��������� �� ����� �������
    */
    bool IsTabEnded(void) override;

    /*!
    * ����� ������������ ���������� ������ �� ��������� ������
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
