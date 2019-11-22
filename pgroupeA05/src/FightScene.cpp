#include "FightScene.h"

FightScene::FightScene()
{
    //ctor
    //init pointer
    activate = 0;
    secondWindowsActivate = 0;
    indexTextWhichMustBeWrite =0;
    textCurrentlyWrite="";
    isEventActive = true;
    isCooldown = false;
    isCurrentlyWrite = false;
    timeEventIsNotActive = 5.0f;
    fn = new WindowsFight(0,250,300,200);
    fn2 = new WindowsFightInfo(325,250,300,200);
    fn3 = new WindowsFightInfo(50,190,550,40);
    barLife = Bar(400,20,200,20);
    barMp = Bar(400,150,200,20);
    barMp.Setcolor(sf::Color(0,0,225));
    barMonsterLife = Bar(50,20,200,20);
    textCombat.setPosition(sf::Vector2f(50,190));
    setText("coucou je vis");
    kill_sig = new bool;
    *kill_sig =  false;
    thd = new Thread(&FightScene::WriteText, this);
    thd->launch();
    indexNbButtonDisplay = 0;
    NbButtonDisplay =4;
    limiteNbButtonDisplay = NbButtonDisplay;
    VerifNbDisplayButton();


    //setMonster();
    spriteMonster.setPosition(sf::Vector2f(100,60));
    spritePlayer.setPosition(sf::Vector2f(450,45));
    /*
    textureMonster = Resources::getTexture("boss","data/images/monsters/boss.png");
    spriteMonster.setTexture(textureMonster);
    */
    textureTest = *TexturesManager::getInstance()->get("vfx_ice");
    spTest.setTexture(textureTest);








    //add Windows in Vecteur
    vectWindows.push_back(fn);
    vectWindows.push_back(fn2);
    vectWindows.push_back(fn3);

    //Creation of button
    btnAttack btnAtt(fn->getPositionX()+10,fn->getPositionY()+7,70,35,"Attack");
    BtnMagic btnMagie(fn->getPositionX()+10,fn->getPositionY()+57,70,35,"Magic");
    btnMagie.setIsMenuBoutton(true);

    BtnDefend btnDefend(fn->getPositionX()+10,fn->getPositionY()+107,70,35,"Defend");
    BtnObject btnObjet(fn->getPositionX()+10,fn->getPositionY()+157,70,35,"Object");
    btnObjet.setIsMenuBoutton(true);

    //btnAttack *btnAttack2 = new btnAttack(fn2->getPositionX(),fn2->getPositionY()+100,80,50,"Feu");
    //btnAttack *btnAttack3 = new btnAttack(fn2->getPositionX(),fn2->getPositionY()+100,80,50,"Eau");
    //btnMagie->AddButton(btnAttack2);
    //btnMagie->AddButton(btnAttack3);
    fm = new FightManager();
    //Add Button  in fightManager
    fn->addButton(btnAtt.clone());
    fn->addButton(btnMagie.Clone());
    fn->addButton(btnDefend.clone());
    fn->addButton(btnObjet.clone());
    //this->setSpriteMonster();
    //initialise fightManager in button
    for(unsigned i = 0; i<fn->getVect().size(); i++)
    {
        fn->getVect().at(i)->setFm(fm);
        fn->getVect().at(i)->setNbBoutonDisplay(NbButtonDisplay);
    }

    activate = 0;

    textureBackGroud = *TexturesManager::getInstance()->get("fight");
    sprintBackGroud.setTexture(textureBackGroud);
    //dbw = DrawableBattleCharacter(fm->getPlayer(),sf::Vector2f(100,400));
    indexXVfx = 0;
    indexYVfx = 0;
    isAnimVfx = false;

    //Delete pointer
    CalculTailleBar();

}

