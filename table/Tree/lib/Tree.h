#include <iostream>
#include "table.h"
using namespace std;



template <class Key, class Value>
class Tree : public table<Key, Value> {
private:



public:

    Value* Find(Key key) override;
    virtual bool Insert(Key key, Value value) override;
    virtual bool Delete(Key key) override;



    Key GetKey(void) const override;
    Value GetValuePtr(void) override;

    void Reset(void) override;
    bool IsTabEnded(void) override;
    void GoNext(void) override;


};
