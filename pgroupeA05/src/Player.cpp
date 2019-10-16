#include "Player.h"

Player::Player(std::string charaName,int hp,int mp,int atk,int mag,int def):BattleCharacter(charaName,hp,mp,atk,mag,def)
{
    level=1;
    charaType="Player";
    this->expNow=0;
    this->expNext=10;
    this->money=0;
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

void Player::draw(sf::RenderTarget&target, sf::RenderStates) const
{
    // for debug only::
    sf::Sprite sp;
    sf::Texture tx;
    tx.loadFromFile("data/images/character_sprite.png");
    Game::getInstance()->drawImage(tx, 32, 0, 32, 32, position.x*32, position.y*32);
}

sf::Vector2f Player::getPosition() const
{
    return position;
}

void Player::move(const float x, const float y)
{
    move(Vector2f(x, y));
}

void Player::move(const Vector2f& movement)
{
    position+= movement;
}

void Player::setPosition(const float x, const float y)
{
    setPosition(Vector2f(x, y));
}

void Player::setPosition(const Vector2f& _position)
{
    position = _position;
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
    Setlevel(level++);
    //ajouter le fait d'augmenter les parametres
}

void Player::moreExp(int expEarned)
{
    if(GetexpNow()+expEarned>=GetexpNext()){
        levelUp();
        moreExpForLevelUp();
    }
    moreExp(expEarned);
    //ajouter le fait d'avoir plus d'un niveau
}

void Player::moreExpForLevelUp()
{
    SetexpNext(expNext*2);
}
