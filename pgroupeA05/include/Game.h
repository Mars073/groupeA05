#ifndef GAME_H
#define GAME_H

#include "HomeScene.h"

using namespace sf;

class Game
{
    private:
        static Game* instance;          //!< Singleton instance
        /** private constructor */
        Game();
        Scene* scene = new HomeScene;   //!< Pointer "Scene"
        RenderWindow* window = nullptr; //!< Pointer "RenderWindow"

    public:
        /** Access Singleton instance
         * \return A pointer of the Game instance
         */
        static Game* getInstance();
        /** instance destructor */
        virtual ~Game();

        /** Draw all of Game component */
        void draw();
        /** Access RenderWindow Instance */
        RenderWindow* getWindow();
        /** Set active Scene
         * \param ptr new Scene to set
         */
        void setScene(Scene*);
        /** Access active Scene */
        Scene* getScene();

        // Shortcuts game <-> window
        bool isOpen();
        bool pollEvent(Event&);
        void pollEvent();
        void close();
        void test_com();

};

#endif // GAME_H
