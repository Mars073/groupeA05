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

std::string Player::toString() const
{
    std::stringstream sstr;
    sstr<<BattleCharacter::toString()<<std::endl<<"Exp : "<<GetexpNow()<<std::endl<<"Exp for next level : "<<GetexpNext()<<std::endl<<"money : "<<Getmoney()<<std::endl;
    return sstr.str();
}

void Player::moreMoney(int moneyEarn)
{
    Setmoney(money+moneyEarn);
}
