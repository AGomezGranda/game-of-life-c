# Conway's Game of Life in C

The objective of this project is to create using the C programing language the Conway's Game of Life.

You can find more information about the game in the following link:
<https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life>

## How to run the program

To run the program you need to have the GCC compiler installed in your machine. If you don't have it installed you can download it from the following link:
<https://gcc.gnu.org/>

After you have the GCC compiler installed you can run the following command in the terminal to compile the program:

```bash
gcc -o game_of_life game_of_life.c
```

After you have compiled the program you can run the following command to execute the program:

```bash
./game_of_life
```

## How to play the game

The game is played in the terminal. When you run the program you will see a grid with cells that are alive represented by the character `#` and cells that are dead represented by the character `·`.

You will be asked to select the map that you want to play. You can select the map by typing the number of the map that you want to play 0 to 3 and pressing enter.

The map types are the following:

- **Map 0**: A simple map with a glider pattern
- **Map 1**: A simple map with a spacecraft pattern.
- **Map 2**: A simple map with a pentadecathlon pattern.
- **Map 3**: A simple map with a pulsar pattern.
