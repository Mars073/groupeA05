#include "FightScene.h"

FightScene::FightScene()
{
    //ctor
     fn = new WindowsFight(25,225,200,200);
     fn2 = new WindowsFightInfo(250,225,200,200);
     fn3 = new WindowsFightInfo(475,225,200,200);

     vectWindows.push_back(fn);
     vectWindows.push_back(fn2);
     vectWindows.push_back(fn3);
     btnAttack *btnMagie = new btnAttack(fn->getPositionX(),fn->getPositionY()+50,80,50,"Magie");
     btnMagie->setIsMenuBoutton(true);
     btnAttack *btnObjet = new btnAttack(fn2->getPositionX(),fn2->getPositionY()+50,80,50,"Object");
     btnAttack *btnAttack2 = new btnAttack(fn2->getPositionX(),fn2->getPositionY()+100,80,50,"Feu");
     btnMagie->AddButton(btnAttack2);

     fn->addButton(new btnAttack(*(btnMagie)));
     fn2->addButton(new btnAttack(*(btnObjet)));

     activate = 0;
}

FightScene::~FightScene()
{
    //dtor
    delete(fn);
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

    sf::Font ft = Resources::getFont("arial", "data/fonts/arial.ttf");
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
       for(int j = 0;j<vectWindows.size();j++)
       {
        target.draw(vectWindows.at(j)->getRect());
        if(vectWindows.at(j)->getNbBoutton()+1 > 0)
        {
            vectWindows.at(j)->activateButton(activate);
            vectWindows.at(j)->getVect().at(activate)->setIsActivate(true);



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

           vectWindows.at(j)->getVect().at(activate)->setIsActivate(true);
            vectWindows.at(j)->getVect().at(activate)->getDescription();
        }

       }

}
void FightScene::eventHandler(Event ev)
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

        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        {

            for(int i = 0; i<=fn->getNbBoutton();i++)
            {

                if(fn->getVect().at(i)->getisActivate() == true)
                {
                    std::cout << "espace toucher" << std::endl;
                    fn->getVect().at(i)->action();
                    std::cout << fn->getVect().at(i)->getIsMenuBoutton() <<"isMenu" <<std::endl;
                    if(fn->getVect().at(i)->getIsMenuBoutton())
                    {
                        for(int j = 0 ;j <fn->getVect().size();j++)
                        {
                             fn2->addButton(fn->getVect().at(i)->getListButton().at(j));
                             //fn2->fn->getVect().at(i)->getListButton().
                        }

                    }

                }

            }

        }
        if(activate < 0)
        {
            activate =fn->getNbBoutton();
        }
        else if(activate >= fn->getNbBoutton())
        {
            setActivate(0);
        }
        std::cout << fn->getNbBoutton()<< std::endl;
        fn->activateButton(activate);


}
//Getter of vector of windows
std::vector<WindowsFight*> FightScene::getVectWindows()
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
            activate++;
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
