#include "maze.h"
#include "globals.h"

/**
 * handleKeyDown - Handles key down events
 * @key: The key that was pressed
 */

void handleKeyDown(SDL_Keycode key)/* Checks which key was pressed */
{
	switch (key)
	{
		case SDLK_m:
			showMap = !showMap;
			break;
		case SDLK_f:
			isRaining = !isRaining;
			break;
		default:
			break;
	}
}

/**
 * handleInput - Handles player input for movement and rotation
 * @state: The current state of the keyboard
 */
void handleInput(const Uint8 *state)
{
	float moveStep = 0;
	float moveX = 0;
	float moveY = 0;
	
	/* If the 'm' key was pressed */
	/* Toggle the showMap variable */
	/* If the 'f' key was pressed */
	/* Toggle the isRaining variable */
	if (state[SDL_SCANCODE_W])
		moveStep = MOVE_SPEED;
	else if (state[SDL_SCANCODE_S])
		moveStep = -MOVE_SPEED;

	if (state[SDL_SCANCODE_A])
		moveX = -MOVE_SPEED;
	else if (state[SDL_SCANCODE_D])
		moveX = MOVE_SPEED;

	if (state[SDL_SCANCODE_LEFT])
	{
		player.angle -= ROTATION_SPEED;
		if (player.angle < 0)
			player.angle += 2 * PI;
	}
	else if (state[SDL_SCANCODE_RIGHT])
	{
		player.angle += ROTATION_SPEED;
		if (player.angle > 2 * PI)
			player.angle -= 2 * PI;
	}

	if (moveStep != 0)
	{
		moveX += cos(player.angle) * moveStep;
		moveY += sin(player.angle) * moveStep;
	}

	movePlayer(moveX, moveY);
}
