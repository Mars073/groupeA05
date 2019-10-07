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
        /** instance destructor */
        ~Game();
        Scene* scene = new HomeScene;   //!< Pointer "Scene"
        RenderWindow* window = nullptr; //!< Pointer "RenderWindow"

    public:
        /** Prevent Singleton copy */
        Game(const Game&) = delete;
        Game(Game&&) = delete;
        Game& operator = (const Game&) = delete;
        Game& operator = (Game&&) = delete;
        /** Access Singleton instance
         * \return A pointer of the Game instance
         */
        static Game* getInstance();

        /** Draw all of Game component */
        void draw() const;
        /** Access RenderWindow Instance */
        RenderWindow* getWindow() const;
        /** Set active Scene
         * \param ptr new Scene to set
         */
        void setScene(Scene*);
        /** Access active Scene */
        Scene* getScene() const;

        // Shortcuts game <-> window
        bool isOpen() const;
        bool pollEvent(/*const*/ Event&) const;
        void pollEvent() const;
        void close() const;
        void test_com() const;

};

#endif // GAME_H
