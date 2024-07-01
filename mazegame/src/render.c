#include "maze.h"
#include "globals.h"

/**
 * renderRain - Renders rain effect on the screen
 * @renderer: The SDL renderer
 */
void renderRain(SDL_Renderer *renderer)
{
	int i;
	int x, y;

	if (isRaining)
	{
		SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0x80);
		for (i = 0; i < 1000; i++)
		{
			x = rand() % SCREEN_WIDTH;
			y = rand() % SCREEN_HEIGHT;
			SDL_RenderDrawPoint(renderer, x, y);
		}
	}
}

/**
 * renderEnemy - Renders enemies on the screen
 * @renderer: The SDL renderer
 */
void renderEnemy(SDL_Renderer *renderer)
{
	int i;
	int mapX, mapY;
	SDL_Rect enemyRect;

	for (i = 0; i < MAX_ENEMIES; i++)
	{
		mapX = enemyPositions[i][0];
		mapY = enemyPositions[i][1];

		if ((int)(player.x / TILE_SIZE) == mapX &&
			(int)(player.y / TILE_SIZE) == mapY)
		{
			enemyRect.x = SCREEN_WIDTH / 2 - 32;
			enemyRect.y = SCREEN_HEIGHT / 2 - 32;
			enemyRect.w = 64;
			enemyRect.h = 64;
			SDL_RenderCopy(renderer, enemyTexture, NULL, &enemyRect);
		}
	}
}
