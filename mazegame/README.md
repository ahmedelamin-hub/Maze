# SDL2 Maze Game

This is a 3D maze game inspired by Wolfenstein 3D, developed using SDL2 and raycasting. The player can navigate through the maze, avoid enemies, and find their way out.

## Features

- **3D Maze Rendering**: Uses raycasting to render a 3D view of the maze.
- **Player Movement**: Move forward, backward, left, and right within the maze.
- **Enemies**: Avoid enemies marked as blue dots on the minimap.
- **Minimap**: Shows an overhead view of the maze, including walls, enemies, and the player's position and orientation.
- **Weather Effects**: Toggle rain effects on or off.
- **Weapon Rendering**: Weapon appears in the player's hand and moves with the player.

## Controls

- **W**: Move forward
- **S**: Move backward
- **A**: Strafe left
- **D**: Strafe right
- **Left Arrow**: Rotate view left
- **Right Arrow**: Rotate view right
- **M**: Toggle minimap
- **F**: Toggle rain effect

## Installation

### Prerequisites

- Ubuntu 14.04 LTS
- GCC (Ubuntu 4.8.4-2ubuntu1~14.04) 4.8.4
- SDL2
- SDL2_image

### Clone the Repository

```sh
git clone https://github.com/ahmedelamin-hub/maze_game.git
cd maze_game
make 
./maze_game map.txt

