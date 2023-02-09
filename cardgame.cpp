#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

string vector_string_formatter(vector<string> list)
{
    // vectors of strings are formatted for cout printing
    string temp = "{ ";
    if (list.size() > 1)
    {
        for (auto i = list.begin(); i != list.end(); i++)
        {
            temp = temp.append(*i);
            if (i != list.end() - 1)
            {
                temp.append(", ");
            }
        }
    }
    else
    {
        temp.append(list[0]);
    }
    temp.append(" }");
    return temp;
}

class Item
{
public:
    string get_name()
    {
        return this->name;
    }

protected:
    string name = "";
};
class Iron_Dagger : public Item
{
public:
    Iron_Dagger()
    {
        name = "Iron Dagger";
    }
};

class Card
{
public:
    string card_name = "";
    string owner;
    int cost = 0;
    string information_text = "";
    string flavor_text = "";
    vector<string> entities_allowed;
    // virtual void cast_spell(Entity *target) = 0;
    virtual void print_info() = 0;
    vector<string> range = {""};

    void delete_card()
    {
        delete this;
    }
};

class Deck
{
public:
    vector<Card *> cards;
    void list_deck()
    {
        if (cards.size() > 0)
        {
            for (auto x : cards)
                x->print_info();
        }
        else
        {
            cout << "<<This deck is empty>>\n";
        }
    }

    void add_card(Card *c)
    {
        cards.push_back(c);
    }
    void remove_card(int c_index)
    {
        // TODO: protect from out of range call
        cout << "Removing " << cards[c_index]->card_name << " from the deck\n";

        cards[c_index]->delete_card();
        cards.erase(cards.begin() + c_index);
    }
};
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
    void get_deck()
    // Lists the cards in an entities Deck.
    {
        cout << name << "'s Deck:\n";
        this->deck.list_deck();
    }
    void add_item(Item *item)
    {
        inventory.push_back(item);
    }
    void equip_item()
    {
    }
    void decrease_hp(int x)
    {
        hp = hp - x;
        if (hp < 0)
        {
            this->alive = false;
        }
        else if (hp < max_hp / 2)
        {
            bloodied = true;
        }
    }
    void describe_health()
    {
        if (this->alive){
        cout << name << " has " << this->hp << " health.\n";
        if (this->bloodied){
            cout << this->bloodied_description;
        }
        }
        else{
            cout << this->dead_description;
        }
    }
};
class Smash_and_Bash : public Card
// Standard melee attack card
{
private:
    int damage;

public:
    Smash_and_Bash()
    {
        range = {"Melee"};
        this->damage = 2;
        card_name = "Smash and Bash";
        owner = "Player";
        entities_allowed = vector<string>{"Human", "Orc"};
        flavor_text = "\"Losing control can be effective.\"";
        cost = 1;
        information_text = "Deals two damage to selected opponent per swing";
    }
    Smash_and_Bash(string named_owner)
    {
        this->damage = 2;
        range = {"Melee"};
        card_name = "Smash and Bash";
        owner = named_owner;
        entities_allowed = {"Human", "Orc"};
        flavor_text = "\"Losing control can be effective.\"";
        cost = 1;
        information_text = "Deals two damage to selected opponent per swing";
    }
    ~Smash_and_Bash()
    {
        cout << "Smash and bash destructed";
    }
    void cast_spell(Entity *target)
    {
        cout << card_name << " has been cast against " << target->name << "\n";
        target->decrease_hp(2);
        target->describe_health();
    }
    void print_info()
    {
        cout << "*********************"
             << "\n"
             << card_name << "\n"
             << "---------------------\n"
             << "Owned by: " << owner
             << " Cost: " << cost << " Range: " << vector_string_formatter(range) << "\n"
             << information_text << "\n"
             << flavor_text << "\n"
             << "---------------------\n"
             << "Effects: \n"
             << "Deals " << damage << " Damage.\n"
             << "---------------------\n"
             << "Characters allowed to use this spell:\n"
             << vector_string_formatter(entities_allowed) << "\n"
             << "*********************"
             << "\n";
    }
};

