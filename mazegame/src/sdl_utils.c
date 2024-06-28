#include "sdl_utils.h"

/**
 * init_sdl - Initializes SDL, creates a window and renderer.
 * @window: Pointer to the SDL_Window.
 * @renderer: Pointer to the SDL_Renderer.
 */
void init_sdl(SDL_Window **window, SDL_Renderer **renderer)
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		fprintf(stderr, "SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}

	*window = SDL_CreateWindow("Maze Game",
							   SDL_WINDOWPOS_UNDEFINED,
							   SDL_WINDOWPOS_UNDEFINED,
							   640, 480,
							   SDL_WINDOW_SHOWN);
	if (!*window)
	{
		fprintf(stderr, "Window could not be created! SDL_Error: %s\n", SDL_GetError());
		SDL_Quit();
		exit(EXIT_FAILURE);
	}

	*renderer = SDL_CreateRenderer(*window, -1, SDL_RENDERER_ACCELERATED);
	if (!*renderer)
	{
		fprintf(stderr, "Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
		SDL_DestroyWindow(*window);
		SDL_Quit();
		exit(EXIT_FAILURE);
	}
}

/**
 * clean_up - Cleans up SDL, destroys the window and renderer.
 * @window: Pointer to the SDL_Window.
 * @renderer: Pointer to the SDL_Renderer.
 */
void clean_up(SDL_Window *window, SDL_Renderer *renderer)
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

/**
 * load_texture - Loads a texture from a file.
 * @renderer: The SDL_Renderer to render the texture.
 * @file: The file path of the texture.
 * Return: The loaded SDL_Texture.
 */
SDL_Texture *load_texture(SDL_Renderer *renderer, const char *file)
{
	SDL_Texture *texture = IMG_LoadTexture(renderer, file);
	if (!texture)
	{
		fprintf(stderr, "Failed to load texture %s! SDL_image Error: %s\n",
				file, IMG_GetError());
	}
	return (texture);
}
