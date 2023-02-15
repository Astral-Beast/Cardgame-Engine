#ifndef MISC
#define MISC


#include <iostream>
#include <vector>
using namespace std;
string vector_string_formatter(vector<string> list);

struct effect_struct {
        string effect_type;
        int effect_magnitude;
        int effect_likelihood;
        string requires_others;
        string required_conditions;
        string buff_type;// eg damage or accuracy
        string buff_target; // eg damage spells
        string buff_scope; // single card, global
};
string effect_struct_formatter(vector<effect_struct> effect);
bool check_accuracy(float x);


#endif