class Scene
// Scenes are locations in the game world which may have
// Enemies or Items.
{
protected:
    string area_description;
    vector<Entity *> enemies;
    vector<Item *> items;
    string describe_enemies()
    {
        string temp = "There ";
        if (this->enemies.size() == 1)
        {
            temp.append("is ");
            temp.append(this->enemies[0]->description);
            if (this->enemies[0]->bloodied)
            {
                temp.append(this->enemies[0]->bloodied_description);
            }
        }
        else if (this->enemies.size() == 2)
        {
            temp.append("are ");
            temp.append(this->enemies[0]->description);
            temp.append(" and ");
            temp.append(this->enemies[1]->description);
        }
        else if (this->enemies.size()>2)
        {
            temp.append("are ");
            for (auto i = enemies.begin(); i != enemies.end(); i++)
            {
                if (i == enemies.end())
                {
                    temp.append(" and ");
                }
                temp.append((*i)->description);
                if (i != enemies.end() - 1)
                {
                    temp.append(", ");
                }
            }
        }
        
        temp.append(" nearby.\n");
        for (auto i = enemies.begin(); i != enemies.end(); i++){
            if ((*i)->bloodied){
                temp = temp + " " +(*i)->bloodied_description;
            }
        }
        return temp;
    }

public:
    void stock_enemies(Entity *entity)
    // Adds entities to the scene
    {
        this->enemies.push_back(entity);
    }
    void stock_items(Item *item)
    // Adds items to the scene
    {
        this->items.push_back(item);
    }
    void describe_scene()
    // Describes scene visually including background, objects, and enemies.
    {

        cout << area_description;
        cout << describe_enemies();
    }

};
class Area_One : public Scene
{
public:
    Area_One()
    {
        this->area_description = "The wide boulevard you woke up on passes between the mammoth buildings around you and strikes out deeper into the city.\n\nToward the center of this great dome the buildings spiral upward and grow grander and more magnificent as they reach for the sky. \n\nWhether those buildings are organic in origin or attempts at replicating the aesthetic of nature is unclear from this far away, but something that's certain is that you've never known any plant or other building material which could hold such massive structures on such spindly legs as some of those central buildings.\n\n\n";
    }
};

class Game_Master
{
private:
    Entity *player;
    vector<Entity *> enemy;
    Scene scene;

public:
    void load_scene(Scene *location)
    {
        location->describe_scene();
    }
};

class Human_Fighter : public Entity
// Human fighter entity.
// Has innate Smash and Bash ability
{
public:
    Human_Fighter()
    {
        description = "a Human fighter";
        dead_description = "The Human fighter's corpse is crumpled unceremoniously on the ground.";
        bloodied_description = "The Human fighter's eyes are glazed from pain and his feral look has been replaced with one of fear.\n";
        hp = 10;
        max_hp = 10;
        deck = Deck();
        Smash_and_Bash *smash = new Smash_and_Bash;
        deck.add_card(smash);
    }
    Human_Fighter(string input_name)
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

    ~Human_Fighter()
    {
        // delete smash;
        cout << "destructor executed\n";
    }
};

class Vampire : public Entity
{
public:
    Vampire()
    {
        description = "a pallid Vampire";
        bloodied_description = "The Vampire's face is contorted with a mixture of rage and fear.\n";
        name = "Marceline";
        hp = 15;
        max_hp = 15;
    }
};

void test_basic_functions()
{
    Vampire v = Vampire();
    Vampire *vp = &v;
    Game_Master gm = Game_Master();
    Scene a = Area_One();
    a.stock_enemies(vp);
    gm.load_scene(&a);
    Human_Fighter hf = Human_Fighter("Finn");
    a.stock_enemies(&hf);
    gm.load_scene(&a);
    hf.get_deck();
    Smash_and_Bash *smash = dynamic_cast<Smash_and_Bash *>(hf.deck.cards[0]);
    smash->cast_spell(vp);
    v.decrease_hp(7);
    smash->cast_spell(vp);
    a.describe_scene();
    hf.deck.remove_card(0);
    hf.get_deck();
}

int main()
{
    test_basic_functions();
}