#ifndef ENTITIES
#define ENTITIES

#include "cards.hpp"
#include "items.hpp"
#include <iostream>
#include <vector>
using namespace std;

class Entity
{
    // Entities are "Players" in the card game
public:
    // DESCRIPTIONS ::
    string description;
    string bloodied_description;
    string dead_description;
    
    // 
    string name;
    bool alive; // Can be searched for items if alive == false
    int hp;
    int max_hp;
    bool bloodied; // Entity is at less than half health
    vector<Item *> equipment;
    vector<Item *> inventory;
    Deck deck;

    // METHODS ::
    void get_deck();
    void add_item(Item *item);
    void equip_item();
    void change_hp(int x);
    void change_global(int magnitude, string type);
    void describe_health();
    void init();
    
    protected:
    // ATTRIBUTES ::

    // Conditions ::
    int bleed;


    

    // BONUSES ::
};
class Human_Fighter : public Entity
// Human fighter entity.
// Has innate Smash and Bash ability
{
public:
    Human_Fighter();
    ~Human_Fighter();
};

class Vampire : public Entity
{
public:
    Vampire();
};
#endif