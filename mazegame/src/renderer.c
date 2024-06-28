#include "renderer.h"
#include "sdl_utils.h"
#include <stdlib.h>

static SDL_Texture *wallTexture;
static SDL_Texture *floorTexture;
static SDL_Texture *ceilingTexture;
static SDL_Texture *weaponTexture;
static SDL_Texture *enemyTexture;

/**
 * init_renderer - Initialize textures
 * @renderer: SDL renderer
 *
 * This function initializes the textures used in the game.
 */
void init_renderer(SDL_Renderer *renderer)
{
	wallTexture = load_texture(renderer, "assets/textures/wall_texture.png");
	if (!wallTexture)
	{
		fprintf(stderr, "Failed to load wall texture\n");
	}
	else
	{
		printf("Loaded wall texture\n");
	}

	floorTexture = load_texture(renderer, "assets/textures/floor_texture.png");
	if (!floorTexture)
	{
		fprintf(stderr, "Failed to load floor texture\n");
	}
	else
	{
		printf("Loaded floor texture\n");
	}

	ceilingTexture = load_texture(renderer,
				      "assets/textures/ceiling_texture.png");
	if (!ceilingTexture)
	{
		fprintf(stderr, "Failed to load ceiling texture\n");
	}
	else
	{
		printf("Loaded ceiling texture\n");
	}

	weaponTexture = load_texture(renderer, "assets/textures/weapon_texture.png");
	if (!weaponTexture)
	{
		fprintf(stderr, "Failed to load weapon texture\n");
	}
	else
	{
		printf("Loaded weapon texture\n");
	}

	enemyTexture = load_texture(renderer, "assets/textures/enemy_texture.png");
	if (!enemyTexture)
	{
		fprintf(stderr, "Failed to load enemy texture\n");
	}
	else
	{
		printf("Loaded enemy texture\n");
	}

	if (!wallTexture || !floorTexture || !ceilingTexture ||
	    !weaponTexture || !enemyTexture)
	{
		fprintf(stderr, "Failed to load one or more textures.\n");
		exit(EXIT_FAILURE);
	}
}

/**
 * clean_renderer - Clean up textures
 *
 * This function cleans up and frees the textures used in the game.
 */
void clean_renderer(void)
{
	SDL_DestroyTexture(wallTexture);
	SDL_DestroyTexture(floorTexture);
	SDL_DestroyTexture(ceilingTexture);
	SDL_DestroyTexture(weaponTexture);
	SDL_DestroyTexture(enemyTexture);
}

/**
 * render_floor_and_ceiling - Render floor and ceiling
 * @renderer: SDL renderer
 * @w: Width of the window
 * @h: Height of the window
 */
void render_floor_and_ceiling(SDL_Renderer *renderer, int w, int h)
{
	SDL_Rect floorRect = {0, h / 2, w, h / 2};
	SDL_Rect ceilingRect = {0, 0, w, h / 2};

	SDL_RenderCopy(renderer, floorTexture, NULL, &floorRect);
	SDL_RenderCopy(renderer, ceilingTexture, NULL, &ceilingRect);
}

/**
 * calculate_ray_direction - Calculate the direction of the ray
 * @player: Pointer to the player structure
 * @cameraX: X coordinate of the camera
 * @rayDirX: Pointer to the X direction of the ray
 * @rayDirY: Pointer to the Y direction of the ray
 */
void calculate_ray_direction(Player *player, double cameraX,
			     double *rayDirX, double *rayDirY)
{
	*rayDirX = player->dirX + player->planeX * cameraX;
	*rayDirY = player->dirY + player->planeY * cameraX;
}

/**
 * render_walls - Render the walls
 * @renderer: SDL renderer
 * @player: Pointer to the player structure
 * @w: Width of the window
 * @h: Height of the window
 */
