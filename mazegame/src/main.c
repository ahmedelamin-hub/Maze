#include <math.h>
#include <stdlib.h>
#include "maze.h"
#include "globals.h"
#include "render.h"

/**
 * main - Entry point of the program
 * @argc: Argument count
 * @argv: Argument vector
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(int argc, char *argv[])
{	

	SDL_Window *window; /* Pointer to the SDL window */
	SDL_Renderer *renderer; /* Pointer to the SDL renderer */
	SDL_Event e; /* SDL event structure for handling events */
	const Uint8 *state; /* Pointer to the current state of the keyboard */
	int quit = 0; /* Flag to control the main loop */

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <map file>\n", argv[0]); /* Print usage message */
		return (EXIT_FAILURE);
	}

	loadMap("assets/textures/map.txt");

	if (SDL_Init(SDL_INIT_VIDEO) < 0) /* Initialize SDL video subsystem */
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		return (EXIT_FAILURE);
	}

	if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG))
	{
		printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
		return (EXIT_FAILURE);
	}

	window = SDL_CreateWindow("SDL2 Maze Game",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		SCREEN_WIDTH, SCREEN_HEIGHT,
		SDL_WINDOW_SHOWN);
	if (window == NULL)
	{
		printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		SDL_Quit();
		return (EXIT_FAILURE);
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (renderer == NULL)
	{
		printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
		SDL_DestroyWindow(window);
		SDL_Quit();
		return (EXIT_FAILURE);
	}

	if (!loadTextures(renderer))
	{
		printf("Failed to load one or more textures!\n");
		SDL_DestroyRenderer(renderer);
		SDL_DestroyWindow(window);
		SDL_Quit();
		IMG_Quit();
		return (EXIT_FAILURE);
	}

	state = SDL_GetKeyboardState(NULL);

	while (!quit)
	{
		while (SDL_PollEvent(&e) != 0)
		{
			if (e.type == SDL_QUIT)
			{
				quit = 1;
			}
			else if (e.type == SDL_KEYDOWN)
			{
				handleKeyDown(e.key.keysym.sym);
			}
		}

		handleInput(state);

		SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF); /* Set the render draw color to black */
		SDL_RenderClear(renderer);

		renderScene(renderer);
		if (showMap)
		{
			drawMinimap(renderer);
		}

		renderEnemy(renderer);
		renderRain(renderer);

		SDL_Rect weaponRect = {SCREEN_WIDTH / 2 - 50, SCREEN_HEIGHT - 150, 100, 100};
		SDL_RenderCopyEx(renderer, weaponTexture, NULL, &weaponRect, -player.angle * (180 / PI), NULL, SDL_FLIP_NONE);

		SDL_RenderPresent(renderer);
	}

	destroyTextures();
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	IMG_Quit();
	return (EXIT_SUCCESS);
}
