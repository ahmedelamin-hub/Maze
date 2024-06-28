#include "game.h"

/**
 * game_loop - The main game loop
 * @window: The SDL_Window (unused)
 * @renderer: The SDL_Renderer
 */
void game_loop(SDL_Window *window, SDL_Renderer *renderer)
{
	(void)window; /* Mark the window parameter as unused */

	Player player;

	initialize_player(&player);

	int running = 1;
	SDL_Event event;
	int frame_count = 0;
	int show_map = 1;
	int show_rain = 1;

	while (running)
	{
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
				running = 0;
		}

		if (frame_count % 60 == 0)
		{
			printf("Rendering frame %d\n", frame_count);
		}

		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderClear(renderer);

		render_scene(renderer, &player, show_map, show_rain);

		SDL_RenderPresent(renderer);
		SDL_Delay(16);
		frame_count++;
	}

	printf("Exiting game loop\n");
}
