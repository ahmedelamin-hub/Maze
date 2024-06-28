#ifndef MAP_H
#define MAP_H

#include <stdlib.h>
#include <stdio.h>

#define MAP_WIDTH 24
#define MAP_HEIGHT 24

extern int world_map[MAP_WIDTH][MAP_HEIGHT];

void load_map(const char *file_path);

#endif /* MAP_H */
