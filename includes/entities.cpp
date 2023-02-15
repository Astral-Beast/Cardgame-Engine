#include "items.hpp"
#include "cards.hpp"
#include "entities.hpp"

using namespace std;


void Entity::describe_health()
{
    if (this->alive)
    {
        cout << name << " has " << this->hp << " health.\n";
        if (this->bloodied)
        {
            cout << this->bloodied_description;
        }
    }
    else
    {
        cout << this->dead_description;
    }
}
void Entity::change_hp(int x)
{
    cout << "Change health called ( " << x<< " )\n";
    hp = hp + x;
    if (hp < 0)
    {
        this->alive = false;
        cout<<this->name +" has died.\n";
    }
    else if (hp < max_hp / 2)
    {
        bloodied = true;
        cout<<this->name +" has been bloodied.\n";
    }
}

void Entity::change_global(int magnitude, string type)
{
    for (auto i = this->deck.cards.begin(); i != this->deck.cards.end(); i++){
        (*i)->update_effect(magnitude, type);
    }
}

void Entity::get_deck()
// Lists the cards in an entities Deck.
{
    cout << name << "'s Deck:\n";
    deck.list_deck();
}
void Entity::equip_item()
{
}
void Entity::add_item(Item *item)
{
    this->inventory.push_back(item);
}

void Entity::init(){
    this->hp=max_hp;
}

Human_Fighter::Human_Fighter()
// Human fighter enemy
    {
        name = "A human fighter";
        description = "a Human fighter";
        dead_description = "The Human fighter's corpse is crumpled unceremoniously on the ground.";
        bloodied_description = "The Human fighter's eyes are glazed from pain and his feral look has been replaced with one of fear.\n";
        hp = 10;
        max_hp = 10;
        this->deck = Deck();
        Smash_and_Bash *smash = new Smash_and_Bash;
        this->deck.add_card(smash);
        bloodied=false;
        Stab *stab = new Stab();
        Backstab *bs = new Backstab();
        Aim_Carefully *ac = new Aim_Carefully();
        deck.add_card(bs);
        deck.add_card(stab);
        deck.add_card(ac);
    }


Human_Fighter::~Human_Fighter()
    {
        // delete smash;
        cout << "destructor executed\n";
        delete this;
    }

Vampire::Vampire()
// Vampire enemy
    {
        this->description = "a pallid Vampire";
        this->bloodied_description = "The Vampire's face is contorted with a mixture of rage and fear.\n";
        this->name = "The Vampire";
        this->hp = 15;
        this->max_hp = 15;
    }