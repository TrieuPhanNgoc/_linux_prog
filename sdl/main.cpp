#include <iostream>
#include "Game.h"

Game* game = nullptr;

int main() {
    // SDL_Init(SDL_INIT_VIDEO);
    // SDL_Window *window = SDL_CreateWindow("Hello World", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
    // SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);
    // SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    // SDL_RenderPresent(renderer);
    // SDL_Delay(3000);

    game = new Game();
    game->init_game("Window Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);
    while (game->running_game()) {
        game->handleEvents();
        game->update_game();
        game->render_game();
        
    }
    game->clean_game();
    std::cout << "Render finished" << std::endl;
    return 0;
}