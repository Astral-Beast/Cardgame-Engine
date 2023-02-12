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
        string effect_target;
};
string effect_struct_formatter(vector<effect_struct> effect);
bool check_accuracy(float x);


#endif
