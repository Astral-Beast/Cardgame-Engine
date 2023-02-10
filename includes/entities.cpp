#include "items.h"
#include "cards.h"
#include "entities.h"

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
void Entity::decrease_hp(int x)
{
    cout << "Decrease health called\n"<<x;
    hp = hp - x;
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

Human_Fighter::Human_Fighter()
    {
        description = "a Human fighter";
        dead_description = "The Human fighter's corpse is crumpled unceremoniously on the ground.";
        bloodied_description = "The Human fighter's eyes are glazed from pain and his feral look has been replaced with one of fear.\n";
        hp = 10;
        max_hp = 10;
        this->deck = Deck();
        Smash_and_Bash *smash = new Smash_and_Bash;
        this->deck.add_card(smash);
        bloodied=false;
    }

Human_Fighter::Human_Fighter(string input_name)
    {
        description = "a Human fighter";
        bloodied_description = input_name + "'s eyes are glazed from pain and his feral look has been replaced with one of fear.\n";
        hp = 10;
        max_hp = 10;
        deck = Deck();
        name = input_name;
        cout << name << "\n";
        Smash_and_Bash *smash = new Smash_and_Bash(name);
        deck.add_card(smash);
    }

Human_Fighter::~Human_Fighter()
    {
        // delete smash;
        cout << "destructor executed\n";
        delete this;
    }

Vampire::Vampire()
    {
        this->description = "a pallid Vampire";
        this->bloodied_description = "The Vampire's face is contorted with a mixture of rage and fear.\n";
        this->name = "Marceline";
        this->hp = 15;
        this->max_hp = 15;
    }