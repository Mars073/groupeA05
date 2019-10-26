#include "Player.h"
//ajouter max hp et mp et reparer armor et weapon
Player::Player(std::string charaName,int hp,int mp,int atk,int mag,int def)
:BattleCharacter(charaName,hp,mp,atk,mag,def)/*,inventory(),
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
    /*this->inventory->addItem(weapon);
    this->inventory->addItem(armor);*/
    this->spells.addMagic("Fire");
    this->spells.addMagic("Ice");
    this->spells.addMagic("Water");
    srand ( time(NULL) );
}

Player::~Player()
{
    std::cout << "tick" ;
    delete weapon;
    delete armor;
    delete inventory;

}

Player::Player(const Player& p):BattleCharacter(p)/*,inventory(p),
weapon("Wooden sword","The first item that every adventurers want.",2,1),
armor("Clothes","Ordinary clothing.",1)*/
{
    level=1;
    charaType="Player";
    this->expNow=0;
    this->expNext=10;
    this->money=0;
    this->inventory=p.inventory;
    this->weapon=p.weapon;
    this->armor=p.armor;
    /*this->inventory->addItem(p.weapon);
    this->inventory->addItem(p.armor);*/
    this->spells.addMagic("Fire");
    this->spells.addMagic("Ice");
    this->spells.addMagic("Water");
    srand ( time(NULL) );
}

Player& Player::operator=(const Player& p){
    if(this!=&p){
        level=1;
        charaType="Player";
        this->expNow=0;
        this->expNext=10;
        this->money=0;
        this->inventory=p.inventory;
        this->weapon=p.weapon;
        this->armor=p.armor;
        /*this->inventory->addItem(p.weapon);
        this->inventory->addItem(p.armor);*/
        this->spells.addMagic("Fire");
        this->spells.addMagic("Ice");
        this->spells.addMagic("Water");
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

Spells Player::Getspells() const
{
    return spells;
}

void Player::Setspells(Spells val)
{
    spells=val;
}


std::string Player::str() const
{
    std::stringstream sstr;
    sstr<<BattleCharacter::str()<<std::endl<<"Exp : "<<GetexpNow()<<std::endl<<"Exp for next level : "<<GetexpNext()<<std::endl<<"money : "<<Getmoney()<<std::endl<<"Equipment : "<<std::endl<<Getweapon()->str()<<std::endl<<Getarmor()->str()<<std::endl<<Getinventory()->str();
    return sstr.str();
}

void Player::moreMoney(int moneyEarn)
{
    Setmoney(money+moneyEarn);
}

void Player::levelUp()
{
    Setlevel(Getlevel()+1);
    Sethp(Gethp()+rand() % 50 + 30);
    Setmp(Getmp()+rand() % 30 + 10);
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

void Player::damageReceived(int dmg)
{
    int damage= dmg - (Getdef() + armor->Getdef());
    if(damage>0){
        Sethp(Gethp()-damage);
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

