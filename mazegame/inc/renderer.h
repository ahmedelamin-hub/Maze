#ifndef RENDERER_H
#define RENDERER_H

#include <SDL2/SDL.h>
#include "player.h"
#include "map.h"

void init_renderer(SDL_Renderer *renderer);
void clean_renderer(void);
void render_scene(SDL_Renderer *renderer, Player *player, int show_map,
	int show_rain);
void render_floor_and_ceiling(SDL_Renderer *renderer, int w, int h);
void calculate_ray_direction(Player *player, double cameraX, double *rayDirX,
	double *rayDirY);
void render_walls(SDL_Renderer *renderer, Player *player, int w, int h);
void render_elements(SDL_Renderer *renderer, int w, int h);
void render_map(SDL_Renderer *renderer);
void render_rain(SDL_Renderer *renderer, int w, int h);

#endif /* RENDERER_H */
