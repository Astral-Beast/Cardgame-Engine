#ifndef MISC
#define MISC


#include <iostream>
#include <vector>
using namespace std;
string vector_string_formatter(vector<string> list);

struct condition_struct {
     string effect_type;
     int effect_duration;
    };
struct effect_struct {
        string effect_type; 
        int effect_magnitude; 
        int effect_likelihood; // Percent likelihood that the effect will be applied
        string requires_others; // States that a previous effect must have been activated successfully
        string required_conditions;// Required target conditions to activate (i.e damage for bleed effect)
        string buff_type;// eg damage or accuracy
        string buff_target; // eg damage spells
        string buff_scope; // single card, global
        int duration; // rounds/ticks
        bool fallback_effect; // effect that occurs if a previous one fails
};
string effect_struct_formatter(vector<effect_struct> effect);
bool check_accuracy(float x);


#endif
