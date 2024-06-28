#ifndef SDL_UTILS_H
#define SDL_UTILS_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

/**
 * init_sdl - Initialize SDL
 * @window: Pointer to the SDL window
 * @renderer: Pointer to the SDL renderer
 *
 * This function initializes SDL, creates the window and renderer.
 */
void init_sdl(SDL_Window **window, SDL_Renderer **renderer);

/**
 * clean_up - Clean up SDL resources
 * @window: SDL window
 * @renderer: SDL renderer
 *
 * This function cleans up and frees SDL resources.
 */
void clean_up(SDL_Window *window, SDL_Renderer *renderer);

/**
 * load_texture - Load a texture from a file
 * @renderer: SDL renderer
 * @file: Path to the texture file
 *
 * This function loads an image file as a texture.
 * Return: SDL_Texture pointer to the loaded texture.
 */
SDL_Texture *load_texture(SDL_Renderer *renderer, const char *file);

#endif /* SDL_UTILS_H */
