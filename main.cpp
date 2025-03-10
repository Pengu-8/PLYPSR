#include <iostream>
#include <SDL.h>
#include <SDL_image.h>

#include "border.h"
#include "Player.h"

int main() {
    std::cout << "Initialising" << std::endl;
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
    }
    if (IMG_Init(IMG_INIT_PNG) < 0) {
        std::cout << "IMG_Init Error: " << IMG_GetError() << std::endl;
    }
    SDL_DisplayMode DM;
    SDL_GetCurrentDisplayMode(0, &DM);
    // int window_width = DM.w;
    // int window_height= DM.h;
    int window_width = 1600;
    int window_height = 800;
    SDL_Window* window = SDL_CreateWindow(
        "Game",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        window_width,
        window_height,
        SDL_WINDOW_OPENGL);
    if (window == nullptr) {std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;}
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == nullptr) {std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;}
    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);

    int amount = 8;


    Border border(amount,window_width,window_height);
    Player player(amount,window_width,window_height,border.location_square);

    for (int i = 0; i < amount*amount; i++) {
        std::cout << border.location_square[i].x << " "<< border.location_square[i].y << std::endl;

    }

    SDL_Event event;
    bool running = true;
    while (running) {
        SDL_PollEvent(&event);
        int tick_speed = 20;
        if (event.type == SDL_QUIT) {
            running = false;
        }
        if (SDL_GetTicks64() % tick_speed == 0) {
            player.move(event);
        }
        SDL_SetRenderDrawColor(renderer,154, 200, 254,100);
        SDL_RenderClear(renderer);

        SDL_SetRenderDrawColor(renderer,0, 0, 0,255);
        for (int i = 0; i < amount; i++) {
            SDL_RenderFillRect(renderer, &border.border1[i]);
            SDL_RenderFillRect(renderer, &border.border2[i]);
        }
        SDL_SetRenderDrawColor(renderer,35, 29, 44,100);
        SDL_RenderFillRect(renderer, &player.rect);
        SDL_RenderPresent(renderer);

    }
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
