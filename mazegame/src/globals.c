#include "maze.h"

/* Global variables for game state */
/* Indicates whether the map should be shown (0 = no, 1 = yes) */
/* Indicates whether it is raining in the game (0 = no, 1 = yes) */
/* Indicates whether enemies are visible (0 = no, 1 = yes) */
int showMap = 0;
int isRaining = 0;
int enemyVisible = 1;

/* Pointers to textures for different game elements */
SDL_Texture *wallTexture;
SDL_Texture *floorTexture;
SDL_Texture *ceilingTexture;
SDL_Texture *enemyTexture;
SDL_Texture *weaponTexture;

/* Array to store the positions of enemies */
int enemyPositions[MAX_ENEMIES][2] = {
	{1, 4},
	{5, 5},
	{11, 6},
	{2, 9},
	{3, 1}
};
