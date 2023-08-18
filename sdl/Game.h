#ifndef __GAME_H__
#define __GAME_H__

#include <SDL2/SDL.h>
#include <stdio.h>
#include <iostream>
#include "Texture.h"

class Game {
    public:
        Game();
        ~Game();


        void init_game(const char* _title, int xpos, int ypos, int width, int height, bool isFullScreen);

        /**
         * @brief This function for events handling in the game
         * 
         */
        void handleEvents();
        void update_game();
        void render_game();
        void clean_game();

        bool running_game();

    private:
        int counter{0};
        bool is_running_game;
        SDL_Window* window;
        SDL_Renderer* renderer;
        Texture* texture;
};

#endif