FightScene::~FightScene()
{
    *kill_sig = true;   // break WriteText loop

    if (thd)
    {
        thd->terminate(); // force quit WriteText
        delete thd;
    }
    if (kill_sig)
        delete kill_sig; // alias intern_ptr in WriteText

    delete fm;

    /*delete fn;
    delete fn2;
    delete fn3;*/
    for (unsigned i; i < vectWindows.size(); i++)
        if (vectWindows.at(i))
            delete vectWindows.at(i);
}
void FightScene::setActivate(int activate)
{
    if (secondWindowsActivate == 1)
    {
        if (activate < 0)
            this->activate = fn2->getNbBoutton();
        else if (activate > fn2->getNbBoutton())
            this->activate = 0;
        else
            this->activate = activate;
    }
    else
    {
        if (activate < 0)
            this->activate = fn->getNbBoutton();
        else if (activate > fn->getNbBoutton())
            this->activate = 0;
        else
            this->activate = activate;
    }
}
void FightScene::draw(RenderTarget& target, RenderStates stat)const
{

    //sf::RenderWindow window;
    //sf::CircleShape cercle;
    //sf::CircleShape triangle(80,3);
    //sf::RectangleShape rect;
    //window.create(sf::VideoMode(1270,720),"papa");
    //window.setFramerateLimit(4);

    //Modifier la position

    sf::Font ft = *FontsManager::getInstance()->get("arial");
    //ft.loadFromFile("arial.ttf");


    sf::Text text;
    text.setFont(ft); // font est un sf::Font


    /*

    // choix de la cha�ne de caract�res � afficher
    text.setString("Hello world");
    // choix de la taille des caract�res
    text.setCharacterSize(24); // exprim�e en pixels, pas en points !
    // choix de la couleur du texte
    text.setColor(sf::Color::Red);
    // choix du style du texte
    text.setStyle(sf::Text::Bold | sf::Text::Underlined);
    */


    //window.setPosition(sf::Vector2i(0,0));
    //window.setFramerateLimit(60);
    //creation de fenetre
    /*
    cercle.setFillColor(sf::Color(100,120,140));
    cercle.setRadius(50.0f);
    cercle.setPosition(100,100);
    cercle.setOutlineColor(sf::Color(100,100,100));
    cercle.setOutlineThickness(10);

    rect.setFillColor(sf::Color(0,0,0));
    rect.setOutlineColor(sf::Color(100,100,100));
    rect.setOutlineThickness(10);
    rect.setRotation(45);
    rect.setPosition(15,100);
    rect.setSize(sf::Vector2f(40,45));

    triangle.setFillColor(sf::Color(100,100,100));
    triangle.setPosition(150,10);
    */
    /*
    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
            {
                window.close();
            }
        }
        //Gestion du clavier
    */

    //BackUp draw Widows
    /*
    fn->activateButton(activate);
    fn->getVect().at(activate)->setIsActivate(true);
    //window.draw(cercle);
    //window.draw(rect);
    //window.draw(triangle);
    //window.draw(text);
    target.draw(fn->getRect());
    for(int i = 0; i<fn->getNbBoutton();i++)
    {
        sf::RectangleShape rr =fn->getVect().at(i)->getRect();
        target.draw(rr,stat);
        sf::Text txt = fn->getVect().at(i)->getText();
        txt.setFont(ft);
        target.draw(txt,stat);
        fn->getVect().at(i)->setIsActivate(false);

    }
    fn->getVect().at(activate)->setIsActivate(true);
    */


    // Draw the backgroud
    target.draw(sprintBackGroud,stat);
    for(unsigned j = 0; j<vectWindows.size(); j++)
    {
        target.draw(vectWindows.at(j)->getRect());
        if(vectWindows.at(j)->getNbBoutton()+1 > 0)
        {
            vectWindows.at(secondWindowsActivate)->activateButton(activate);
            vectWindows.at(secondWindowsActivate)->getVect().at(activate)->setIsActivate(true);


            /*
            backup de draw
            for(int i = 0; i<=vectWindows.at(j)->getNbBoutton(); i++)
            {
                //std::cout << vectWindows.at(i)->getNbBoutton() <<i <<std::endl;
                sf::RectangleShape rr =vectWindows.at(j)->getVect().at(i)->getRect();
                target.draw(rr,stat);
                sf::Text txt = vectWindows.at(j)->getVect().at(i)->getText();
                txt.setFont(ft);
                target.draw(txt,stat);
                vectWindows.at(j)->getVect().at(i)->setIsActivate(false);
            }
            */


            for(int i = indexNbButtonDisplay; i<limiteNbButtonDisplay; i++)
            {


                 if(i >vectWindows.at(j)->getNbBoutton())
                {
                 break;
                }

                //std::cout << vectWindows.at(i)->getNbBoutton() <<i <<std::endl;
                sf::RectangleShape rr =vectWindows.at(j)->getVect().at(i)->getRect();
                target.draw(rr,stat);
                sf::Text txt = vectWindows.at(j)->getVect().at(i)->getText();
                txt.setFont(ft);
                target.draw(txt,stat);
                vectWindows.at(j)->getVect().at(i)->setIsActivate(false);

            }

            vectWindows.at(secondWindowsActivate)->getVect().at(activate)->setIsActivate(true);
            //vectWindows.at(secondWindowsActivate)->getVect().at(activate)->getDescription();

        }

    }

    //




    target.draw(textCombat,stat);
    //manage bar of life and mana and
    //target.draw((barLife->getFond()),stat);
    target.draw(spritePlayer,stat);
    target.draw((barLife.getFond()),stat);
    target.draw((barMp.getFond()),stat);
    target.draw((barMonsterLife.getFond()),stat);

    target.draw((barLife.getRect()),stat);
    target.draw((barMp.getRect()),stat);
    target.draw((barMonsterLife.getRect()),stat);


    //Get current and max value of Bar
    /*float current = fm->getPlayer()->Gethp();
    float maxx = fm->getPlayer()->GetmaxHp();

    float currentMp = fm->getPlayer()->Getmp();
    float maxxMp = fm->getPlayer()->GetmaxHp();

    float currentMHp = fm->getMonster()->Gethp();
    float maxxMHp = fm->getMonster()->GetmaxHp();




    //std::cout <<secondWindowsActivate<<endl;
    //Change the size of bar
    barLife.setBarLifeTaille(current,maxx);*/
    //barMonsterLife->setBarLifeTaille(currentMHp,maxxMHp);
    target.draw(spriteMonster,stat);
    if(isAnimVfx)
    {
     target.draw(spriteVfx,stat);
    }
    //target.draw(spTest);



    //target.draw(dbw,stat);



}
bool __HOTFIX__inRange(int i, int b, int e) {
    if (i >= b && i <= e)
    {
        return true;
    }
    else
    {
        std::cout << "▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄" << std::endl << "████▌▄▌▄▐▐▌█████" << std::endl << "████▌▄▌▄▐▐▌▀████" << std::endl << "▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀" << std::endl;
        std::cout <<"la mort"<<std::endl;
        return false;
    }
}

