# so_long
 [![Intro](https://img.shields.io/badge/Cursus-so_long-success?style=for-the-badge&logo=42)](https://github.com/MashkaCoder/so_long.git)<br>
This project is a small 2D game with minilibx.  <br>

![gif_01](https://github.com/MashkaCoder/so_long/blob/main/giphy.gif)
## Cloning <br>
```
git clone hhttps://github.com/MashkaCoder/so_long.git
cd so_long
make
```
## Make commands

- `make` to compile mandatory part. <br>
- `make bonus` to compile with bonuses(enemies and animation). <br>
- `make clean` to clean all object files of libft. <br>
- `make fclean` to remove executable files. <br>
- `make re` to recompile this project.<br>

## Usage <br>

To launch the game without enemies and animations you need to compile the project, then run the executable file and specify the map. 
```
make
./so_long maps/valid1.ber
```
To launch the game with enemies and animations you need to compile the project, then run the executable file and specify the map. 
```
make bonus
./so_long maps/valid_bonus.ber
```
## Characters of map
-  `0` for an empty space
-  `1` for a wall
-  `C` for a collectible
-  `E` for map exit 
-  `P` for the player’s starting position
-  `X` for enemy. (bonus part)

## Card requirements

- the map must have the extension `.ber`
- the map must be closed/surrounded by <b>walls</b>
- map must have at least <b>one exit</b>, <b>one collectible</b>, and <b>one starting position</b>
- the map must be rectangular

### Note

In the `maps` folder there are invalid maps (invalid...) for visualizing error workings, maps for the mandatory part (valid...) and maps for the bonus part (valid_bonus...)

## Subject
For more detailed information about the projects, you can read the task
 > [subject](en.subject.pdf)

