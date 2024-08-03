#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "maps.h"

#define ROWS 30
#define COLUMNS 30


int select_map() {
    int opcion;
    printf("Select a map (0-3): ");
    scanf("%d", &opcion);
    return opcion;
}

void print_map(int map[ROWS][COLUMNS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; ++j) {
            if (map[i][j] == 1) {
                printf("#");
            } else {
                printf("·");
            }
        }
        printf("\n");
    }
}

int count_live_neighbours(int map[ROWS][COLUMNS], int r, int c) {
    int counter = 0;
    for (int i = r - 1; i <= r + 1; i++) {
        for (int j = c - 1; j <= c + 1; j++) {
            if (i >= 0 && i < ROWS && j >= 0 && j < COLUMNS && !(i == r && j == c)) {
                counter += map[i][j];
            }
        }
    }
    return counter;
}

void evolve(int map[ROWS][COLUMNS]) {
    int new_map[ROWS][COLUMNS] = {0};

    for (int y = 0; y < ROWS; ++y) {
        for (int x = 0; x < COLUMNS; ++x) {
            int live_neighbours = count_live_neighbours(map, y, x);

            if (map[y][x] == 1) {
                if (live_neighbours == 2 || live_neighbours == 3) {
                    new_map[y][x] = 1;
                }
            } else {
                if (live_neighbours == 3) {
                    new_map[y][x] = 1;
                }
            }
        }
    }

    // Copiar new_map a map
    memcpy(map, new_map, sizeof(new_map));
}


int main(void)
{

    printf("Game of Life in C \n\n");

    int map[ROWS][COLUMNS];
    int map_num = select_map();
    inicialize_map(map, map_num);

    for (int generation = 0; generation < 100; ++generation) {
        system("clear");
        printf("Generation: %d \n", generation);
        evolve(map);
        print_map(map);
        sleep(1);
    }

    return 0;
}
