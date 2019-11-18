#include "Player.h"
//ajouter max hp et mp et reparer armor et weapon
Player::Player(std::string charaName,int maxHp,int hp,int maxMp,int mp,int atk,int mag,int def)
:BattleCharacter(charaName,maxHp,hp,maxMp,mp,atk,mag,def)/*,inventory(),
weapon("Wooden sword","The first item that every adventurers want.",2,1),
armor("Clothes","Ordinary clothing.",1)*/
{
    level=1;
    charaType="Player";
    this->expNow=0;
    this->expNext=10;
    this->money=0;
    this->inventory=new Inventory();
    this->weapon=new Weapon("Wooden sword","The first item that every adventurers want.",2,1);
    this->armor=new Armor("Clothes","Ordinary clothing.",1);
    this->inventory->addItem(weapon);
    this->inventory->addItem(armor);
    this->inventory->addItem(inventory->getOneItem("Potion"));
    this->inventory->addItem(inventory->getOneItem("Ether"));
    this->spells=new Spells();
    this->spells->addMagic("Fire");
    this->spells->addMagic("Ice");
    this->spells->addMagic("Water");
    this->spells->addMagic("Ultima");
    this->spells->addMagic("Super fire");
    srand ( time(NULL) );
}

Player::~Player()
{
    delete weapon;
    delete armor;
    delete inventory;
    delete spells;

}

Player::Player(const Player& p):BattleCharacter(p)/*,inventory(p),
weapon("Wooden sword","The first item that every adventurers want.",2,1),
armor("Clothes","Ordinary clothing.",1)*/
{
    level=p.level;
    charaType=p.charaType;
    this->expNow=p.expNow;
    this->expNext=p.expNext;
    this->money=p.money;
    this->inventory=new Inventory(*p.inventory);
    this->weapon=new Weapon(*p.weapon);
    this->armor=new Armor(*p.armor);
    this->inventory->addItem(p.weapon);
    this->inventory->addItem(p.armor);
    this->spells=new Spells(*p.spells);
    this->spells->addMagic("Fire");
    this->spells->addMagic("Ice");
    this->spells->addMagic("Water");
    srand ( time(NULL) );
}

Player& Player::operator=(const Player& p){
    if(this!=&p){
        level=p.level;
        charaType=p.charaType;
        this->expNow=p.expNow;
        this->expNext=p.expNext;
        this->money=p.money;
        delete inventory;
        this->inventory=new Inventory(*p.inventory);
        delete weapon;
        this->weapon=new Weapon(*p.weapon);
        delete armor;
        this->armor=new Armor(*p.armor);
        this->inventory->addItem(p.weapon);
        this->inventory->addItem(p.armor);
        delete spells;
        this->spells=new Spells(*p.spells);
        this->spells->addMagic("Fire");
        this->spells->addMagic("Ice");
        this->spells->addMagic("Water");
        srand ( time(NULL) );
    }
    return *this;
}

int Player::GetexpNow() const
{
    return expNow;
}

void Player::SetexpNow(int val)
{
    expNow = val;
}

int Player::GetexpNext() const
{
    return expNext;
}

void Player::SetexpNext(int val)
{
    expNext = val;
}

int Player::Getmoney() const
{
    return money;
}

void Player::Setmoney(int val)
{
    money = val;
}

Weapon* Player::Getweapon() const
{
    return weapon;
}

void Player::Setweapon(Weapon* val)
{
    weapon = val;
}

Armor* Player::Getarmor() const
{
    return armor;
}

void Player::Setarmor(Armor* val)
{
    armor = val;
}

Inventory* Player::Getinventory() const
{
    return inventory;
}

void Player::Setinventory(Inventory* val)
{
    inventory = val;
}

Spells* Player::Getspells() const
{
    return spells;
}

void Player::Setspells(Spells* val)
{
    spells=val;
}

bool Player::GetcheckSpellCast() const
{
    return checkSpellCast;
}

void Player::SetcheckSpellCast(bool val)
{
    checkSpellCast=val;
}

std::string Player::str() const
{
    std::stringstream sstr;
    sstr<<BattleCharacter::str()<<std::endl
    <<"Money : "<<Getmoney()<<std::endl
    <<"Exp : "<<GetexpNow()<<"/"<<GetexpNext()<<std::endl<<std::endl
    <<"Equipment : "<<std::endl<<std::endl
    <<"Weapon : "<<Getweapon()->GetitemName()<<" ATK : "<<Getweapon()->Getatk()<<" MAG : "<<Getweapon()->Getmag()<<std::endl
    <<"Armor : "<<Getarmor()->GetitemName()<<" DEF : "<<Getarmor()->Getdef()<<std::endl;
    return sstr.str();
}

