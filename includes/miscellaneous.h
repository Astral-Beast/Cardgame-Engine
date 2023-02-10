#ifndef MISC
#define MISC

#include <iostream>
#include <vector>
using namespace std;
string vector_string_formatter(vector<string> list);

struct effect_struct {
        string effect_type;
        int effect_magnitude;
        float effect_likelihood;
};
string effect_struct_formatter(vector<effect_struct> effect);



#endif
