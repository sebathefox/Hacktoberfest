/**
 * The file containing the main class of the program.
 * @file Game.h
 * @author Sebastian Davaris
 * @date 30-09-2019
 */

#ifndef GAME_GAME_H
#define GAME_GAME_H

#include <bits/unique_ptr.h>

namespace sf {
    class RenderWindow;
}

namespace game {
    /**
     * The main game class.
     * @author Sebastian Davaris
     * @date 30-09-2019
     */
    class Game {
    public:
        /**
         * The main constructor.
         * @author Sebastian Davaris
         * @date 30-09-2019
         */
        Game();

        /**
         * The Game Destructor.
         * @author Sebastian Davaris.
         * @date 30-09-2019
         */
        ~Game();

        /**
         * Begins the game.
         * @author Sebastian Davaris
         * @date 30-09-2019
         * @return zero when exiting successfully otherwise a non zero value.
         */
        int Run();
    private:
        /**
         * Starts all of the systems in order so that the game will run.
         * @author Sebastian Davaris
         * @date 30-09-2019
         */
        void StartSystems();

        /**
         * Loads all of the game's assets.
         * @author Sebastian Davaris
         * @date 30-09-2019
         */
        void LoadAssets();

        std::unique_ptr<sf::RenderWindow> m_window;
    };
}

#endif //GAME_GAME_H
