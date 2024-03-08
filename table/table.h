#pragma once
#include "TPolinom.h"
#include <vector>
using namespace std;

/*!
* ��������: �������� �.
* ����� table - ��������� ����� ��� �������� ������
* \param[in] ������� �������� Key - ���� ��� ������
* \param[in] ������� �������� Value - �������� ������
*/
template <class Key, class Value>
class table{
protected:
    int count = 0; ///< ��������� ����� � �������

    /*!
    * ��������� ��� �������� ������ �������
    * Key - ���� ��� ������
    * Value - �������� ������
    */
    struct Line
    {
        Key key;
        Value value;
    };

    int MaxSize = 10000; ///< ������������ ����� ����� � �������
public:
    
    /*!
    * ����� ���������� ���������� ����� � �������
    * \param[out] �������� �������� int - ���������� �����
    */
    int Count();

    /*!
    * ����� ���������� ������ �� �������
    * \param[out] �������� �������� bool - true ���� ������� �����
    */
    bool IsEmpty() const;

    /*!
    * ����� ���������� ��������� �� �������
    * \param[out] �������� �������� bool - true ���� ������� ���������
    */
    bool IsFull();

    /*!
    * ����� ������ ������ �� �����
    * \param[in] ������� �������� Key - ���� ������
    * \param[out] �������� �������� Value - �������� ������, ���� �� ������ �� nullptr
    */
    virtual Value* Find(Key key) = 0;

    /*!
   * ����� ���������� ������ � �������
   * \param[in] ������� �������� Key - ���� ������
   * \param[in] ������� �������� value - ������
   * \param[out] �������� �������� bool - true ���� ������� �������� �������
   */
    virtual bool Insert(Key key, Value value) = 0;

    /*!
    * ����� �������� ������ �� �������
    * \param[in] ������� �������� Key - ���� ������
    * \param[out] �������� �������� bool - true ���� ������� ������ �������
    */
    virtual bool Delete(Key key) = 0;



    /*!
    * ����� ��������� ����� ���������� ������
    * \param[out] �������� �������� key - ���� ���������� ������
    */
    virtual Key GetKey(void) const = 0;

    /*!
    * ����� ��������� �������� ���������� ������
    * \param[out] �������� �������� key - �������� ���������� ������
    */
    virtual Value GetValuePtr(void) = 0;

    /*!
    * ����� ��������� ���������� ������ �� ������ �������
    */
    virtual void Reset(void) = 0;

    /*!
    * ����� �������� ���������� ������ �� ����� �������
    * \param[out] �������� �������� bool - true ���� ���������� ������ ��������� �� ����� �������
    */
    virtual bool IsTabEnded(void) = 0;

    /*!
    * ����� ������������ ���������� ������ �� ��������� ������
    */
    virtual void GoNext(void) = 0;


    /*!
    * ����� ������ ������� � �������
    */
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
