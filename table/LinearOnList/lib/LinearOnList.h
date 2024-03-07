#include <iostream>
#include "table.h"
#include <vector>
using namespace std;



template <class Key, class Value>
class LinerOnList : public table<Key, Value> {
private:
    
    List<Line> array;
    Node<Line>* node;

public:
    LinerOnList() {
        node = array.begin();
    };
    Value* Find(Key key) override;
    virtual bool Insert(Key key, Value value) override;
    virtual bool Delete(Key key) override;



    Key GetKey(void) const override;
    Value GetValuePtr(void) override;

    void Reset(void) override;
    bool IsTabEnded(void) override;
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
