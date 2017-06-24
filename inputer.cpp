#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#define LENGTH 50


/* Generate random number*/
void writeRandomCones(int cones) {

    for (int i = 0; i < cones; i++) {
        for (int j = 0; j < 6; j++) {
            float a = 10.0;
            float x = (float)rand()/(RAND_MAX/a);
            printf("%f\t", x);
        }
        float angle = rand() % (90 + 1);
        printf("%f\t\n", angle);
    }
}   //end of void writeRandomCones(int cones)

int main(void){
	writeRandomCones(10);
	return 0;
	
}