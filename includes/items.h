
#ifndef ITEMS
#define ITEMS
#include <iostream>
#include <vector>
using namespace std;

class Item
{
public:
    string get_name();

protected:
    string name;
};

class Iron_Dagger : public Item
{
public:
    Iron_Dagger();

};

#endif