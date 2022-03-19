#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ATTEMPTS  100

int dice[6] = {4, 6, 8, 10, 12, 20};

int throwRandom(int faces) {
    return  rand() % faces;
}

int roll() {
    int tries = 0;
    int i = 0;
    while (i < 6) {
        int found = 0;
        while (found == 0 ) {
            tries++;
            if (throwRandom(dice[i]) == dice[i] - 1) {
                found = 1;
                i = i + 1;
            } else {
                i = 0;
            }
        }
    }
    return tries;
}

int main() {
    time_t t;
    srand((unsigned) time(&t));
    int min = 1000000000;
    int max = 0;
    double avg = 0.0;
    int total = 0;

    clock_t start = clock();

    for ( int i = 0; i < ATTEMPTS ; i++ ) {
        int tries = roll();
        if (tries < min) {
            min = tries;
        } 
        if (tries > max) {
            max = tries;
        }
        total += tries;
        avg = (double)total / (double)i;
    }

    clock_t end = clock();

    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;

    printf("min: %d, max: %d, avg: %f, total: %d \n", min, max, avg, total);
    printf("Time: %f ms\n", time_spent * 1000);
    return 0;

}


