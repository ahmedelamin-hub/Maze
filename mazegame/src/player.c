#include "player.h"
#include "map.h"

/**
 * initialize_player - Initialize the player's position and direction
 * @player: Pointer to the player structure
 */
void initialize_player(Player *player)
{
	player->posX = 22.0;
	player->posY = 12.0;
	player->dirX = -1.0;
	player->dirY = 0.0;
	player->planeX = 0.0;
	player->planeY = 0.66;
}

/**
 * move_player - Move the player based on input
 * @player: Pointer to the player structure
 * @keystate: Array of key states
 */
void move_player(Player *player, const Uint8 *keystate)
{
	double moveSpeed = 0.05;
	double rotSpeed = 0.03;

	if (keystate[SDL_SCANCODE_W])
	{
		if (world_map[(int)(player->posX + player->dirX * moveSpeed)]
			[(int)(player->posY)] == 0)
		{
			player->posX += player->dirX * moveSpeed;
		}
		if (world_map[(int)(player->posX)]
			[(int)(player->posY + player->dirY * moveSpeed)] == 0)
		{
			player->posY += player->dirY * moveSpeed;
		}
	}

	if (keystate[SDL_SCANCODE_S])
	{
		if (world_map[(int)(player->posX - player->dirX * moveSpeed)]
			[(int)(player->posY)] == 0)
		{
			player->posX -= player->dirX * moveSpeed;
		}
		if (world_map[(int)(player->posX)]
			[(int)(player->posY - player->dirY * moveSpeed)] == 0)
		{
			player->posY -= player->dirY * moveSpeed;
		}
	}

	if (keystate[SDL_SCANCODE_D])
	{
		double oldDirX = player->dirX;
		player->dirX = player->dirX * cos(-rotSpeed)
					   - player->dirY * sin(-rotSpeed);
		player->dirY = oldDirX * sin(-rotSpeed)
					   + player->dirY * cos(-rotSpeed);

		double oldPlaneX = player->planeX;
		player->planeX = player->planeX * cos(-rotSpeed)
						 - player->planeY * sin(-rotSpeed);
		player->planeY = oldPlaneX * sin(-rotSpeed)
						 + player->planeY * cos(-rotSpeed);
	}

	if (keystate[SDL_SCANCODE_A])
	{
		double oldDirX = player->dirX;
		player->dirX = player->dirX * cos(rotSpeed)
					   - player->dirY * sin(rotSpeed);
		player->dirY = oldDirX * sin(rotSpeed)
					   + player->dirY * cos(rotSpeed);

		double oldPlaneX = player->planeX;
		player->planeX = player->planeX * cos(rotSpeed)
						 - player->planeY * sin(rotSpeed);
		player->planeY = oldPlaneX * sin(rotSpeed)
						 + player->planeY * cos(rotSpeed);
	}
}
