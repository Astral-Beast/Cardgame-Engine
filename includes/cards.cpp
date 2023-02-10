
#include <iostream>
#include <vector>
#include <string>
#include "miscellaneous.h"
#include "cards.h"

using namespace std;

void Deck::list_deck()
{
    if (this->cards.size() > 0)
    {
        for (auto x : this->cards)
            x->print_info();
    }
    else
    {
        cout << "<<This deck is empty>>\n";
    }
}
void Deck::add_card(Card *c)
{
    this->cards.push_back(c);
}

void Deck::remove_card(int c_index)
{
    // TODO: protect from out of range call
    cout << "Removing " << this->cards[c_index]->card_name << " from the deck\n";

    this->cards[c_index]->~Card();
    cards.erase(this->cards.begin() + c_index);
}

Card::~Card()
{
    delete this;
}

vector<effect_struct> Card::cast_spell()
{
    return this->effect;
}

void Card::print_info()
{
    cout << "*********************"
         << "\n"
         << this->card_name << "\n"
         << "---------------------\n"
         << " Cost: " << this->cost << " Range: " << vector_string_formatter(this->range) << "\n"
         << this->information_text << "\n"
         << this->flavor_text << "\n"
         << "---------------------\n"
         << "Effects: \n"
         << effect_struct_formatter(cast_spell())
         << "---------------------\n"
         << "Characters allowed to use this spell:\n"
         << vector_string_formatter(this->entities_allowed) << "\n"
         << "*********************"
         << "\n";
}

Smash_and_Bash::Smash_and_Bash()
{
    range = {"Melee"};
    effect = {{"Damage", 2, 75.0, "N/A", "N/A"}};
    card_name = "Smash and Bash";
    entities_allowed = vector<string>{"Human", "Orc"};
    flavor_text = "\"Losing control can be effective.\"";
    cost = 1;
    information_text = "Deals two damage to selected opponent per swing";
}

Stab::Stab()
{
    range = {"Melee"};
    effect = {{"Damage", 1, 75.0, "N/A", "N/A"},
              {"Bleed", 2, 14.0, "Damage", "N/A"}};
    card_name = "Stab";
    entities_allowed = vector<string>{"All"};
    flavor_text = "\"A path to a bloody victory.\"";
    cost = 1;
    information_text = "Deals " + to_string(effect[0].effect_magnitude) + " damage to selected opponent per swing";
}

Backstab::Backstab()
{
    range = {"Melee"};
    effect = {{"Damage", 2, 75.0, "N/A", "Unaware"},
              {"Bleed", 2, 34.0, "Damage", "N/A"},
              {"Damage", 1, 75.0, "N/A", "N/A"},
              {"Bleed", 2, 14.0, "Damage", "N/A"}};
    card_name = "Stab";
    entities_allowed = vector<string>{"All"};
    flavor_text = "\"A path to a bloody victory.\"";
    cost = 1;
    information_text = "Deals " + to_string(effect[0].effect_magnitude) + " damage to selected opponent per swing";
}

// void Smash_and_Bash::cast_spell(Entity *target)
//{
//   cout << card_name << " has been cast against " << target->name << "\n";
// target->decrease_hp(2);
// target->describe_health();
//}
