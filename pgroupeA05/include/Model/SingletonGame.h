#ifndef GAME_H
#define GAME_H

#include "View/Scenes/ConcreteStrategyHomeScene.h"

using namespace sf;

class SingletonGame
{
    private:
        static SingletonGame* instance;          //!< Singleton instance
        /** private constructor */
        SingletonGame();
        /** instance destructor */
        ~SingletonGame();
        StrategyScene* previous_scene = nullptr;//!< Pointer "Previous Scene"
        StrategyScene* scene = new ConcreteStrategyHomeScene;   //!< Pointer "Scene"
        RenderWindow* window = nullptr; //!< Pointer "Render Window"

    public:
        /** Game window size */
        static const int W_WIDTH = 640;
        static const int W_HEIGHT = 480;
        /** Prevent Singleton copy */
        SingletonGame(const SingletonGame&) = delete;
        SingletonGame(SingletonGame&&) = delete;
        SingletonGame& operator = (const SingletonGame&) = delete;
        SingletonGame& operator = (SingletonGame&&) = delete;
        /** Access Singleton instance
         * \return A pointer of the Game instance
         */
        static SingletonGame* getInstance();

        /** Draw all of Game component */
        void draw() const;
        void drawImage(const Texture&, int, int ,int ,int, int, int) const;
        void drawImage(const Texture&, int, int ,int ,int, int, int, int, int) const; // js like
        /** Access RenderWindow Instance */
        RenderWindow* getWindow() const;
        /** Set active Scene
         * \param ptr new Scene to set
         */
        void setScene(StrategyScene*);
        /** Access active Scene */
        StrategyScene* getScene() const;
        /** Set previous scene as current scene */
        void gotoPreviousScene();
        void resetView();

        // Shortcuts game <-> window
        bool isOpen() const;
        bool pollEvent(/*const*/ Event&) const;
        void pollEvent() const;
        void close() const;
        void test_com() const;

};

#endif // GAME_H
