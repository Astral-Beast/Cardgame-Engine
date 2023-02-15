#include <iostream>
#include <vector>
#include "miscellaneous.h"
#include <string>
using namespace std;

string effect_struct_formatter(vector<effect_struct> effect){
    /// @brief Makes effect struct a readable vector
    /// @param effect --- A card's effect vector
    /// @return formatted string for printing a card's effect
    string temp ="";
    for (auto i= effect.begin(); i != effect.end();i++){
        temp=temp+"{ Effect Type : "+i->effect_type
        + ", Effect Magnitude: "+to_string(i->effect_magnitude)
        + ", Chance of Success: "+ to_string(i->effect_likelihood)
        + "%, Required Effect: \""+i->requires_others
        + "\" Required Conditions: \""+ i->required_conditions + "\" \n"
        + "Buff Type: \""+i->buff_type+"\", Applicable Card Types: \""+ i->buff_target+ "\" }\n";
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

bool check_accuracy(float x){
    int calc = rand() % 100;
    if (x >= calc){
        cout <<"True: "<<calc<< " <= " <<x<<"\n";
        return true;
    }
    else{
        cout <<"False: "<<calc<< " > " <<x<<"\n";
        return false;
    }
}