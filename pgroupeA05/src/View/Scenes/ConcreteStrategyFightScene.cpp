#include "View/Scenes/ConcreteStrategyFightScene.h"
//Constructeur of fghtScene
ConcreteStrategyFightScene::ConcreteStrategyFightScene()
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
    fn = new WindowsFight(15,250,300,200);
    fn2 = new WindowsFightInfo(325,250,300,200);
    fn3 = new WindowsFightInfo(50,190,550,40);
    barLife = Bar(400,20,200,20);
    barMp = Bar(400,150,200,20);
    barMp.Setcolor(sf::Color(20,160,225));
    barMonsterLife = Bar(50,20,200,20);
    textCombat.setPosition(sf::Vector2f(60,190));
    setText("the fight Begin");
    kill_sig = new bool;
    *kill_sig =  false;
    thd = new Thread(&ConcreteStrategyFightScene::WriteText, this);
    thd->launch();
    indexNbButtonDisplay = 0;
    NbButtonDisplay =4;
    limiteNbButtonDisplay = NbButtonDisplay;
    VerifNbDisplayButton();


    //setMonster();
    spriteMonster.setPosition(sf::Vector2f(100,60));
    spritePlayer.setPosition(sf::Vector2f(450,45));

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


    fm = new FightManager();
    //Add Button  in fightManager
    fn->addButton(btnAtt.clone());
    fn->addButton(btnMagie.Clone());
    fn->addButton(btnDefend.clone());
    fn->addButton(btnObjet.clone());

    //initialise fightManager in button
    for(unsigned i = 0; i<fn->getVect().size(); i++)
    {
        fn->getVect().at(i)->setFm(fm);
        fn->getVect().at(i)->setNbBoutonDisplay(NbButtonDisplay);
    }

    activate = 0;

    textureBackGroud = *TexturesManager::getInstance()->get("fight");
    sprintBackGroud.setTexture(textureBackGroud);

    indexXVfx = 0;
    indexYVfx = 0;
    isAnimVfx = false;

    //Delete pointer
    CalculTailleBar();

}
//destructeur of ConcreteStrategyFightScene
ConcreteStrategyFightScene::~ConcreteStrategyFightScene()
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
//check if activate exceed limite
void ConcreteStrategyFightScene::setActivate(int activate)
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
//Display of component which must be displyed
void ConcreteStrategyFightScene::draw(RenderTarget& target, RenderStates stat)const
{


    //Modifier la position

    sf::Font ft = *FontsManager::getInstance()->get("arial");
    //ft.loadFromFile("arial.ttf");


    sf::Text text;
    text.setFont(ft); // font est un sf::Font



    //fn->getVect().at(activate)->setIsActivate(true);



    // Draw the backgroud
    target.draw(sprintBackGroud,stat);
    for(unsigned j = 0; j<vectWindows.size(); j++)
    {
        target.draw(Panel(vectWindows.at(j)->getRect()));
        if(vectWindows.at(j)->getNbBoutton()+1 > 0)
        {
            vectWindows.at(secondWindowsActivate)->activateButton(activate);
            vectWindows.at(secondWindowsActivate)->getVect().at(activate)->setIsActivate(true);




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
                txt.move(rr.getSize().x/2.f - txt.getGlobalBounds().width/2.f, rr.getSize().y/2.f - txt.getGlobalBounds().height); // Alignement centered H/V
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
    /*target.draw((barLife.getFond()),stat);
    target.draw((barMp.getFond()),stat);
    target.draw((barMonsterLife.getFond()),stat);*/

    /*target.draw((barLife.getRect()),stat);
    target.draw((barMp.getRect()),stat);
    target.draw((barMonsterLife.getRect()),stat);*/
    target.draw(barLife);
    target.draw(barMp);
    target.draw(barMonsterLife);


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
        std::cout<<std::endl<<std::endl <<"LA MORT"<<std::endl<<std::endl<<std::endl;
        return false;
    }
}
//manage all event in ConcreteStrategyFightScene
void ConcreteStrategyFightScene::eventHandler(Event ev)
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
                                    gotoPreviousScene();
                                    return;
                                }
                                else
                                {
                                  //setScene(new ConcreteStrategyGameOverScene);
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
                                    isBtnisAttack =vectWindows.at(secondWindowsActivate)->getVect().at(i)->getIsAttack();
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
std::vector<WindowsFight*> ConcreteStrategyFightScene::getVectWindows()const
{
    return vectWindows;
}
void ConcreteStrategyFightScene::fight()
{
    // DELETE ME
}
//setter of fightManager
void ConcreteStrategyFightScene::setFightManager(FightManager* fm)
{
    this->fm = fm;
}
//getteur of fightManager
FightManager* ConcreteStrategyFightScene::getFightManager()const
{
    return fm;
}
//getteur of Texture of backgroud
sf::Texture ConcreteStrategyFightScene::getTextureBackGroud()const
{
    return textureBackGroud;
}
float ConcreteStrategyFightScene::getTimeEventIsNotActive()const
{
    return timeEventIsNotActive;
}
void ConcreteStrategyFightScene::setTimeEventIsNotActive(float newTime)
{
    timeEventIsNotActive = newTime;
}
//set the texture and the sprite of mob
void ConcreteStrategyFightScene::setSpriteMonster()
{
    std::string lien = ("mob_"+getFightManager()->getMonster()->GetcharaName());
    textureMonster = *tm->get(lien);//"_" + getFightManager()->getMonster()->GetcharaName()
    spriteMonster.setTexture(textureMonster);
}
//set the text
void ConcreteStrategyFightScene::setText(std::string text)
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
void ConcreteStrategyFightScene::setMonster()
{
    //setSpriteMonster(fm->getMonster()->GetcharaName());
    std::cout<<fm->getMonster()->GetcharaName()<<std::endl;
}

/** @brief setPlayer
  *
  * Set the Player in fightManager
  */
void ConcreteStrategyFightScene::setPlayer()
{

}

/** @brief setSpritePlayer
  *
  * set the sprite of Player
  */
void ConcreteStrategyFightScene::setSpritePlayer()
{
  texturePlayer = *tm->get("hero");//"_" + getFightManager()->getMonster()->GetcharaName()
  spritePlayer.setTexture(texturePlayer);
  spritePlayer.setScale(0.8,0.8);
}
/** @brief WriteText
  *
  * Write the text of fight
  */
void ConcreteStrategyFightScene::WriteText()
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

                textCurrentlyWrite="";
                indexTextWhichMustBeWrite =0;
                isCurrentlyWrite= false;



            }
        }
        if(isAnimVfx)
        {
         std::cout <<"vfx marche"<< std::endl;
         CalculVfxAnimation(indexXVfx,indexYVfx,isBtnisAttack);
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
void ConcreteStrategyFightScene::VerifNbDisplayButton()
{
 indexNbButtonDisplay =((activate/NbButtonDisplay)*NbButtonDisplay);
 limiteNbButtonDisplay = (((activate/NbButtonDisplay)*4)+NbButtonDisplay);
}
/**
*Calcul size of BarLif,Bar of mana,Life bar of monster
*/
void ConcreteStrategyFightScene::CalculTailleBar()
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
void ConcreteStrategyFightScene::CalculVfxAnimation(int indexX,int indexY,bool isAttack)
{
 if(isAttack)
 {
  spriteVfx.setPosition(0,0);
  std::cout<< isAttack<<"isAttack"<<std::endl;
 }
 else
 {
  spriteVfx.setPosition(400,0);
  std::cout<< isAttack<<"isAttack"<<std::endl;
 }

 spriteVfx.setTexture(textureVfx);
 spriteVfx.setTextureRect(sf::IntRect(256*indexX,256*indexY,256,256));
  //spriteVfx.setTexture(textureTest);
  //= sf::Sprite(textureVfx,sf::IntRect(posX*indexX,posY*indexY,tailleX,tailleY));

}
/** @brief MakeAniùation
  *
  * manage index of vfx
  */
void ConcreteStrategyFightScene::MakeAnimation(int limiteX,int limiteY)
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














