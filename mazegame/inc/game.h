#ifndef GAME_H
#define GAME_H

#include "sdl_utils.h"
#include "map.h"
#include "player.h"
#include "renderer.h"
#include <SDL2/SDL.h>
/**
 * game_loop - Main game loop
 * @window: SDL window
 * @renderer: SDL renderer
 *
 * This function contains the main game loop and handles
 * rendering and event processing.
 */
void game_loop(SDL_Window *window, SDL_Renderer *renderer);

#endif /* GAME_H */
