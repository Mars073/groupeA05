#include "View/Scenes/ConcreteStrategryMenuScene.h"

ConcreteStrategyMenuScene::ConcreteStrategyMenuScene()
{
    //ctor
}

ConcreteStrategyMenuScene::~ConcreteStrategyMenuScene()
{
    //dtor
}

void ConcreteStrategyMenuScene::draw(RenderTarget& target, RenderStates states) const
{
    target.setView(View(FloatRect(0, 0, SingletonGame::W_WIDTH, SingletonGame::W_HEIGHT))); // HOT FIX
    Font f = Resources::getFont("arial", "data/fonts/arial.ttf");
    for (int i = 0; i < MENU_LENGTH; i++)
    {
        Text text(i==selected_id?"> "+menu[i]:menu[i], f);
        text.setCharacterSize(20);
        text.setFillColor(sf::Color::White);
        text.setPosition(80, 40 + i*24);
        target.draw(text, states);
    }
}
void ConcreteStrategyMenuScene::eventHandler(Event event)
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
                switch(selected_id)
                {
                case 0:
                    {
                        //back
                        gotoPreviousScene();
                        break;
                    }
                case 1:
                    {
                        //home
                        setScene(new ConcreteStrategyHomeScene);
                        break;
                    }
                case 2:
                    {
                        //map
                        setScene(new ConcreteStrategyMapScene);
                        break;
                    }
                case 3:
                    {
                        //scene
                        setScene(new FightScene);
                        break;
                    }
                default://credits, gameover
                    {
                        break;
                    }
                }
                break;
            }
        case Keyboard::Space:
            {
                //ouvrir le menu du personnage
                //setScene(new FightScene);
                //break;
            }
        default: // no default action
            break;
        }
        selected_id = max(0, min((int)selected_id, (int) (MENU_LENGTH - 1)));
    }
}
