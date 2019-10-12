#include "FightScene.h"

FightScene::FightScene()
{
    //ctor
}

FightScene::~FightScene()
{
    //dtor
}
void FightScene::fight()
{
    WindowsFight fn(150,500,600,200);
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
    */


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
        /*Gestion du clavier*/
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
        window.draw(cercle);
        window.draw(rect);
        window.draw(triangle);
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
}
