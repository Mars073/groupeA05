// *** ADDED BY HEADER FIXUP ***
#include <istream>
// *** END ***
#include "View/StrategyScene.h"
#include "View/Scenes/ConcreteStrategyHomeScene.h"
#include "View/Scenes/ConcreteStrategyMapScene.h"
#include "View/Scenes/ConcreteStrategyCreditsScene.h"
#include "Model/SingletonGame.h"

#include<iostream>
#include<algorithm>

ConcreteStrategyHomeScene::ConcreteStrategyHomeScene()
{
    sm->stopAll();
    sm->get("title")->setLoop(true);
    sm->play("title");
}

void ConcreteStrategyHomeScene::draw(RenderTarget& target, RenderStates states) const
{
    TexturesManager* tm = TexturesManager::getInstance();
    target.setView(View(FloatRect(0, 0, SingletonGame::W_WIDTH, SingletonGame::W_HEIGHT))); // HOT FIX
    Sprite sprite;
    Texture t = *tm->get("title");
    sprite.setTexture(t);
    target.draw(sprite, states);
    Font f = *fm->get("arial");
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
                        setScene(new ConcreteStrategyCreditsScene);
                        break;
                    }
                default:
                    win->close(); // Dans les autres cas on ferme
                }
                sm->stopAll();
                break;
            }
        default: // no default action
            break;
        }
        selected_id = max(0, min((int)selected_id, (int) (MENU_LENGTH - 1)));
    }
}
