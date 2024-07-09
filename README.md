SDL2 Maze Game
This is a 3D maze game inspired by Wolfenstein 3D, developed using SDL2 and raycasting. Navigate through the maze, avoid enemies, and find your way out.

Features
3D Maze Rendering: Uses raycasting to render a 3D view of the maze.
Player Movement: Move forward, backward, left, and right within the maze.
Enemies: Avoid enemies marked as blue dots on the minimap.
Minimap: Shows an overhead view of the maze, including walls, enemies, and the player's position and orientation.
Weather Effects: Toggle rain effects on or off.
Weapon Rendering: Weapon appears in the player's hand and moves with the player.
Controls
W: Move forward
S: Move backward
A: Strafe left
D: Strafe right
Left Arrow: Rotate view left
Right Arrow: Rotate view right
M: Toggle minimap
F: Toggle rain effect
Installation
Prerequisites
Ubuntu 14.04 LTS
GCC (Ubuntu 4.8.4-2ubuntu1~14.04) 4.8.4
SDL2
SDL2_image
Usage
sh
نسخ الكود
# Clone the repo
git clone https://github.com/ahmedelamin-hub/maze_game.git
cd maze_game

# Build the project
make

# Run the game
./maze_game map.txt
Contribution
This project was done solo by me, Ahmed Elamin. Resources I consulted included the SDL2 tutorial and a raycasting tutorial.

Related Projects
Inspired by the classic game Wolfenstein 3D.

Licensing
This project is licensed under the MIT License. Feel free to use and modify it.

Technical Details
Ray Casting Algorithm
Goal: To render a 3D perspective from a 2D map.
Implementation: For each vertical strip on the screen, a ray is cast from the player's position, incrementally checking for wall collisions. The distance to the nearest wall is used to determine the height of the wall slice to render, creating the illusion of depth.
Challenges: Ensuring the rays were properly normalized within a 360-degree field and correcting the fish-eye effect by adjusting the ray distance based on the angle difference.

Texture Mapping
Goal: To apply textures to walls, floors, and ceilings for a more realistic appearance.
Implementation: Textures were loaded from image files and mapped onto the 3D-rendered surfaces using SDL. Careful attention was paid to texture coordinates to ensure they aligned correctly with the ray intersections.
Challenges: Handling different resolutions and ensuring performance remained high, even when rendering large textures.

Player Movement and Collision Detection
Goal: To allow smooth and responsive player movement while preventing the player from passing through walls.
Implementation: Player movement was managed by updating the player's position based on input, with collision detection checking if the new position would intersect with a wall.
Challenges: Balancing responsiveness with accurate collision detection, especially when dealing with diagonal movements.

Rendering Rain Effect
Goal: To create a dynamic weather effect that adds immersion.
Implementation: Randomly generating points on the screen and rendering them with transparency to simulate raindrops.
Challenges: Ensuring the rain effect did not hinder performance and looked visually appealing across different resolutions.

Enemy Rendering
Goal: To place and render enemies within the maze, making them appear when the player is in the same location.
Implementation: Enemies were rendered as textures at the player's position when their grid coordinates matched.
Challenges: Synchronizing enemy positions with the player’s view and ensuring that multiple enemies could be displayed correctly.

Inspiration for the Project
The inspiration for creating this maze game came from my long-standing fascination with classic 2D games and a desire to understand how they operate under the hood. Growing up playing games like "Pac-Man" and "The Legend of Zelda," I was always intrigued by how simple mechanics could create such engaging gameplay. I wanted to replicate that sense of wonder and challenge myself to build a game from scratch, using modern tools and techniques. This project became an opportunity to blend my love for nostalgia with my technical skills, pushing me to explore deeper into game development.

Links to the Project
Blog: 3D Maze Game Using SDL2
Google Slides: Project Presentation
Landing Page: Elmostafa Games
YouTube: Game Demo
Next Steps
This project, while not the most technically impressive application a recruiter or hiring manager might see, represents a significant learning journey for me. It showcases my ability to tackle complex problems, iterate on solutions, and continually improve. More importantly, it reflects my passion for game development and my determination to create engaging and enjoyable experiences.
