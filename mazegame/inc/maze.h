#ifndef MAZE_H
#define MAZE_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define TILE_SIZE 64
#define ROTATION_SPEED 0.05
#define MOVE_SPEED 2.0
#define FOV 60
#define NUM_RAYS SCREEN_WIDTH
#define PI 3.14159265358979323846
#define MAP_WIDTH 24
#define MAP_HEIGHT 24
#define MAX_ENEMIES 10
#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

typedef struct {
	float x, y;
	float angle;
} Player;

extern Player player;
extern int map[MAP_WIDTH][MAP_HEIGHT];

SDL_Texture *loadTexture(SDL_Renderer *renderer, const char *path);
void loadMap(const char *filename);
void drawMinimap(SDL_Renderer *renderer);
void renderScene(SDL_Renderer *renderer);
void handleInput(const Uint8 *state);
void movePlayer(float moveX, float moveY);
int isWall(float x, float y);
void renderRain(SDL_Renderer *renderer);
void renderEnemy(SDL_Renderer *renderer);
void handleKeyDown(SDL_Keycode key);
int loadTextures(SDL_Renderer *renderer);
void destroyTextures(void);

#endif /* MAZE_H */
