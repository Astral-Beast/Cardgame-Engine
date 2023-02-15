#include <iostream>
#include "items.hpp"
using namespace std;

string Item::get_name()
{
    return this->name;
}

Iron_Dagger::Iron_Dagger()
{
    name = "Iron Dagger";
}