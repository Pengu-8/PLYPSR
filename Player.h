//
// Created by 123ye on 27/02/2025.
//

#ifndef PLAYER_H
#define PLAYER_H
#include <SDL.h>


class Player {
public:
    float direction_x = 0;
    float direction_y = 0;
    float location_x = 0;
    float location_y = 0;
    // float max_velocity_x = 9999;
    // float max_velocity_y = 9999;
    SDL_Event event;
    bool pressed = false;
    int width_distance;
    int height_distance;
    int window_width;
    int window_height;
    const Uint8* keyStates = SDL_GetKeyboardState(nullptr);
    SDL_Rect rect{};
    Player(int amount, int window_width, int window_height);
    void move();
};



#endif //PLAYER_H