void FightScene::eventHandler(Event ev)
{
    setActivate(activate);
    std::cout<< isCurrentlyWrite << std::endl;
    if (!isCurrentlyWrite)
    {
        if (ev.type == sf::Event::KeyReleased) // KeyPressed (OnKeyDown)
        {
            switch(ev.key.code)
            {
            case sf::Keyboard::Up:
                {
                    setActivate(activate - 1);
                    std::cout<<activate<<"activate est egale a combien"<<std::endl;
                    VerifNbDisplayButton();
                    break;
                }
            case sf::Keyboard::Down:
                {
                    setActivate(activate +1);
                    std::cout<<activate<<"activate est egale a combien"<<std::endl;
                    VerifNbDisplayButton();
                    break;
                }
            //case sf::Keyboard::Right:
            //case sf::Keyboard::Left:
            case sf::Keyboard::Enter:
            case sf::Keyboard::Space:
                {
                    if (!__HOTFIX__inRange(secondWindowsActivate, 0, vectWindows.size()-1))
                        return;
                    for (int i = 0; i <= vectWindows.at(secondWindowsActivate)->getNbBoutton(); i++)
                    {
                        std::cout << "secondWindowsActivate: " << secondWindowsActivate<<endl;

                        if (!__HOTFIX__inRange(i, 0, vectWindows.at(secondWindowsActivate)->getVect().size()-1))
                            return;
                        if (vectWindows.at(secondWindowsActivate)->getVect().at(i)->getisActivate())
                        {
                            std::cout << "espace/enter toucher" << std::endl;

                            if (!__HOTFIX__inRange(i, 0, vectWindows.at(secondWindowsActivate)->getVect().size()-1))
                                return;
                            vectWindows.at(secondWindowsActivate)->getVect().at(i)->action();
                            VerifNbDisplayButton();
                            CalculTailleBar();
                            setActivate(0);

                            if (fm->isFightFinish())
                            {
                                if (fm->isPlayerWin())
                                {
                                    std::cout << "Freeze?" << std::endl;
                                    gotoPreviousScene();
                                    return;
                                }
                            }
                            else
                            {
                                std::cout <<"isMenu" <<std::endl;

                                if (!__HOTFIX__inRange(i, 0, vectWindows.at(secondWindowsActivate)->getVect().size()-1))
                                    return;
                                if(vectWindows.at(secondWindowsActivate)->getVect().at(i)->getIsMenuBoutton())
                                {
                                    fn2->ClearWindows();
                                    secondWindowsActivate = 1;

                                    //check Doublon ERREUR

                                    if (!__HOTFIX__inRange(i, 0, fn->getVect().size()-1))
                                        return;
                                    for(unsigned j = 0 ; j <(fn->getVect().at(i)->getListButton().size()); j++)
                                    {
                                        //std::cout << fn2->getVect().at(i)->getListButton().size() <<"nombre de bouton dans le bouton et j " << j <<endl;

                                        bool isCopie = false;
                                        for(unsigned t = 0; t < fn2->getVect().size(); t++)
                                        {
                                            if (!__HOTFIX__inRange(t, 0, fn2->getVect().size()-1))
                                                return;
                                            if (!__HOTFIX__inRange(i, 0, fn->getVect().size()-1))
                                                return;
                                            if (!__HOTFIX__inRange(j, 0, fn->getVect().at(i)->getListButton().size()-1))
                                                return;
                                            if(fn2->getVect().at(t)->equals(fn->getVect().at(i)->getListButton().at(j)))
                                                isCopie = true;
                                        }

                                        if (!isCopie)
                                        {
                                            if (!__HOTFIX__inRange(i, 0, fn->getVect().size()-1))
                                                return;
                                            if (!__HOTFIX__inRange(j, 0, fn->getVect().at(i)->getListButton().size()-1))
                                                return;
                                            fn2->addButton(fn->getVect().at(i)->getListButton().at(j));
                                        }

                                        //fn2->fn->getVect().at(i)->getListButton().
                                    }
                                }
                                else
                                {
                                    //setText(vectWindows.at(secondWindowsActivate)->getVect().at(i)->getDescription());
                                    if (!__HOTFIX__inRange(i, 0, vectWindows.at(secondWindowsActivate)->getVect().size()-1))
                                                return;
                                    textWhichMustBeWrite=vectWindows.at(secondWindowsActivate)->getVect().at(i)->getDescription();
                                    isCurrentlyWrite = true;
                                    textureVfx = vectWindows.at(secondWindowsActivate)->getVect().at(i)->getVfxTexture();
                                    secondWindowsActivate = 0;
                                    isAnimVfx =true;

                                }

                                std::cout << "verif doublons" << std::endl;
                            }
                        }
                    }
                    break;
                }
            default: break;
            }
        }
        // Tout est géré par le setter
        /*if (secondWindowsActivate == 1)
        {
            if (activate < 0)
                activate = fn2->getNbBoutton()-1; // getNbBoutton() retourne size - 1, donc active prend l'avant dernière valeur?
            else if (activate > fn2->getNbBoutton())
                setActivate(0);                   // Dans ce cas on utilise un setter ?

            std::cout << activate<< std::endl;
        }
        else
        {
            if(activate < 0)
            {
                activate =fn->getNbBoutton();
            }
            else if(activate > fn->getNbBoutton())
            {
                setActivate(0);
            }
            std::cout << activate<< std::endl;

        }*/
    }
}
//Getter of vector of windows
std::vector<WindowsFight*> FightScene::getVectWindows()const
{
    return vectWindows;
}
void FightScene::fight()
{
    // DELETE ME
}
void FightScene::setFightManager(FightManager* fm)
{
    this->fm = fm;
}
FightManager* FightScene::getFightManager()const
{
    return fm;
}
sf::Texture FightScene::getTextureBackGroud()const
{
    return textureBackGroud;
}
float FightScene::getTimeEventIsNotActive()const
{
    return timeEventIsNotActive;
}
void FightScene::setTimeEventIsNotActive(float newTime)
{
    timeEventIsNotActive = newTime;
}
void FightScene::setSpriteMonster()
{
    std::string lien = ("mob_"+getFightManager()->getMonster()->GetcharaName());
    textureMonster = *tm->get(lien);//"_" + getFightManager()->getMonster()->GetcharaName()
    spriteMonster.setTexture(textureMonster);
}
void FightScene::setText(std::string text)
{
    textCombat.setCharacterSize(30);
    police = *FontsManager::getInstance()->get("arial");
    textCombat.setFont(police);
    textCombat.setString(text);
}




