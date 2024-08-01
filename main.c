#include <stdio.h>
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

int main(void)
{

    printf("Game of Life in C \n\n");

    int map[ROWS][COLUMNS];
    int map_num = select_map();
    inicialize_map(map, map_num);
    print_map(map);

    return 0;
}
