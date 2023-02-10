#ifndef ENTITIES
#define ENTITIES

#include "cards.h"
#include "items.h"
#include <iostream>
#include <vector>
using namespace std;

class Entity
{
    // Entities are "Players" in the card game
public:
    string name;
    string description;
    string bloodied_description;
    string dead_description;
    bool alive; // Can be searched for items if alive == false
    int hp;
    int max_hp;
    bool bloodied; // Entity is at less than half health
    vector<Item *> equipment;
    vector<Item *> inventory;
    Deck deck;
    void get_deck();
    void add_item(Item *item);
    void equip_item();
    void decrease_hp(int x);
    void describe_health();
};
class Human_Fighter : public Entity
// Human fighter entity.
// Has innate Smash and Bash ability
{
public:
    Human_Fighter();
    Human_Fighter(string input_name);
    ~Human_Fighter();
};

class Vampire : public Entity
{
public:
    Vampire();
};
#endif