void render_walls(SDL_Renderer *renderer, Player *player, int w, int h)
{
	int x;

	for (x = 0; x < w; x++)
	{
		double cameraX = 2 * x / (double)w - 1;
		double rayDirX, rayDirY;
		calculate_ray_direction(player, cameraX, &rayDirX, &rayDirY);

		int mapX = (int)player->posX;
		int mapY = (int)player->posY;

		double sideDistX;
		double sideDistY;

		double deltaDistX = (rayDirX == 0) ? 1e30 : fabs(1 / rayDirX);
		double deltaDistY = (rayDirY == 0) ? 1e30 : fabs(1 / rayDirY);
		double perpWallDist;

		int stepX;
		int stepY;

		int hit = 0;
		int side;

		if (rayDirX < 0)
		{
			stepX = -1;
			sideDistX = (player->posX - mapX) * deltaDistX;
		}
		else
		{
			stepX = 1;
			sideDistX = (mapX + 1.0 - player->posX) * deltaDistX;
		}
		if (rayDirY < 0)
		{
			stepY = -1;
			sideDistY = (player->posY - mapY) * deltaDistY;
		}
		else
		{
			stepY = 1;
			sideDistY = (mapY + 1.0 - player->posY) * deltaDistY;
		}

		while (hit == 0)
		{
			if (sideDistX < sideDistY)
			{
				sideDistX += deltaDistX;
				mapX += stepX;
				side = 0;
			}
			else
			{
				sideDistY += deltaDistY;
				mapY += stepY;
				side = 1;
			}
			if (world_map[mapX][mapY] > 0)
				hit = 1;
		}

		if (side == 0)
			perpWallDist = (mapX - player->posX + (1 - stepX) / 2) /
				       rayDirX;
		else
			perpWallDist = (mapY - player->posY + (1 - stepY) / 2) /
				       rayDirY;

		int lineHeight = (int)(h / perpWallDist);

		int drawStart = -lineHeight / 2 + h / 2;
		if (drawStart < 0)
			drawStart = 0;
		int drawEnd = lineHeight / 2 + h / 2;
		if (drawEnd >= h)
			drawEnd = h - 1;

		SDL_Rect wallRect = {x, drawStart, 1, drawEnd - drawStart};
		SDL_RenderCopy(renderer, wallTexture, NULL, &wallRect);
	}
}

/**
 * render_elements - Render additional elements (weapon, enemy)
 * @renderer: SDL renderer
 * @w: Width of the window
 * @h: Height of the window
 */
void render_elements(SDL_Renderer *renderer, int w, int h)
{
	SDL_Rect weaponRect = {w - 100, h - 100, 80, 80};
	SDL_Rect enemyRect = {w / 2 - 50, h / 2 - 50, 100, 100};
	SDL_RenderCopy(renderer, weaponTexture, NULL, &weaponRect);
	SDL_RenderCopy(renderer, enemyTexture, NULL, &enemyRect);
}

/**
 * render_map - Render the map
 * @renderer: SDL renderer
 */
void render_map(SDL_Renderer *renderer)
{
	int i, j;

	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	for (i = 0; i < MAP_HEIGHT; i++)
	{
		for (j = 0; j < MAP_WIDTH; j++)
		{
			if (world_map[i][j] > 0)
			{
				SDL_Rect rect = {j * 5, i * 5, 5, 5};
				SDL_RenderFillRect(renderer, &rect);
			}
		}
	}
}

/**
 * render_rain - Render the rain effect
 * @renderer: SDL renderer
 * @w: Width of the window
 * @h: Height of the window
 */
void render_rain(SDL_Renderer *renderer, int w, int h)
{
	int i, x, y;

	SDL_SetRenderDrawColor(renderer, 0, 0, 255, 100);
	for (i = 0; i < 100; i++)
	{
		x = rand() % w;
		y = rand() % h;
		SDL_RenderDrawLine(renderer, x, y, x, y + 5);
	}
}

/**
 * render_scene - Render the game scene
 * @renderer: SDL renderer
 * @player: Pointer to the player structure
 * @show_map: Integer to indicate if map should be shown
 * @show_rain: Integer to indicate if rain should be shown
 *
 * This function renders the game scene, including walls,
 * floor, ceiling, and other elements.
 */
void render_scene(SDL_Renderer *renderer, Player *player, int show_map,
	int show_rain)
{
	int w, h;

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);

	SDL_GetRendererOutputSize(renderer, &w, &h);

	render_floor_and_ceiling(renderer, w, h);
	render_walls(renderer, player, w, h);
	render_elements(renderer, w, h);

	if (show_map)
	{
		render_map(renderer);
	}

	if (show_rain)
	{
		render_rain(renderer, w, h);
	}
}
