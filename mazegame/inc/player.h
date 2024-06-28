#ifndef PLAYER_H
#define PLAYER_H

#include <SDL2/SDL.h>

typedef struct {
    double posX;
    double posY;
    double dirX;
    double dirY;
    double planeX;
    double planeY;
    double moveSpeed;
    double rotSpeed;
} Player;

/**
 * initialize_player - Initialize player properties
 * @player: Pointer to the player structure
 *
 * This function initializes the player's position, direction,
 * and movement properties.
 */
void initialize_player(Player *player);

/**
 * move_player - Move the player based on keyboard input
 * @player: Pointer to the player structure
 * @keystate: Current state of the keyboard
 *
 * This function handles the movement of the player based on
 * the current keyboard state.
 */
void move_player(Player *player, const Uint8 *keystate);

/**
 * rotate_player - Rotate the player
 * @player: Pointer to the player structure
 * @angle: Rotation angle
 *
 * This function rotates the player's direction by the specified
 * angle.
 */
void rotate_player(Player *player, double angle);

#endif /* PLAYER_H */
