#include "Player.h"

Player::Player(std::string charaName,int hp,int mp,int atk,int mag,int def):BattleCharacter(charaName,hp,mp,atk,mag,def)
{
    level=1;
    orientation = 0;
    move_at = 0;
    charaType="Player";
    this->expNow=0;
    this->expNext=10;
    this->money=0;
    this->weapon=new Weapon("Wooden sword","The first item that every adventurers want.",2,1);
    this->armor=new Armor("Clothes","Ordinary clothing.",1);
    this->inventory.addItem(weapon);
    this->inventory.addItem(armor);
    this->spells.addMagic("Fire");
    this->spells.addMagic("Ice");
    this->spells.addMagic("Water");
    srand ( time(NULL) );
    clock.restart();
}

Player::~Player()
{
    //dtor
}

Player::Player(const Player& p):BattleCharacter(charaName,hp,mp,atk,mag,def)
{
    level=1;
    charaType="Player";
    this->expNow=0;
    this->expNext=10;
    this->money=0;
}

Player& Player::operator=(const Player& p){
    if(this!=&p){
        level=1;
        charaType="Player";
        this->expNow=0;
        this->expNext=10;
        this->money=0;
    }
    return *this;
}

void Player::draw(sf::RenderTarget&target, sf::RenderStates) const
{
    // for debug only::
    sf::Sprite sp;
    sf::Texture tx;
    tx.loadFromFile("data/images/character_sprite.png");
    int delta_anim = clock.getElapsedTime().asMilliseconds() - move_at;
    int y =
        orientation == 0 ? 108 :
            orientation == 1 ? 73 :
                orientation == 3 ? 38 : 3;
    int x =
        delta_anim < 300 ?
            delta_anim < 200 ?
                delta_anim < 100 ? 1 : 33 : 65 : 33;
    Game::getInstance()->drawImage(tx, x, y, 32, 32, getPosition().x*32, getPosition().y*32-8);
}

void Player::move(const float x, const float y)
{
    move(Vector2f(x, y));
}

void Player::move(const Vector2f& movement)
{
    Time now = clock.getElapsedTime();
    if (now.asMilliseconds() - move_at < 300)
        return;
    old_position = position;
    position+= movement;
    move_at = now.asMilliseconds();
}

sf::Vector2f Player::getPosition() const
{
    Time now = clock.getElapsedTime();
    float progress = std::min(1.f, (now.asMilliseconds() - move_at)/300.f);
    Vector2f delta_position = position - old_position;
    return Vector2f(
        old_position.x + delta_position.x*progress,
        old_position.y + delta_position.y*progress
    );
}

sf::Vector2f Player::getRelativePosition() const
{
    return Vector2f(position.x*32, position.y*32);
}

sf::Vector2f Player::getAbsolutePosition() const
{
    return Vector2f(position.x, position.y);
}

void Player::setPosition(const float x, const float y)
{
    setPosition(Vector2f(x, y));
}

void Player::setPosition(const Vector2f& _position)
{
    position = old_position = _position;
    move_at=0; // clear animation
}

void Player::flip()
{
    setOrientation(orientation + 2);
}

void Player::setOrientation(const short _orientation)
{
    orientation = _orientation % 4;
}

short Player::getOrientation() const
{
    return orientation;
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

Inventory Player::Getinventory() const
{
    return inventory;
}

void Player::Setinventory(Inventory val)
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
    sstr<<BattleCharacter::str()<<std::endl<<"Exp : "<<GetexpNow()<<std::endl<<"Exp for next level : "<<GetexpNext()<<std::endl<<"money : "<<Getmoney()<<std::endl;
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
    return Getatk() + weapon->Getatk();
}

void Player::damageReceived(int dmg)
{
    int damage= dmg - (Getdef() + armor->Getdef());
    if(damage>0){
        Sethp(Gethp()-damage);
    }
}

