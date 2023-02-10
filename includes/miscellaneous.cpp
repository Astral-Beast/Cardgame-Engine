#include <iostream>
#include <vector>
#include "miscellaneous.h"
#include <string>
using namespace std;

string effect_struct_formatter(vector<effect_struct> effect){
    string temp ="";
    for (auto i= effect.begin(); i != effect.end();i++){
        temp=temp+"{ Effect Type : "+i->effect_type
        + ", Effect Magnitude: "+to_string(i->effect_magnitude)
        + ", Chance of Success: "+ to_string(i->effect_likelihood)
        + "%}\n";
    }
    return temp;

}

string vector_string_formatter(vector<string> list)
{
    // vectors of strings are formatted for cout printing
    string temp = "{ ";
    if (list.size() > 1)
    {
        for (auto i = list.begin(); i != list.end(); i++)
        {
            temp = temp.append(*i);
            if (i != list.end() - 1)
            {
                temp.append(", ");
            }
        }
    }
    else
    {
        temp.append(list[0]);
    }
    temp.append(" }");
    return temp;
}
