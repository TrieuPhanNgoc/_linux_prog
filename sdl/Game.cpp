#include "Game.h"

Game::Game() {
}

Game::~Game() {
}

void Game::init_game(const char* title, int xpos, int ypos, int width, int height, bool isFullScreen) {
    int flags = 0;
    if (isFullScreen) {
        flags |= SDL_WINDOW_FULLSCREEN;
    }
    
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        std::cout << "Subsystem initialized!..." << std::endl;

        window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
        if (window) {
            std::cout << "Window created" << std::endl;
        }

        renderer = SDL_CreateRenderer(window, -1, 0);
        if (renderer) {
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            std::cout << "Renderer created" << std::endl;
        }

        texture = new Texture(renderer, "./assets/bg2.png");
        texture->Render(renderer, xpos, ypos, width, height);
        
        is_running_game = true;
    }
    else {
        is_running_game = false;
    }
}

void Game::handleEvents() {
    SDL_Event event;
    SDL_PollEvent(&event);
    switch (event.type) {
        case SDL_QUIT: {
            std::cout << "Event::Quit" << std::endl;
            is_running_game = false;
            break;
        }

        default: {
            break;
        }
    }
}
void Game::update_game() {
    counter++; // increment counter
    std::cout << "counter: " << counter << std::endl;
}
void Game::render_game() {
    SDL_RenderClear(renderer);
    // This is where we should add stuff to render
    SDL_RenderPresent(renderer);
}
void Game::clean_game() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout << "Game cleaned" << std::endl;
}
bool Game::running_game() { return is_running_game; }