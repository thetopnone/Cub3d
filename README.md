*This project has been created as part of the 42 curriculum by akonstan and mstawski*
# Cub3d
Cub is a baby wolf btw
## Description
This project is about creating a raycaster from scratch and make a small 3D navigating-through-a-maze game using the raycaster we created, similar to the Wolfenstein3D video game !!!
## Instructions
To compile the base project run `make` at the root of the repository.
To compile the bonus run `make bonus` at the root of the repository.
To clear object files run `make clean`
To clear all files created run `make fclean`

In order to run the base game, run this command at the root of the repository:
```
./cub3d <mapfilepath>
```
or for bonus:
```
./cub3d_bonus <mapfilepath>
```

**mapfilepath** is the path to a file with the *.cub* extension that has the format
```
NO ./path_to_the_north_texture
SO ./path_to_the_south_texture
WE ./path_to_the_west_texture
EA ./path_to_the_east_texture

F <valueR>,<valueG>,<valueB>
C <valueR>,<valueG>,<valueB>
```

Followed by a map blueprint with '1' representing walls, '0' representing floors, ' ' representing empty space,'N' 'S' 'E' 'W' representing the player spawn and it's orientation. For example:

```
11111111
10000001
1000N001
10011101
1001 101
10011101
10000001
11111111
```

For the bonus part, you can include up to 4 'D' characters to make doors in any wall you want.

## Resources
A very thorough explanation on raycasting from lodev: [here](https://lodev.org/cgtutor/raycasting.html)

Link to recreated browser version of [Wolfenstein3D](http://users.atw.hu/wolf3d/
)

An indispensible [MiniLibX Manual](https://harm-smits.github.io/42docs/libs/minilibx)

## AI Usage
*AI was used to assist with debugging, although admitedly it was very poor at it due to the complexity of the project. However sometimes it was spitting an idea that was useful and led to finding a fix of a bug. ZERO code has been copy-pasted or agent-generated in this project*
