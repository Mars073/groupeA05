#include "Monster.h"

Monster::Monster(std::string charaName,int maxHp,int hp,int maxMp,int mp,int atk,int mag,int def,int level,int expHeld):BattleCharacter(charaName,maxHp,hp,maxMp,mp,atk,mag,def)
{
    SetcharaType("Monster");
    Setlevel(level);
    this->expHeld=expHeld;
}

Monster::~Monster()
{
   for (unsigned i = 0; i < lootHeld.size(); i++)
    {
        delete lootHeld.at(i);
    }
}

Monster::Monster(const Monster& m):BattleCharacter(m)
{
    SetcharaType("Monster");
    Setlevel(m.Getlevel());
    this->expHeld=m.expHeld;
}

Monster& Monster::operator=(const Monster& m){
    if(this!=&m){
        BattleCharacter::operator=(m);
        for (unsigned i = 0; i < lootHeld.size(); i++)
        {
            delete lootHeld.at(i);
            lootHeld.at(i)=m.GetLootHeld().at(i)->clone();
        }
        SetcharaType("Monster");
        Setlevel(m.Getlevel());
        this->expHeld=m.expHeld;
    }
    return *this;
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
    <<"Exp held : "<<GetexpHeld()<<std::endl
    <<"Items and percentages : "<<std::endl;
    for (unsigned i = 0; i < percentagesItem.size(); i++){
        if (i >= GetLootHeld().size())
        {
            sstr << "Loot range fail" << std::endl;
            break;
        }
        sstr<<GetLootHeld().at(i)->GetitemName()<<" "<<std::to_string(percentagesItem.at(i))<<" %"<<std::endl;
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
    int damage= dmg - Getdef();
    if(damage<0){
        damage=0;
    }
    return damage;
}

Monster* Monster::clone() const
{
    Monster* m=new Monster(GetcharaName(),GetmaxHp(),Gethp(),GetmaxMp(),Getmp(),Getatk(),Getmag(),Getdef(),Getlevel(),GetexpHeld());
    for(unsigned i=0;i<GetLootHeld().size();i++){
        m->addLoot(GetLootHeld().at(i)->clone());
        m->addPercentage(GetPercentagesItem().at(i));
    }
    return m;
}

bool Monster::operator==(const Monster& other) const
{
    return GetcharaName() == other.GetcharaName();
}

std::vector<Item*> Monster::GetLootHeld() const
{
    return lootHeld;
}

void Monster::SetLootHeld(std::vector<Item*> val)
{
    lootHeld = val;
}

void Monster::addLoot(Item* item)
{
    lootHeld.push_back(item);
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

std::vector<Item*> Monster::giveLoot(){
    std::vector<Item*>loot;
    srand(time(NULL));
    for(unsigned i=0;i<percentagesItem.size();i++){
        if(percentagesItem.at(i)>=(rand() % 100 + 0)){
            loot.push_back(lootHeld.at(i));
        }
    }
    return loot;
}

