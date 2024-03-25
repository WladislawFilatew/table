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
