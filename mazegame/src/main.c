#include "game.h"

/**
 * main - Entry point of the program
 * @argc: Argument count
 * @argv: Argument vector
 *
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on error
 */
int main(int argc, char *argv[])
{
	SDL_Window *window = NULL;
	SDL_Renderer *renderer = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <map file>\n", argv[0]);
		return (EXIT_FAILURE);
	}

	init_sdl(&window, &renderer);
	load_map(argv[1]);
	game_loop(window, renderer);
	clean_up(window, renderer);

	return (EXIT_SUCCESS);
}
