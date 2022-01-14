#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "gnuplot.h"

#define TITLE       "teilaufgabe22"
#define FILENAME    "teilaufgabe22"

//  Computes the current y value
float _compute_value(float k) {
    return 10 / ( k * ( pow(logf(k), 2) ) );
}

//  Plots the function with GnuPlot
//  @iter   number of iterations
//  @return the accumulated value
float plot(unsigned int iter) {
    float y = 0;

    for(float k = 2; k <= iter; k += 0.1) {
        y += _compute_value(k);
        GnuPlotValue(k,y);
    }

    return y;
} 

int main() {
    
    unsigned int iterations;
    printf("Please enter the number of iterations: 100\n");
    scanf("%u", &iterations);

    GnuPlotOpen(TITLE, FILENAME);

    float result = plot(iterations);
    printf("%.2f", result);

    GnuPlotClose();
    return 0;
}