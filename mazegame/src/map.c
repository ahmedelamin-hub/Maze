#include "map.h"

int world_map[MAP_WIDTH][MAP_HEIGHT];

/**
 * load_map - Load the map from a file
 * @file_path: Path to the map file
 *
 * This function loads the map data from the specified file
 * and populates the world_map array.
 */
void load_map(const char *file_path)
{
	FILE *file = fopen(file_path, "r");

	if (!file)
	{
		perror("Error opening map file");
		exit(EXIT_FAILURE);
	}

	int i, j;

	for (i = 0; i < MAP_HEIGHT; i++)
	{
		for (j = 0; j < MAP_WIDTH; j++)
		{
			fscanf(file, "%d", &world_map[i][j]);
		}
	}

	fclose(file);
}
