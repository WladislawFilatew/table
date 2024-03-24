#include <iostream>
#include "table.h"
using namespace std;



template <class Key, class Value>
class HashList : public table<Key, Value> {
private:

    vector<vector<Line>> vector;

    struct id
    {
        int vector_id = 0;
        int list_id = 0;
        bool end = false;
    } id;
   

public:

    int Hash_func(string key)
    {
        int res = 0;
        for (int i = 0; i < key.length(); i++)
        {
            res += key[i];
        }

        return res;
    }


    Value* Find(Key key) override;
    virtual bool Insert(Key key, Value value) override;
    virtual bool Delete(Key key) override;



    Key GetKey(void) const override;
    Value GetValuePtr(void) override;

    void Reset(void) override;
    bool IsTabEnded(void) override;
    void GoNext(void) override;


};

template <class Key, class Value>
inline Value* HashList<Key, Value>::Find(Key key)
{
    int vector_id = Hash_func(key);
    if (vector_id >= vector.size())
        return nullptr;
    for (int i = 0; i < vector[vector_id].size(); i++)
        if (key == vector[vector_id][i].key)
        {
            return &vector[vector_id][i].value;
        }
    return nullptr;
}

template <class Key, class Value>
inline bool HashList<Key, Value>::Insert(Key _key, Value _value)
{
    int vector_id = Hash_func(_key);
    if (this->IsFull())
        return false;
    if (vector_id >= vector.size())
    {
        vector.resize(vector_id + 1);
        vector[vector_id].push_back({ _key,_value });
    }
    else
    {
        int size = vector[vector_id].size();
        for (int i = 0; i < size; i++)
            if (_key == vector[vector_id][i].key)
                return false;
        vector[vector_id].push_back({ _key,_value });
    }
    count++;
    Reset();
    return true;

}

template <class Key, class Value>
inline bool HashList<Key, Value>::Delete(Key key)
{
    int vector_id = Hash_func(key);

    if (vector_id >= vector.size())
        return false;
    int size = vector[vector_id].size();
    for (int i = 0; i < size; i++)
         if (key == vector[vector_id][i].key) {
             vector[vector_id].erase(vector[vector_id].begin() + i);
             count--;
             Reset();
             return true;
         }
    return false;

}

template<class Key, class Value>
inline Key HashList<Key, Value>::GetKey(void) const
{
    return vector[id.vector_id][id.list_id].key;
}

template<class Key, class Value>
inline Value HashList<Key, Value>::GetValuePtr(void)
{
    return vector[id.vector_id][id.list_id].value;
}

template<class Key, class Value>
inline void HashList<Key, Value>::Reset(void)
{
    int i = 0;
    while (vector.size() > i && vector[i].size() == 0)
        i++;
    if (vector.size() == i) {
        id.end = true;
        return;
    }
    id.vector_id = i;
    id.list_id = 0;
}

template<class Key, class Value>
inline bool HashList<Key, Value>::IsTabEnded(void)
{
    return id.end;
}

template<class Key, class Value>
inline void HashList<Key, Value>::GoNext(void)
{

    if (vector[id.vector_id].size() <= id.list_id + 1)
    {
        int i = id.vector_id + 1;
        while (vector.size() > i && vector[i].size() == 0)
            i++;
        if (vector.size() == i) {
            id.end = true;
            return;
        }
        id.vector_id = i;
        id.list_id = 0;
    }
    else
    {
        id.list_id += 1;
    }
}