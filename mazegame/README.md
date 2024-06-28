MazeGame
MazeGame is a 3D maze game inspired by Wolfenstein 3D. The game involves navigating through a maze, avoiding enemies, and finding your way to the exit.

# The Maze

MazeGame is a 3D maze game inspired by Wolfenstein 3D. The game involves navigating through a maze, avoiding enemies, and finding your way to the exit.

Features
3D Rendering with Raycasting: The game uses raycasting to render a 3D view of the maze.
Player Movement: Move through the maze using the keyboard.
Collision Detection: The player cannot pass through walls.
Textures: Textures are applied to walls, floors, and ceilings.
Enemies: Enemies are placed in the maze.
Weapon: The player has a weapon to interact with the game.
Minimap: A toggleable minimap is displayed.
Rain Effect: Toggleable rain effect.

### About SDL2 

Simple DirectMedia Layer is a cross-platform development library designed to provide low level access to audio, keyboard, mouse, joystick, and graphics hardware via OpenGL and Direct3D. It is used by video playback software, emulators, and popular games including Valve's award winning catalog and many Humble Bundle games.

## Installation 
```sh
$ git clone git@github.com:ahmedelamin-hub/Maze.git

```
## Usage 
* Execute ./maze or type make run 
Controls
Move Forward: W
Move Backward: S
Move Left: A
Move Right: D
Rotate Left: Left Arrow
Rotate Right: Right Arrow
Toggle Minimap: M
Toggle Rain: R

## Compilation
```sh
$ gcc -Wall -Werror -Wextra -pedantic ./src/*.c -lm -o maze `sdl2-config --cflags` `sdl2-config --libs`;
```

## Flowchart
![The Maze Flow Chart](https://i.imgur.com/t0MxNni.png)

## Author :black_nib:

- **AhmedElamin** <(https://github.com/ahmedelamin-hub)>
