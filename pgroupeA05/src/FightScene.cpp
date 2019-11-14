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
     ft = FontsManager::getInstance();
     barLife = new Bar(400,20,200,20);
     barMp = new Bar(400,150,200,20);
     barMp->Setcolor(sf::Color(0,0,225));
     barMonsterLife = new Bar(50,20,200,20);
     textCombat.setPosition(sf::Vector2f(50,190));
     setText("coucou je vis");
     thd =std::thread(&FightScene::WriteText,this);
     thd.detach();


     //setMonster();
     spriteMonster.setPosition(sf::Vector2f(100,60));
     /*
     textureMonster = Resources::getTexture("boss","data/images/monsters/boss.png");
     spriteMonster.setTexture(textureMonster);
     */







     //add Windows in Vecteur
     vectWindows.push_back(fn);
     vectWindows.push_back(fn2);
     vectWindows.push_back(fn3);
     //Creation of button
     btnAttack *btnAtt = new btnAttack(fn->getPositionX()+10,fn->getPositionY()+7,70,35,"Attack");
     BtnMagic *btnMagie = new BtnMagic(fn->getPositionX()+10,fn->getPositionY()+57,70,35,"Magic");
     btnMagie->setIsMenuBoutton(true);

     btnAttack *btnDefend = new btnAttack(fn->getPositionX()+10,fn->getPositionY()+107,70,35,"Defend");
     BtnObject *btnObjet = new BtnObject(fn->getPositionX()+10,fn->getPositionY()+157,70,35,"Object");
     btnObjet->setIsMenuBoutton(true);

     //btnAttack *btnAttack2 = new btnAttack(fn2->getPositionX(),fn2->getPositionY()+100,80,50,"Feu");
     //btnAttack *btnAttack3 = new btnAttack(fn2->getPositionX(),fn2->getPositionY()+100,80,50,"Eau");
     //btnMagie->AddButton(btnAttack2);
     //btnMagie->AddButton(btnAttack3);
     fm = new FightManager();
     //Add Button  in fightManager
     fn->addButton(btnAtt);
     fn->addButton(btnMagie);
     fn->addButton(btnDefend);
     fn->addButton(btnObjet);
     //this->setSpriteMonster();
     //initialise fightManager in button
     for(int i = 0;i<fn->getVect().size();i++)
     {
      fn->getVect().at(i)->setFm(fm);
     }

     activate = 0;

     textureBackGroud = *TexturesManager::getInstance()->get("fight");
     sprintBackGroud.setTexture(textureBackGroud);



     //Delete pointer


}