/** @brief setMonster
  *
  * set the monster in  view.this monster must exist
  */
void FightScene::setMonster()
{
    //setSpriteMonster(fm->getMonster()->GetcharaName());
    std::cout<<fm->getMonster()->GetcharaName()<<std::endl;
}

/** @brief setPlayer
  *
  * Set the Player in fightManager
  */
void FightScene::setPlayer()
{

}

/** @brief setSpritePlayer
  *
  * set the sprite of Player
  */
void FightScene::setSpritePlayer()
{
  texturePlayer = *tm->get("hero");//"_" + getFightManager()->getMonster()->GetcharaName()
  spritePlayer.setTexture(texturePlayer);
  spritePlayer.setScale(0.8,0.8);
}
/** @brief WriteText
  *
  * Whrite the text of fight
  */
void FightScene::WriteText()
{
    std::cout <<"ecrire"<<std::endl;
    bool* intern_ptr = kill_sig;
    while(!*intern_ptr)
    {

        if(isCurrentlyWrite)
        {

            if(indexTextWhichMustBeWrite < (int)textWhichMustBeWrite.length())
            {
                textCurrentlyWrite += textWhichMustBeWrite[indexTextWhichMustBeWrite];
                setText(textCurrentlyWrite);
                //clock.restart();
                indexTextWhichMustBeWrite++;

            }
            else
            {
                isCurrentlyWrite= false;
                indexTextWhichMustBeWrite =0;
                textCurrentlyWrite="";
            }
        }
        if(isAnimVfx)
        {
         std::cout <<"vfx marche"<< std::endl;
         CalculVfxAnimation(256,205,200,200,indexXVfx,indexYVfx);
         MakeAnimation(5,4);
        }
        //std::this_thread::sleep_for(std::chrono::milliseconds(60));
        sf::sleep(sf::milliseconds(60));

    }
    delete intern_ptr;
    intern_ptr = 0;

}

