// Problem: Design a game character system using multiple interfaces.

// Requirements:
// Interface Movable with move(), getPosition()
// Interface Attackable with attack(), takeDamage()
// Interface MagicCaster with castSpell(), getMana()

// Create character classes:
// Warrior (Movable, Attackable)
// Mage (Movable, Attackable, MagicCaster)
// Archer (Movable, Attackable)
// Create a game loop that can handle all character types polymorphically


#include<bits/stdc++.h>
using namespace std;
class Movable{
  public:
    virtual void move(int dx,int dy)=0;
    virtual std::pair<int,int> getPosition()=0;

    virtual ~Movable()=default;
  
};
class Attackable{
  public:
    virtual void attack(Attackable& target)=0;
    virtual void takeDamage(int damage)=0;

    virtual ~Attackable()=default;
};
class MagicCaster{
  public:
    virtual void castSpell(Attackable& target)=0;
    virtual int getMana()=0;

    virtual ~MagicCaster()=default;
};

class Character: public Movable,public Attackable{
  protected:
    int x{0},y{0};
    int health{100};
  public:
    void move(int dx,int dy)override{
      x+=dx;
      y+=dy;
      std::cout<<"Move to"<<x<<" "<<y<<endl;
    }
    void takeDamage(int amount) override {
        health -= amount;
        std::cout << "Took " << amount
                  << " damage. Health = " << health << "\n";
    }

    bool isAlive() const {
        return health > 0;
    }

    virtual ~Character() = default;
};


class Warrior : public Character {
public:
    void attack(Attackable& target) override {
        std::cout << "Warrior attacks with sword!\n";
        target.takeDamage(15);
    }
};
class Mage : public Character, public MagicCaster {
private:
    int mana{50};

public:
    void attack(Attackable& target) override {
        std::cout << "Mage attacks with staff!\n";
        target.takeDamage(10);
    }

    void castSpell(Attackable& target) override {
        if (mana >= 10) {
            mana -= 10;
            std::cout << "Mage casts Fireball! Mana = "
                      << mana << "\n";
            target.takeDamage(25);
        } else {
            std::cout << "Not enough mana!\n";
        }
    }

    int getMana() override {
        return mana;
    }
};
class Archer : public Character {
public:
    void attack(Attackable& target) override {
        std::cout << "Archer shoots an arrow!\n";
        target.takeDamage(12);
    }
};
#include <vector>
#include <memory>

int main() {
    std::vector<std::unique_ptr<Character>> characters;

    characters.push_back(std::make_unique<Warrior>());
    characters.push_back(std::make_unique<Mage>());
    characters.push_back(std::make_unique<Archer>());

    // Move all characters
    for (auto& c : characters) {
        c->move(1, 1);
    }

    std::cout << "------------------\n";

    // Everyone attacks the next character
    for (size_t i = 0; i < characters.size(); ++i) {
        auto& attacker = characters[i];
        auto& target =
            characters[(i + 1) % characters.size()];

        attacker->attack(*target);
    }

    std::cout << "------------------\n";

    // Magic users cast spells (runtime check)
    for (auto& c : characters) {
        if (auto* mage = dynamic_cast<MagicCaster*>(c.get())) {
            mage->castSpell(*characters[0]);
        }
    }

    return 0;
}
