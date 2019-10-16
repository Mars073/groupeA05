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

void Player::setPosition(const float x, const float y)
{
    setPosition(Vector2f(x, y));
}

void Player::setPosition(const Vector2f& _position)
{
    position = _position;
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
