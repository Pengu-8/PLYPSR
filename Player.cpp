//
// Created by 123ye on 27/02/2025.
//

#include <SDL.h>
#include "Player.h"

#include <iostream>
#include <ostream>

Player::Player(int amount, int window_width, int window_height):window_height(window_height),window_width(window_width),
                                                                width_distance(window_width/amount),height_distance(window_height/amount) {
    rect.w = 50;
    rect.h = 50;
    rect.x = (window_width/amount/2)-(rect.w/2);
    rect.y = (window_height/amount/2)-(rect.h/2);
    std::cout << width_distance << " "<< height_distance << " " << window_width << " " << window_height << std::endl;
}


void Player::move() {
    if (keyStates[SDL_SCANCODE_A] || keyStates[SDL_SCANCODE_D] || keyStates[SDL_SCANCODE_W] || keyStates[SDL_SCANCODE_S]) {
    }
    else if (keyStates[SDL_SCANCODE_RETURN]) {
        pressed = false;
    }

    if (keyStates[SDL_SCANCODE_A] && not pressed)  {
        if (location_x - width_distance >= 0) direction_x -= width_distance , location_x-=width_distance , pressed = true;
    }
    // SDL_PollEvent(&event);
    //
    // if (event.type == SDL_KEYDOWN) {
    //     if (event.key.keysym.scancode == SDL_SCANCODE_D) {
    //         if (location_x + width_distance < window_width) {
    //             std::cout << location_x + width_distance << " " << window_width << std::endl;
    //             location_x += width_distance;
    //             pressed = true;
    //         }
    //     }
    // }

    if (keyStates[SDL_SCANCODE_D] && not pressed)
        if (location_x + width_distance < window_width) direction_x += width_distance, location_x+=width_distance,pressed = true;
        // {
        // if (location_x + width_distance < window_width) {
        //     std::cout << location_x + width_distance << " " << window_width << std::endl;
        //     location_x += width_distance;
        //     pressed = true;
        // }

    // }

    if (keyStates[SDL_SCANCODE_W] && not pressed)  {
        if (location_y - height_distance >= 0) direction_y -= height_distance,location_y-=height_distance,pressed = true;
    }

    if (keyStates[SDL_SCANCODE_S] && not pressed)  {
        if (location_y + height_distance < window_height) direction_y += height_distance,location_y+=height_distance,pressed = true;
    }

    // if (velocity_x > max_velocity_x) {
    //     velocity_x = max_velocity_x;
    // }
    // if (velocity_x < -max_velocity_x) {
    //     velocity_x = -max_velocity_x;
    // }
    // if (velocity_y < -max_velocity_y) {
    //     velocity_y = -max_velocity_y;
    // }
    // if (velocity_y > max_velocity_y) {
    //     velocity_y = max_velocity_y;
    // }
    // velocity_x *= 1;

    // velocity_y *= 0.9;

    rect.x += static_cast<int> (direction_x);
    direction_x = 0;
    rect.y += static_cast<int> (direction_y);
    direction_y = 0;
}
