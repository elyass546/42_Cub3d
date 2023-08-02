# cub3D

## Objective
cub3D is a graphic design project aimed at improving skills in windows, colors, events, and basic algorithms using C. It offers a remarkable playground to explore the playful practical applications of mathematics.

## Constraints
- Use the miniLibX library for smooth window management and graphics.
- Display different wall textures based on their orientation (North, South, East, West).
- Set floor and ceiling colors to two different ones.
- Implement smooth controls using arrow keys and WASD to navigate the maze.
- **ESC** key and **red cross** to cleanly close the window and exit the program.
- Utilize images from the miniLibX for optimal performance.

## Functionality
- The program takes a scene description file with the **.cub** extension as the first argument.
- The map must contain only 6 characters: **0** (empty space), **1** (wall), and **N/S/E/W** (player start and orientation).
- The map must be closed/surrounded by walls, or an error will be returned.
- Elements in the file can be separated by empty lines and set in any order.
- Each element's information can be separated by one or more spaces.
- Spaces within the map are considered valid and handled appropriately.

## Bonus Features
- Wall collisions
- Minimap system
- Doors that can open and close
- Animated sprites
- Rotating the point of view using the mouse

## Contributions
- **<a href="https://github.com/mkorchi">Mohamed Korchi</a>:** Implemented raycasting & textures, implemented doors, and created the minimap system.
- **<a href="https://github.com/elyass546">Ilias El Aabbassi</a>:** Handled parsing and provided textures, implemented smooth mouse-based rotation, and animated the gun for enhanced visual appeal.

## Conclusion
cub3D is an exciting project to showcase your C skills, algorithms, and graphics abilities. By leveraging miniLibX and mathematics, you can create visually engaging and efficient applications. Enjoy exploring the captivating world of cub3D!
