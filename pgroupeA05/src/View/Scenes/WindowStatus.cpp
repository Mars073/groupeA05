#include <View/Scenes/WindowStatus.h>

WindowStatus::WindowStatus()
{
    this->rectAll.setPosition(sf::Vector2f(50,50));
    this->rectAll.setSize(sf::Vector2f(500,400));
    this->rectAll.setOutlineThickness(5);
    this->rectAll.setOutlineColor(sf::Color(0,0,0));
    this->rectAll.setFillColor(sf::Color(75,52,251));

    this->rectMenu.setPosition(sf::Vector2f(60,60));
    this->rectMenu.setSize(sf::Vector2f(150,380));
    this->rectMenu.setOutlineThickness(5);
    this->rectMenu.setOutlineColor(sf::Color(255,255,255));
    this->rectMenu.setFillColor(sf::Color(253,67,0));

    this->p=new Player();
}

WindowStatus::~WindowStatus()
{
    delete p;
}

WindowStatus::WindowStatus(const WindowStatus& other)
{
    this->rectAll.setPosition(sf::Vector2f(50,50));
    this->rectAll.setSize(sf::Vector2f(200,200));
    this->rectAll.setOutlineThickness(5);
    this->rectAll.setOutlineColor(sf::Color(0,200,0));
    this->rectAll.setFillColor(sf::Color(255,0,0));

    this->rectMenu.setPosition(sf::Vector2f(60,60));
    this->rectMenu.setSize(sf::Vector2f(150,380));
    this->rectMenu.setOutlineThickness(5);
    this->rectMenu.setOutlineColor(sf::Color(255,255,255));
    this->rectMenu.setFillColor(sf::Color(253,67,0));

    this->p=other.p;
}

WindowStatus& WindowStatus::operator=(const WindowStatus& rhs)
{
    if (this != &rhs){
        this->rectAll.setPosition(sf::Vector2f(50,50));
        this->rectAll.setSize(sf::Vector2f(200,200));
        this->rectAll.setOutlineThickness(5);
        this->rectAll.setOutlineColor(sf::Color(0,200,0));
        this->rectAll.setFillColor(sf::Color(255,0,0));

        this->rectMenu.setPosition(sf::Vector2f(60,60));
        this->rectMenu.setSize(sf::Vector2f(150,380));
        this->rectMenu.setOutlineThickness(5);
        this->rectMenu.setOutlineColor(sf::Color(255,255,255));
        this->rectMenu.setFillColor(sf::Color(253,67,0));

        delete p;
        this->p=rhs.p;
    }
    //assignment operator
    return *this;
}

void WindowStatus::draw(RenderTarget& target, RenderStates states) const
{
    target.setView(View(FloatRect(0, 0, SingletonGame::W_WIDTH, SingletonGame::W_HEIGHT))); // HOT FIX
    Sprite sprite;
    Texture t = Resources::getTexture("bg_menu_status", "data/images/bg_menu_status.jpg");
    sprite.setTexture(t);
    target.draw(sprite, states);
    target.draw(rectAll, states);
    target.draw(rectMenu, states);
    Font f = Resources::getFont("arial", "data/fonts/arial.ttf");
    for (int i = 0; i < MENU_LENGTH; i++)
    {
        Text text(i==selected_id?"> "+menu[i]:menu[i], f);
        text.setCharacterSize(15);
        text.setFillColor(sf::Color::Black);
        text.setPosition(70, 70 + i*42);
        target.draw(text, states);
    }
}

void WindowStatus::eventHandler(Event event)
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
                gotoPreviousScene();
                break;
            }
        case Keyboard::Enter:
            {
                switch(selected_id)
                {
                case 0:
                    {
                        //status
                        SettextMenu(p->str());
                        break;
                    }
                case 1:
                    {
                        //equipment
                        //SettextMenu(p.str())
                        break;
                    }
                case 2:
                    {
                        //items

                        break;
                    }
                case 3:
                    {
                        //return to game
                        gotoPreviousScene();
                        break;
                    }

                default:
                    {
                        break;
                    }
                }
                break;
            }
            default: // no default action
            break;
        }
        selected_id = max(0, min((int)selected_id, (int) (MENU_LENGTH - 1)));
    }
}

void WindowStatus::SettextMenu(string val)
{
    Font f = Resources::getFont("arial", "data/fonts/arial.ttf");
    Text textMenu(val,f);
    textMenu.setCharacterSize(15);
    textMenu.setFillColor(sf::Color::Black);
    textMenu.setPosition(70, 70);
    //rectMenu.draw(textMenu);
}
