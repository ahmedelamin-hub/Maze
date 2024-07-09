#include "maze.h"
#include "globals.h"

/**
 * renderScene - Renders the 3D scene
 * @renderer: The SDL renderer
 */
void renderScene(SDL_Renderer *renderer)
{
	/* Calculate the starting angle of the first ray */
	float rayAngle = player.angle - (FOV / 2.0) * (PI / 180.0);
	float rayStep = FOV / (float)NUM_RAYS * (PI / 180.0);

	/* Define the rectangle for the ceiling and floor */
	SDL_Rect ceilingRect = {0, 0, SCREEN_WIDTH, SCREEN_HEIGHT / 2};
	SDL_Rect floorRect = {0, SCREEN_HEIGHT / 2, SCREEN_WIDTH, SCREEN_HEIGHT / 2};
	
	/* Define the rectangle for the ceiling and floor*/
	SDL_RenderCopy(renderer, ceilingTexture, NULL, &ceilingRect);
	SDL_RenderCopy(renderer, floorTexture, NULL, &floorRect);

	/* Loop through each ray */
	for (int i = 0; i < NUM_RAYS; i++)
	{
		if (rayAngle < 0)
			rayAngle += 2 * PI;
		if (rayAngle > 2 * PI)
			rayAngle -= 2 * PI;

		float distanceToWall = 0;
		int hitWall = 0;
		float eyeX = cos(rayAngle);
		float eyeY = sin(rayAngle);

		/* Loop until a wall is hit or the ray reaches the maximum distance */
		while (!hitWall && distanceToWall < SCREEN_WIDTH)
		{
			distanceToWall += 0.1;
			int testX = (int)(player.x + eyeX * distanceToWall) / TILE_SIZE;
			int testY = (int)(player.y + eyeY * distanceToWall) / TILE_SIZE;

			if (testX < 0 || testX >= MAP_WIDTH || testY < 0 || testY >= MAP_HEIGHT)
			{
				hitWall = 1;
				distanceToWall = SCREEN_WIDTH;
			}
			else if (map[testX][testY] == 1)
			{
				hitWall = 1;
			}
		}

		 /* Correct the distance to the wall to avoid fish-eye effect */
		float correctedDistance = distanceToWall * cos(rayAngle - player.angle);
		int wallHeight = (int)(SCREEN_HEIGHT / correctedDistance * 2.0);
		int ceiling = (SCREEN_HEIGHT / 2) - (wallHeight / 2);

		SDL_Rect wallRect = {i, ceiling, 1, wallHeight};
		SDL_RenderCopy(renderer, wallTexture, NULL, &wallRect);

		rayAngle += rayStep;
	}
}
