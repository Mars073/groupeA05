#include "View/StrategyScene.h"
#include "View/Scenes/ConcreteStrategyMapScene.h"
#include "Model/SingletonGame.h"

#include<iostream>
#include<algorithm>

ConcreteStrategyHomeScene::ConcreteStrategyHomeScene()
{
    //ctor
}

void ConcreteStrategyHomeScene::draw(RenderTarget& target, RenderStates states) const
{
    target.setView(View(FloatRect(0, 0, SingletonGame::W_WIDTH, SingletonGame::W_HEIGHT))); // HOT FIX
    Sprite sprite;
    Texture t = Resources::getTexture("title-background", "data/images/background-title.png");
    sprite.setTexture(t);
    target.draw(sprite, states);
    Font f = Resources::getFont("arial", "data/fonts/arial.ttf");
    for (int i = 0; i < MENU_LENGTH; i++)
    {
        Text text(i==selected_id?"> "+menu[i]:menu[i], f);
        text.setCharacterSize(30);
        text.setFillColor(sf::Color::White);
        text.setPosition(400, 220 + i*42);
        target.draw(text, states);
    }
}

void ConcreteStrategyHomeScene::eventHandler(Event event)
{
    if (event.type == Event::KeyPressed)
    {
        switch (event.key.code)
        {
        case Keyboard::Up:
            {
                selected_id--;
                break;
            }
        case Keyboard::Down:
            {
                selected_id++;
                break;
            }
        case Keyboard::Escape:
            {
                getWindow()->close();
                break;
            }
        case Keyboard::Enter:
            {
                RenderWindow* win = getWindow();
                switch(selected_id)
                {
                case 0:
                    {
                        // Lancer de jeu
                        ConcreteStrategyMapScene* s = new ConcreteStrategyMapScene;
                        setScene(s);
                        //s->playFXIntro();
                        break;
                    }
                case 1:
                    {
                        // Afficher Scene Credits
                        break;
                    }
                default:
                    win->close(); // Dans les autres cas on ferme
                }
                break;
            }
        default: // no default action
            break;
        }
        selected_id = max(0, min((int)selected_id, (int) (MENU_LENGTH - 1)));
    }
}