/** @brief VerifNbDisplayButton
  *
  * Manage the number of button display
  */
void FightScene::VerifNbDisplayButton()
{
 indexNbButtonDisplay =((activate/NbButtonDisplay)*NbButtonDisplay);
 limiteNbButtonDisplay = (((activate/NbButtonDisplay)*4)+NbButtonDisplay);
}
/**
*Calcul size of BarLif,Bar of mana,Life bar of monster
*/
void FightScene::CalculTailleBar()
{
    float current = fm->getPlayer()->Gethp();
    float maxx = fm->getPlayer()->GetmaxHp();

    float currentMp = fm->getPlayer()->Getmp();
    float maxxMp = fm->getPlayer()->GetmaxMp();

    float currentMHp = fm->getMonster()->Gethp();
    float maxxMHp = fm->getMonster()->GetmaxHp();

    barLife.setBarLifeTaille(current,maxx);
    barMp.setBarLifeTaille(currentMp,maxxMp);
    barMonsterLife.setBarLifeTaille(currentMHp,maxxMHp);
}
/** @brief CalculVfxAnimation
  *
  * change Texture of vfx for make animation
  */
void FightScene::CalculVfxAnimation(int tailleX, int tailleY, int posX, int posY, int indexX,int indexY)
{
 spriteVfx.setTexture(textureVfx);
 spriteVfx.setTextureRect(sf::IntRect(256*indexX,256*indexY,256,256));
  //spriteVfx.setTexture(textureTest);
  //= sf::Sprite(textureVfx,sf::IntRect(posX*indexX,posY*indexY,tailleX,tailleY));

}
/** @brief MakeAniùation
  *
  * manage index of vfx
  */
void FightScene::MakeAnimation(int limiteX,int limiteY)
{
  indexXVfx++;
  if(indexXVfx >= limiteX)
  {

   indexXVfx =0;
   indexYVfx++;
   if(indexYVfx>=limiteY)
   {
     indexYVfx = 0;
     isAnimVfx = false;
   }
  }
}