FightScene::~FightScene()
{
    //dtor
    delete(fn);
    delete(barLife);
    delete(barMonsterLife);

}
void FightScene::setActivate(int activate)
{
    this->activate = activate;
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
       for(int j = 0;j<vectWindows.size();j++)
       {
        target.draw(vectWindows.at(j)->getRect());
        if(vectWindows.at(j)->getNbBoutton()+1 > 0)
        {
            vectWindows.at(secondWindowsActivate)->activateButton(activate);
            vectWindows.at(secondWindowsActivate)->getVect().at(activate)->setIsActivate(true);



           for(int i = 0; i<=vectWindows.at(j)->getNbBoutton();i++)
           {
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
       target.draw((barLife->getRect()),stat);
       target.draw((barMp->getRect()),stat);
       target.draw((barMonsterLife->getRect()),stat);
       //Get current and max value of Bar
       float current = fm->getPlayer()->Gethp();
       float maxx = fm->getPlayer()->GetmaxHp();

       float currentMp = fm->getPlayer()->Getmp();
       float maxxMp = fm->getPlayer()->GetmaxHp();

       float currentMHp = fm->getMonster()->Gethp();
       float maxxMHp = fm->getMonster()->GetmaxHp();




       //std::cout <<secondWindowsActivate<<endl;
       //Change the size of bar
       barLife->setBarLifeTaille(current,maxx);
       barMonsterLife->setBarLifeTaille(currentMHp,maxxMHp);
       target.draw(spriteMonster,stat);



}
void FightScene::eventHandler(Event ev)
{



 if(!isCurrentlyWrite)
 {

         if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
         {
             //rect.move(0,1);
             activate--;
         }
         else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
         {
             //rect.move(0,-1);
             activate++;

         }
         else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
         {
             //rect.move(1,0);
         }
         else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
         {
             //rect.move(-1,0);
         }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && clock.getElapsedTime().asSeconds() >0.5)
        {
                 clock.restart();
                 isCooldown = true;
                 for(int i = 0; i<=vectWindows.at(secondWindowsActivate)->getNbBoutton();i++)
                 {


                     std::cout <<secondWindowsActivate<<endl;

                      if(this->vectWindows.at(secondWindowsActivate)->getVect().at(i)->getisActivate() == true)
                      {


                          std::cout << "espace toucher" << std::endl;
                          vectWindows.at(secondWindowsActivate)->getVect().at(i)->action();
                          std::cout<<"it works 0 bitch : "<<std::endl<<getFightManager()->getMonster()->str();
                          if(fm->isFightFinish())
                          {
                              std::cout<<"it works 1 bitch : "<<std::endl<<getFightManager()->getMonster()->str();
                            if(fm->isPlayerWin())
                            {
                                std::cout<<"it works 2 bitch : "<<std::endl<<getFightManager()->getMonster()->str();
                               gotoPreviousScene();
                            }
                          }
                          else
                          {


                                 std::cout <<"isMenu" <<std::endl;
                                 if(vectWindows.at(secondWindowsActivate)->getVect().at(i)->getIsMenuBoutton())
                                 {
                                    fn2->ClearWindows();
                                  secondWindowsActivate = 1;
                                  //check Doublon ERREUR

                                     for(int j = 0 ;j <(fn->getVect().at(i)->getListButton().size());j++)
                                     {
                                          //std::cout << fn2->getVect().at(i)->getListButton().size() <<"nombre de bouton dans le bouton et j " << j <<endl;
                                          bool isCopie = false;
                                           for(int t = 0;t <fn2->getVect().size();t++)
                                           {
                                             if(fn2->getVect().at(t)->equals(fn->getVect().at(i)->getListButton().at(j)))
                                             {
                                              isCopie = true;
                                             }
                                           }
                                           if(isCopie == false)
                                           {
                                            fn2->addButton(fn->getVect().at(i)->getListButton().at(j));
                                           }


                                          //fn2->fn->getVect().at(i)->getListButton().
                                     }


                                 }
                                 else
                                 {
                                     //setText(vectWindows.at(secondWindowsActivate)->getVect().at(i)->getDescription());
                                     textWhichMustBeWrite=vectWindows.at(secondWindowsActivate)->getVect().at(i)->getDescription();
                                     isCurrentlyWrite = true;
                                     secondWindowsActivate =0;
                                 }




                               std::cout << "verif doublons" << std::endl;
                            }
                        }


                 }


          }
         //isCooldown = isEventActive;
        if(secondWindowsActivate == 1)
         {
             if(activate < 0)
             {
                 activate =fn2->getNbBoutton()-1;
             }
             else if(activate > fn2->getNbBoutton())
             {
                 setActivate(0);
             }
                std::cout << fn2->getNbBoutton()<< std::endl;

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

         }

 }
 else
 {
    /*
  if(clock.getElapsedTime().asMilliseconds()>200)
         {
          indexTextWhichMustBeWrite++;
          if(indexTextWhichMustBeWrite < textWhichMustBeWrite.length())
          {
           textCurrentlyWrite += textWhichMustBeWrite[indexTextWhichMustBeWrite];
           setText(textCurrentlyWrite);
           clock.restart();

          }
          else
          {
            isCurrentlyWrite= true;
          }
         }

        */


 }






}
//Getter of vector of windows
std::vector<WindowsFight*> FightScene::getVectWindows()const
{
    return vectWindows;
}
void FightScene::fight()
{
    /*
    sf::RenderWindow window;
    sf::CircleShape cercle;
    sf::CircleShape triangle(80,3);
    sf::RectangleShape rect;
    window.create(sf::VideoMode(1270,720),"papa");
    window.setFramerateLimit(4);
    int activate =0;
    //Modifier la position

    sf::Font ft;
    ft.loadFromFile("arial.ttf");


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



    window.setPosition(sf::Vector2i(0,0));
    window.setFramerateLimit(60);
    //creation de fenetre
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
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            rect.move(0,1);
            activate--;
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            rect.move(0,-1);
            activate++;fm->getMonster()->GetcharaName()
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            rect.move(1,0);
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            rect.move(-1,0);
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        {

            for(int i = 0; i<fn.getNbBoutton();i++)
            {

                if(fn.getVect().at(i)->getisActivate() == true)
                {
                    std::cout << "espace toucher" << std::endl;
                    fn.getVect().at(i)->action();
                }

            }

        }

        fn.activateButton(activate);
        fn.getVect().at(activate)->setIsActivate(true);
        //window.draw(cercle);
        //window.draw(rect);
        //window.draw(triangle);
        //window.draw(text);
        window.draw(fn.getRect());

       for(int i = 0; i<fn.getNbBoutton();i++)
       {
            sf::RectangleShape rr =fn.getVect().at(i)->getRect();
            window.draw(rr);
            sf::Text txt = fn.getVect().at(i)->getText();
            txt.setFont(ft);
            window.draw(txt);
            fn.getVect().at(i)->setIsActivate(false);

       }
       fn.getVect().at(activate)->setIsActivate(true);


        window.display();
        window.clear();
    }
    */

}
void FightScene::setFightManager(FightManager* fm)
{
 this->fm = fm;
}
FightManager* FightScene::getFightManager()const
{
 return fm;
}
Bar* FightScene::getBar()const
{
 return barLife;
}
Bar* FightScene::getBarMp()const
{
 return barMp;
}
Bar* FightScene::getBarMonsterLife()const
{
 return barMonsterLife;
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
 std::string lien = ("data/images/monsters/"+getFightManager()->getMonster()->GetcharaName()+".png");
 textureMonster = *TexturesManager::getInstance()->get("mob_boss");//"_" + getFightManager()->getMonster()->GetcharaName()
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
  * @todo: document this function
  */
void FightScene::setPlayer()
{

}

/** @brief setSpritePlayer
  *
  * @todo: document this function
  */
void FightScene::setSpritePlayer()
{

}
/** @brief WriteText
  *
  * @todo: document this function
  */
void FightScene::WriteText()
{
    std::cout <<"ecrire"<<std::endl;
    while(this)
    {

        if(isCurrentlyWrite)
        {
                  std::this_thread::sleep_for(std::chrono::milliseconds(20));

                  if(indexTextWhichMustBeWrite < textWhichMustBeWrite.length())
                  {
                   textCurrentlyWrite += textWhichMustBeWrite[indexTextWhichMustBeWrite];
                   setText(textCurrentlyWrite);
                   clock.restart();
                   indexTextWhichMustBeWrite++;

                  }
                  else
                  {
                    isCurrentlyWrite= false;
                    indexTextWhichMustBeWrite =0;
                    textCurrentlyWrite="";
                  }

            }

    }



}







