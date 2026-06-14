#include <stdio.h>
#include <unistd.h>
#include <time.h>

void make_box(){
    for (int i = 0; i < 4; i++){
        printf("##########\n");
    }
}

// measures the reaction time from the user and returns it
double measure_reaction() {
    struct timespec start, end;
    double elapsed;

    clock_gettime(CLOCK_MONOTONIC, &start); // starting time

    char ch = getchar(); // wait for Enter press

    clock_gettime(CLOCK_MONOTONIC, &end); // ending time

    elapsed = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1000000000.0;
    return elapsed;
}

// reads the best recorded time from 'best.bin'
double get_best(){
    double best;
    FILE *ptr = fopen("best.bin", "rb");

    if (fread(&best, sizeof(best), 1, ptr) != 1){
        printf("Best value could not be read.\n");
        fclose(ptr);
        return -1.0; //error
    };

    fclose(ptr); // close pointer
    return best;
}

// writes a best time value into 'best.bin'
int write_best(double x) {
    FILE *ptr = fopen("best.bin", "wb");

    if (fwrite(&x, sizeof(x), 1, ptr) != 1) {
        printf("Could not write best value.\n");
        fclose(ptr);
        return -1;
    };

    fclose(ptr); // close pointer
    return 0;
}

int main(){
    printf("Press `Enter` once the box appears.\n");
    fflush(stdout);

    sleep(1);

    make_box(); // visual stimuli

    double time = measure_reaction();

    printf("Reaction time: %lf seconds\n", time);

    double best = get_best(); // get best time
    printf("Your best time is: %lf\n", best);

    // check if time is better than best
    if (time < best) { // record new best
        write_best(time);
    } else { // print the current best
        printf("Your best time is: %lf\n", best);
    }
    
    return 0;
}

