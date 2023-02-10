#ifndef CARDS
#define CARDS
#include <iostream>
#include <vector>
#include "miscellaneous.h"

using namespace std;
class Card
{
protected:
    int damage;
    vector<struct effect_struct> effect;

public:
    Card();
    string card_name;
    string owner;
    int cost;
    string information_text;
    string flavor_text;
    vector<string> entities_allowed;
    // virtual void cast_spell(Entity *target) = 0;
    void print_info();
    vector<struct effect_struct> cast_spell();
    vector<string> range;
    ~Card();
};

class Smash_and_Bash : public Card
// Standard melee attack card
{
public:
    Smash_and_Bash();
    Smash_and_Bash(string named_owner);
    
};
class Deck
{
public:
    vector<Card *> cards;
    void list_deck();
    void add_card(Card *c);

    void remove_card(int c_index);
};

#endif