#include "maze.h"
#include "globals.h"

/**
 * loadTexture - Loads a texture from a file
 * @renderer: The SDL renderer
 * @path: The path to the image file
 * Return: The loaded SDL texture
 */
SDL_Texture *loadTexture(SDL_Renderer *renderer, const char *path)
{
	SDL_Texture *newTexture = NULL;
	SDL_Surface *loadedSurface = IMG_Load(path);

	if (loadedSurface == NULL)
	{
		printf("Unable to load image %s! SDL_image Error: %s\n", path, IMG_GetError());
	}
	else
	{
		newTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
		if (newTexture == NULL)
		{
			printf("Unable to create texture from %s! SDL Error: %s\n", path, SDL_GetError());
		}
		SDL_FreeSurface(loadedSurface);
	}
	return (newTexture);
}

/**
 * loadTextures - Loads all required textures
 * @renderer: The SDL renderer
 * Return: 1 if all textures loaded successfully, 0 otherwise
 */
int loadTextures(SDL_Renderer *renderer)
{
	wallTexture = loadTexture(renderer, "assets/textures/wall.png");
	floorTexture = loadTexture(renderer, "assets/textures/floor.png");
	ceilingTexture = loadTexture(renderer, "assets/textures/ceiling.png");
	enemyTexture = loadTexture(renderer, "assets/textures/enemy.png");
	weaponTexture = loadTexture(renderer, "assets/textures/weapon.png");

	return (wallTexture && floorTexture && ceilingTexture && enemyTexture && weaponTexture);
}

/**
 * destroyTextures - Destroys all loaded textures
 */
void destroyTextures(void)
{
	SDL_DestroyTexture(wallTexture);
	SDL_DestroyTexture(floorTexture);
	SDL_DestroyTexture(ceilingTexture);
	SDL_DestroyTexture(enemyTexture);
	SDL_DestroyTexture(weaponTexture);
}
