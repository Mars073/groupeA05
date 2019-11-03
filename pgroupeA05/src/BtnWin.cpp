#include "BtnWin.h"


BtnWin::BtnWin(int positionX,int positionY,int tailleX,int tailleY,std::string textButton)
{
    this->rect.setPosition(sf::Vector2f(positionX,positionY));
    this->rect.setSize(sf::Vector2f(tailleX,tailleY));
    this->rect.setOutlineThickness(5);
    this->rect.setOutlineColor(sf::Color(0,0,255));
    nomText = textButton;
    this->positionX = positionX;
    this->positionY =positionY;
    this->tailleX = tailleX;
    this->tailleY = tailleY;
    this->isButtonMenu = false;




    sf::Text text;
    //this->text.setFont(ft); // font est un sf::Font
    // choix de la cha�ne de caract�res � afficher
    this->text.setString(textButton);
    this->text.setCharacterSize(15); // exprim�e en pixels, pas en points !
    this->text.setStyle(sf::Text::Bold | sf::Text::Underlined);
    this->text.setPosition(positionX,positionY);
    this->text.setFillColor(sf::Color(0,0,255));
    //this->strat = strat;

    /*
    this->txt.setFont(this->font);
    this->txt.setPosition(sf::Vector2f(positionX,positionY));


    this->txt.setString("papapapapa");
    this->txt.setFillColor(sf::Color(255,255,255));
    this->txt.setColor(sf::Color(255,0,0));
    this->txt.setCharacterSize(10);
    this->txt.setPosition(sf::Vector2f(100,100));
    this->txt.setOutlineThickness(4);
    */

    // Design paterne strategie car le masquage des methode ne marche pas dans les vector


}
BtnWin::BtnWin(int positionX,int positionY,int tailleX,int tailleY,std::string textButton,std::string Description)
{
    this->rect.setPosition(sf::Vector2f(positionX,positionY));
    this->rect.setSize(sf::Vector2f(tailleX,tailleY));
    this->rect.setOutlineThickness(5);
    this->rect.setOutlineColor(sf::Color(0,0,255));





    sf::Text text;
    //this->text.setFont(ft); // font est un sf::Font
    // choix de la cha�ne de caract�res � afficher
    this->text.setString(textButton);
    this->text.setCharacterSize(15); // exprim�e en pixels, pas en points !
    this->text.setStyle(sf::Text::Bold | sf::Text::Underlined);
    this->text.setPosition(positionX,positionY);
    this->text.setFillColor(sf::Color(0,0,255));
}
void BtnWin::ativate()
{
 isActivate = true;
}
void BtnWin::Desativate()
{
 isActivate = false;
}
int BtnWin::getPositionX() const
{
    return positionX;
}
int BtnWin::getPositionY()const
{
    return positionY;
}
int BtnWin::getTailleX()const
{
    return tailleX;
}
int BtnWin::getTailleY()const
{
    return tailleY;
}
sf::RectangleShape BtnWin::getRect()const
{
    return rect;
}
void BtnWin::changeColorActivate()
{
    rect.setOutlineColor(sf::Color(255,0,0));
}
void BtnWin::changeColorDesactivate()
{
    rect.setOutlineColor(sf::Color(0,0,0));
}

sf::Text BtnWin::getText()
{
    return text;
}
void BtnWin::action()
{
    std::cout << "vous avez fait une action"<< std::endl;
}
bool BtnWin::getisActivate()
{
    return isActivate;
}
void BtnWin::setIsActivate(bool val)
{
    isActivate = val;
}

BtnWin::~BtnWin()
{
    //dtor
}
BtnWin::BtnWin(BtnWin const& c)
{
    this->positionX= c.positionX;
    this->positionY = c.positionY;
    this->tailleX = c.tailleX;
    this->tailleY = c.tailleY;
    this->text = c.text;

    this->rect = c.rect;

    this->rect.setPosition(sf::Vector2f(c.positionX,c.positionY));
    this->rect.setSize(sf::Vector2f(c.tailleX,c.tailleY));
    this->rect.setOutlineThickness(5);
    this->rect.setOutlineColor(sf::Color(0,0,255));

    std::cout << c.positionX<< std::endl;
    this->text = c.text;
    this->text.setString(c.nomText);
    this->text.setCharacterSize(15); // exprim�e en pixels, pas en points !
    this->text.setStyle(sf::Text::Bold | sf::Text::Underlined);
    this->text.setPosition(c.positionX,c.positionY);
    this->text.setFillColor(sf::Color(0,0,255));

    this->isButtonMenu = c.isButtonMenu;
    this->ListButton = c.ListButton;
    this->fm = c.fm;




}
//Peur de fuite de memoire a poser au prof
std::vector<BtnWin*> BtnWin::getListButton()
{
    return ListButton;
}
std::string BtnWin::getDescription()const
{
    return Description;
}
void BtnWin::setDescription(std::string str)
{
    Description = str;
}
 void BtnWin::setPositionX(int pos)
 {
    positionX = pos;
 }
void BtnWin::setPositionY(int pos)
{
    positionY =pos;
}
void BtnWin::setTailleX(int pos)
{
    tailleX = pos;
}
void BtnWin::setTailleY(int pos)
{
    tailleY = pos;
}
 std::string BtnWin::getTextButton()
{
    return nomText;
}
void BtnWin::AddButton(BtnWin *btn)
{
    ListButton.push_back(btn);
}
bool BtnWin::getIsMenuBoutton()const
{
    return isButtonMenu;
}
void BtnWin::setIsMenuBoutton(bool val)
{
    isButtonMenu = val;
}
void BtnWin::setFm(FightManager *fmNew)
{
    fm = fmNew;
}
FightManager* BtnWin::getFm()
{
 return fm;
}
void BtnWin::setNomText(std::string nomText)
{
 this->nomText = nomText;
 this->text.setString(nomText);
}
std::string BtnWin::getNomText()const
{
 return nomText;
}
bool BtnWin::operator==(const BtnWin a)
{
  return this->equals(a);
}
bool BtnWin::equals(const BtnWin b)
{
 return this->getNomText() == b.getNomText();
}
bool BtnWin::equals(BtnWin* b)
{
 return this->getNomText() == b->getNomText();
}



