#ifndef CARDS
#define CARDS
#include <iostream>
#include <vector>
#include "miscellaneous.hpp"

using namespace std;
class Card
{
protected:
    vector<struct effect_struct> effect;
    int cost;

public:
    string card_name;
    string information_text;
    string flavor_text;
    vector<string> entities_allowed;
    void print_info();
    void update_effect(int magnitude, string type);
    vector<struct effect_struct> cast_spell();
    vector<string> range;
    ~Card();
};

class Smash_and_Bash : public Card
// Standard melee attack card
{
public:
    Smash_and_Bash();
};
class Stab : public Card
// Standard melee attack card
{
public:
    Stab();
};
class Backstab : public Card
{
public:
    Backstab();
};
class Aim_Carefully : public Card
{
public:
    Aim_Carefully();
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