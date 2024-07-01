#include "maze.h"

int showMap = 0;
int isRaining = 0;
int enemyVisible = 1;

SDL_Texture *wallTexture;
SDL_Texture *floorTexture;
SDL_Texture *ceilingTexture;
SDL_Texture *enemyTexture;
SDL_Texture *weaponTexture;

int enemyPositions[MAX_ENEMIES][2] = {
	{1, 4},
	{5, 5},
	{11, 6},
	{2, 9},
	{3, 1}
};
