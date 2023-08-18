#ifndef _TEXTURE_
#define _TEXTURE_

#include "SDL2/SDL.h"
#include <SDL2/SDL_surface.h>
#include <iostream>

class Texture {
    public:
        Texture(SDL_Renderer* renderer, const std::string& imagePath);
        ~Texture();
        void Render(SDL_Renderer* renderer, int x, int y, int width, int height);

    private:
        /**
         * @brief This surface for saving background image
         * 
         */
        SDL_Surface* image = nullptr;

        /**
         * @brief 
         * 
         */
        SDL_Texture* texture = nullptr;
};

#endif // _TEXTURE_