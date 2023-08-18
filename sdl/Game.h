#ifndef __GAME_H__
#define __GAME_H__

#include <SDL2/SDL.h>
#include <SDL2/SDL_surface.h>
#include <stdio.h>
#include <iostream>
// #include "Texture.h"

class Game {
    public:
        struct Window {
            uint32_t m_width;
            uint32_t m_height;
            Window(const uint32_t width, const uint32_t height) : m_width(width), m_height(height) {}
        };
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
        Window* m_window;
        int counter{0};
        bool is_running_game;
        SDL_Window* window;
        SDL_Renderer* renderer;
        SDL_Texture* background;
};

#endif