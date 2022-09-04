#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "door_struct.h"

#define DOORS_COUNT 15
#define MAX_ID_SEED 10000

void sort(struct door *doors);
void close(struct door *doors);
void swap(int *d, int *k);
void output(struct door *doors);
void swap_doors(struct door *d1, struct door *d2);
void initialize_doors(struct door* doors);

int main() {
    struct door doors[DOORS_COUNT];
    initialize_doors(doors);
    sort(doors);
    close(doors);
    output(doors);
    return 0;
}

// Doors initialization function
// ATTENTION!!!
// DO NOT CHANGE!
void initialize_doors(struct door* doors) {
    srand(time(0));
    int seed = rand() % MAX_ID_SEED;
    for (int i = 0; i < DOORS_COUNT; i++) {
        doors[i].id = (i + seed) % DOORS_COUNT;
        doors[i].status = rand() % 2;
    }
}

void close(struct door *doors) {
    for (int i = 0; i < DOORS_COUNT; i++) {
        doors[i].status = 0;
    }
}

void swap(int *d, int *k) {
    int tmp = *d;
    *d = *k;
    *k = tmp;
}

void swap_doors(struct door *d1, struct door *d2) {
    swap(&d1->id, &d2->id);
}

void sort(struct door *doors) {
    for (int i = DOORS_COUNT; i > 0; --i) {
        for (int j = 0; j < i - 1; ++j) {
            if (doors[j].id > doors[j+1].id) {
                swap_doors(&doors[j], &doors[j+1]);
            }
        }
    }
}

void output(struct door *doors) {
    for (int i = 0; i < DOORS_COUNT; ++i) {
        printf("%d, %d", doors[i].id, doors[i].status);
        if (i != DOORS_COUNT - 1) {
            printf("\n");
        }
    }
}
