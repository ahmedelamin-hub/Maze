#include "maze.h"
#include "globals.h"

int map[MAP_WIDTH][MAP_HEIGHT];

/**
 * loadMap - Loads the map from a file
 * @filename: The name of the file to load the map from
 */
void loadMap(const char *filename) /* Declare the map array with dimensions MAP_WIDTH x MAP_HEIGHT */
{
	FILE *file = fopen(filename, "r"); /* Open the map file in read mode */
	int i, j; /* Loop counters for map coordinates */
	char tile; /* Variable to store each tile read from the file */

	if (file == NULL)
	{
		perror("Failed to open map file"); /* Check if the file failed to open */
		exit(EXIT_FAILURE);
	}

	for (i = 0; i < MAP_HEIGHT; i++)
	{
		for (j = 0; j < MAP_WIDTH; j++)
		{
			fscanf(file, " %c", &tile);
			map[j][i] = tile - '0';
		}
	}

	fclose(file);
}

/**
 * drawMinimap - Draws the minimap on the screen
 * @renderer: The SDL renderer
 */
void drawMinimap(SDL_Renderer *renderer)
{
	int i, j; /* Loop counters for map coordinates */
	SDL_Rect rect, enemyRect, playerRect; /* Rectangles for drawing the map, enemies, and player */
	int lineX, lineY; /* Coordinates for the player's direction line */

	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

	for (i = 0; i < MAP_HEIGHT; i++) /* Loop through each row of the map */
	{
		for (j = 0; j < MAP_WIDTH; j++) /* Loop through each column of the map */
		{
			if (map[j][i] == 1)
			{
				rect.x = j * TILE_SIZE / 8;
				rect.y = i * TILE_SIZE / 8;
				rect.w = TILE_SIZE / 8;
				rect.h = TILE_SIZE / 8;
				SDL_RenderFillRect(renderer, &rect);
			}
		}
	}

	SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
	for (i = 0; i < MAX_ENEMIES; i++)
	{
		enemyRect.x = enemyPositions[i][0] * TILE_SIZE / 8;
		enemyRect.y = enemyPositions[i][1] * TILE_SIZE / 8;
		enemyRect.w = TILE_SIZE / 16;
		enemyRect.h = TILE_SIZE / 16;
		SDL_RenderFillRect(renderer, &enemyRect);
	}

	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	playerRect.x = player.x / 8;
	playerRect.y = player.y / 8;
	playerRect.w = TILE_SIZE / 16;
	playerRect.h = TILE_SIZE / 16;
	SDL_RenderFillRect(renderer, &playerRect);

	lineX = player.x / 8 + cos(player.angle) * 20;
	lineY = player.y / 8 + sin(player.angle) * 20;
	SDL_RenderDrawLine(renderer, player.x / 8 + TILE_SIZE / 32, player.y / 8 + TILE_SIZE / 32, lineX, lineY);
}
