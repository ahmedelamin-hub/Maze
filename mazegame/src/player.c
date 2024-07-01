#include "maze.h"
#include "globals.h"

Player player = {128, 128, 0};

/**
 * isWall - Checks if a position is a wall
 * @x: The x coordinate
 * @y: The y coordinate
 * Return: 1 if it is a wall, 0 otherwise
 */
int isWall(float x, float y)
{
	int mapX = (int)(x / TILE_SIZE);
	int mapY = (int)(y / TILE_SIZE);
	return (map[mapX][mapY] == 1);
}

/**
 * movePlayer - Moves the player by the specified amounts
 * @moveX: The amount to move on the x axis
 * @moveY: The amount to move on the y axis
 */
void movePlayer(float moveX, float moveY)
{
	if (moveX != 0)
	{
		float newX = player.x + moveX;
		if (!isWall(newX, player.y))
			player.x = newX;
	}

	if (moveY != 0)
	{
		float newY = player.y + moveY;
		if (!isWall(player.x, newY))
			player.y = newY;
	}
}
