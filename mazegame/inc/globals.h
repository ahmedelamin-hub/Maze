#ifndef GLOBALS_H
#define GLOBALS_H

extern int showMap;
extern int isRaining;
extern int enemyVisible;

extern SDL_Texture *wallTexture;
extern SDL_Texture *floorTexture;
extern SDL_Texture *ceilingTexture;
extern SDL_Texture *enemyTexture;
extern SDL_Texture *weaponTexture;

extern int enemyPositions[MAX_ENEMIES][2];

#endif /* GLOBALS_H */
