#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <string>

class Dictionary
{
protected:
    Dictionary(std::string name) : name(name) { }

public:
    std::string name;

    virtual void insert(int n)   = 0;
    virtual bool contains(int n) = 0;
    virtual void onAllInserted() {}
};

#endif // DICTIONARY_H
