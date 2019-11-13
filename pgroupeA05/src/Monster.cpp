#include "Monster.h"

Monster::Monster(std::string charaName,int maxHp,int hp,int maxMp,int mp,int atk,int mag,int def,int level,int moneyHeld,int expHeld):BattleCharacter(charaName,maxHp,hp,maxMp,mp,atk,mag,def)
{
    charaType="Monster";
    this->level=level;
    this->moneyHeld=moneyHeld;
    this->expHeld=expHeld;
    this->inventory=new Inventory();
}

Monster::~Monster()
{
    delete inventory;
}

Monster::Monster(const Monster& m):BattleCharacter(m)
{
    charaType="Monster";
    this->level=m.level;
    this->moneyHeld=m.moneyHeld;
    this->expHeld=m.expHeld;
    this->inventory=new Inventory(*m.inventory);
}

Monster& Monster::operator=(const Monster& m){
    if(this!=&m){
        charaType="Monster";
        this->level=m.level;
        this->moneyHeld=m.moneyHeld;
        this->expHeld=m.expHeld;
        delete inventory;
        this->inventory=new Inventory(*m.inventory);
    }
    return *this;
}

int Monster::GetmoneyHeld() const
{
    return moneyHeld;
}

void Monster::SetmoneyHeld(int val)
{
    moneyHeld = val;
}

int Monster::GetexpHeld() const
{
    return expHeld;
}

void Monster::SetexpHeld(int val)
{
    expHeld = val;
}

std::string Monster::str() const
{
    std::stringstream sstr;
    sstr<<BattleCharacter::str()<<std::endl
    <<"Money held : "<<GetmoneyHeld()<<std::endl
    <<"Exp held : "<<GetexpHeld()<<std::endl
    <<"Items and percentages : "<<std::endl;
    for (unsigned i = 0; i < percentagesItem.size(); i++){
        sstr<<Getinventory()->Getbag()[i]->GetitemName()<<" "<<std::to_string(percentagesItem[i])<<" %"<<std::endl;
    }
    return sstr.str();
}

int Monster::damageDone() const
{
    return Getatk();
}

void Monster::damageReceived(int dmg)
{
    int damage= dmg - Getdef();
    if(damage>0){
        Sethp(Gethp()-damage);
        if(Gethp()<0){
            Sethp(0);
        }
    }
}

int Monster::showDamageReceived(int dmg)
{
    return dmg - Getdef();

}

Monster* Monster::clone() const
{
    Monster* m=new Monster(GetcharaName(),GetmaxHp(),Gethp(),GetmaxMp(),Getmp(),Getatk(),Getmag(),Getdef(),Getlevel(),GetmoneyHeld(),GetexpHeld());
    m->Setinventory(Getinventory());
    m->SetPercentagesItem(GetPercentagesItem());
    return m;
}

bool Monster::operator==(const Monster& other) const
{
    return charaName == other.GetcharaName();
}

Inventory* Monster::Getinventory() const
{
    return inventory;
}

void Monster::Setinventory(Inventory* val)
{
    inventory = val;
}

std::vector<int> Monster::GetPercentagesItem() const
{
    return percentagesItem;
}

void Monster::SetPercentagesItem(std::vector<int> val)
{
    percentagesItem = val;
}

void Monster::addPercentage(int nb)
{
    percentagesItem.push_back(nb);
}

