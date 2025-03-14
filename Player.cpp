//
// Created by 123ye on 27/02/2025.
//

#include <SDL.h>
#include "Player.h"

#include <iostream>
#include <ostream>
#include <vector>

Player::Player(int amount, int window_width, int window_height, std::vector<std::vector<SDL_Rect>> location_square):window_height(window_height),window_width(window_width),
                                                                                                       width_distance(window_width/amount),height_distance(window_height/amount),location_square(location_square) {
    rect.w = 50;
    rect.h = 50;
    // rect.x = (window_width/amount/2)-(rect.w/2);
    // rect.y = (window_height/amount/2)-(rect.h/2);
    rect.x = location_square[location_y][location_x].x;
    rect.y = location_square[location_y][location_x].y;
    std::cout << width_distance << " "<< height_distance << " " << window_width << " " << window_height << std::endl;
}


void Player::move(SDL_Event event) {
    if (keyStates[SDL_SCANCODE_A] || keyStates[SDL_SCANCODE_D] || keyStates[SDL_SCANCODE_W] || keyStates[SDL_SCANCODE_S]) {
    }
    else if (keyStates[SDL_SCANCODE_RETURN]) {
        pressed = false;
    }
    // if (event.type == SDL_MOUSEBUTTONDOWN) {
    //     std::cout << "button press" << std::endl;
    //     if (event.button.button == SDL_BUTTON_LEFT) {
    //         std::cout << "left button pressed"<<std::endl;
    //     }
    //     else if (event.button.button == SDL_BUTTON_RIGHT) {
    //         std::cout << "right button pressed"<<std::endl;
    //     }
    // }
    // else if (event.type == SDL_MOUSEBUTTONUP) {
    //     std::cout << "button release"<<std::endl;
    // }

    if (keyStates[SDL_SCANCODE_A] && not pressed)  {
        // if (location_x - width_distance >= 0) direction_x -= width_distance , location_x-=width_distance , pressed = true;
        if (location_x - direction_x >= 0) {
            location_x -= direction_x;
            rect.x = location_square[location_y][location_x].x;
        }
    }

    if (keyStates[SDL_SCANCODE_D] && not pressed)
        // if (location_x + width_distance < window_width) direction_x += width_distance, location_x+=width_distance,pressed = true;
        if (location_x + direction_x < 8) {
            location_x += direction_x;
            rect.x = location_square[location_y][location_x].x;
        }

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