void Player::moreMoney(int moneyEarn)
{
    Setmoney(money+moneyEarn);
}

void Player::levelUp()
{
    Setlevel(Getlevel()+1);
    SetmaxHp(Gethp()+rand() % 50 + 30);
    Sethp(GetmaxHp());
    SetmaxMp(Getmp()+rand() % 30 + 10);
    Setmp(GetmaxMp());
    Setatk(Getatk()+rand() % 3 + 1);
    Setmag(Getmag()+rand() % 3 + 1);
    Setdef(Getdef()+rand() % 3 + 1);
}

void Player::moreExp(int expEarned)
{
    SetexpNow(GetexpNow()+expEarned);
    if(GetexpNow()>=GetexpNext()){
        //permet d'avoir plus d'un niveau supplementaire
        int nb=(int)ceil(log2(GetexpNow()/GetexpNext()));
        for(int i=0;i<=nb;i++){
            levelUp();
            moreExpForLevelUp();
        }
    }
}

void Player::moreExpForLevelUp()
{
    SetexpNext(expNext*2);
}

int Player::damageDone() const
{
    return Getatk()+ weapon->Getatk();
}

int Player::magicalDamageDone(std::string magicName)
{
    reduceMp(magicName);
    if(!GetcheckSpellCast()){
        return 0;
    }
    return Getmag()+ spells->getOneMagicInGame(magicName)->GetbaseDamage();
}

void Player::damageReceived(int dmg)
{
    int damage= dmg - (Getdef() + armor->Getdef());
    if(damage>0){
        Sethp(Gethp()-damage);
        if(Gethp()<0){
            Sethp(0);
        }
    }
}

void Player::guard(int dmg)
{
    damageReceived(dmg/2);
    if(Gethp()>0){
        Sethp(Gethp()+(GetmaxHp()*0.1));
        if(Gethp()>GetmaxHp()){
            Sethp(GetmaxHp());
        }
        Setmp(Getmp()+(GetmaxMp()*0.1));
        if(Getmp()>GetmaxMp()){
            Setmp(GetmaxMp());
        }
    }
}

void Player::addIntoTheBag(std::string nameItem)
{
    inventory->addItem(nameItem);
}

void Player::changeEquipment(std::string nameItem)
{
    if(inventory->getOneItemIngame(nameItem)!=0){
        if(inventory->getOneItemIngame(nameItem)->GetitemType()=="Weapon"){
            Setweapon(dynamic_cast<Weapon*>(inventory->getOneItemIngame(nameItem)));
        }
        else if(inventory->getOneItemIngame(nameItem)->GetitemType()=="Armor"){
            Setarmor(dynamic_cast<Armor*>(inventory->getOneItemIngame(nameItem)));
        }

    }
}

Player* Player::clone() const
{
    return new Player();
}

void Player::reduceMp(std::string magicName)
{
    if(Getmp()>=spells->getOneMagicInGame(magicName)->GetmpUsage()){
        Setmp(Getmp()-(spells->getOneMagicInGame(magicName)->GetmpUsage()));
        if(Getmp()<0){
            Setmp(0);
        }
        SetcheckSpellCast(true);
    }
    else {
        SetcheckSpellCast(false);
    }
}

void Player::heals(Item* item)
{
    if(item->GetitemType()=="Heal"){
        Sethp(Gethp()+(dynamic_cast<HealItem*>(item)->GetamountHealed()));
        if(Gethp()>GetmaxHp()){
            Sethp(GetmaxHp());
        }
    }
    else if(item->GetitemType()=="HealMp"){
        Setmp(Getmp()+(dynamic_cast<HealItem*>(item)->GetamountHealed()));
        if(Getmp()>GetmaxMp()){
            Setmp(GetmaxMp());
        }
    }
    Getinventory()->deleteItem(item->GetitemName());
}

void Player::addLootMonster(std::vector<Item*>loot){
    if(loot.size()>0){
        for(unsigned i=0;i<loot.size();i++){
            Getinventory()->addItem(loot.at(i));
        }
    }
}

