//
// Created by Alvaro Gomez on 1/8/24.
//

#include "maps.h"

void empty_map(int map[ROWS][COLUMNS]) {
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLUMNS; ++j) {
            map[i][j] = 0;
        }
    }
}

void glider_map(int map[ROWS][COLUMNS]) {
    empty_map(map);
    map[1][2] = 1;
    map[2][3] = 1;
    map[3][1] = 1;
    map[3][2] = 1;
    map[3][3] = 1;
}

void spacecraft_map(int map[ROWS][COLUMNS]) {
    empty_map(map);
    map[2][1] = 1;
    map[2][4] = 1;
    map[3][5] = 1;
    map[4][1] = 1;
    map[4][5] = 1;
    map[5][2] = 1;
    map[5][3] = 1;
    map[5][4] = 1;
    map[5][5] = 1;
}

void pentadecathlon_map(int map[ROWS][COLUMNS]) {
    empty_map(map);
    int center_x = ROWS / 2;
    int center_y = COLUMNS / 2;
    for (int i = -5; i <= 5; i++) {
        if (i != -3 && i != 3) {
            map[center_x][center_y + i] = 1;
        }
    }
    map[center_x - 1][center_y - 3] = 1;
    map[center_x + 1][center_y - 3] = 1;
    map[center_x - 1][center_y + 3] = 1;
    map[center_x + 1][center_y + 3] = 1;
}

void pulsar_map(int map[ROWS][COLUMNS]) {
    empty_map(map);
    int center_x = ROWS / 2;
    int center_y = COLUMNS / 2;
    int offsets[] = {-6, -1, 1, 6};
    for (int i = 0; i < 4; i++) {
        for (int j = -2; j <= 2; j++) {
            if (j != 0) {
                map[center_x + offsets[i]][center_y + j] = 1;
                map[center_x + j][center_y + offsets[i]] = 1;
            }
        }
    }
}


void inicialize_map(int map[ROWS][COLUMNS], int map_num) {

    switch (map_num) {
        case 0:
            glider_map(map);
            break;
        case 1:
            spacecraft_map(map);
            break;
        case 2:
            pentadecathlon_map(map);
            break;
        case 3:
            pulsar_map(map);
            break;
        default:
            empty_map(map);
    }
}