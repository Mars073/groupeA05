#include <SFML/Graphics.hpp>
#include <Game.h>
#include <SceneMap.h>

using namespace sf;

int main()
{
    RenderWindow window(VideoMode(640, 480), "Ceci n'est pas une pipe");

    Game *game = Game::get();
    SceneMap scene;

    game->setScene(scene);
    Game::window = &window;


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
            //->getScene().eventHandler(event);
            scene.eventHandler(event);
        }
        window.clear();
        //game->getScene().draw();
        scene.draw();
    }

    delete game;
    return 0;
}
