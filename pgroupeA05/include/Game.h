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
        /** Game window size */
        static const int W_WIDTH = 640;
        static const int W_HEIGHT = 480;
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
        void drawImage(const Texture&, int, int ,int ,int, int, int) const;
        void drawImage(const Texture&, int, int ,int ,int, int, int, int, int) const; // js like
        /** Access RenderWindow Instance */
        RenderWindow* getWindow() const;
        /** Set active Scene
         * \param ptr new Scene to set
         */
        void setScene(Scene*);
        /** Access active Scene */
        Scene* getScene() const;
        void resetView();

        // Shortcuts game <-> window
        bool isOpen() const;
        bool pollEvent(/*const*/ Event&) const;
        void pollEvent() const;
        void close() const;
        void test_com() const;

};

#endif // GAME_H
