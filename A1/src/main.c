#include <stdlib.h>
#include <stdio.h>
#include "gnuplot.h"

#define TITLE    "teilaufgabe21"
#define FILENAME "teilaufgabe21"

//  Computes the next value
float _next_value(float y) {
    return y / 3 + 1;
}

//  @iterations Number of iterations
//  @x          start value for x
//  @y          start value for y
//  @return     the accumulated value
//  Plots the function with GnuPlot
float plot(unsigned int iterations, float x, float y) {

    GnuPlotValue(x,y);

    if(x == iterations)
        return y;
    
    return plot(iterations, x + 1, _next_value(y));
}

int main() {

    unsigned int iterations;
    printf("Please enter the number of iterations: 100\n");
    scanf("%u", &iterations);

    GnuPlotOpen(TITLE,FILENAME);

    float result = plot(iterations, 0, 100);
    printf("a(%d) = %.2f", iterations, result);
    
    GnuPlotClose();
    return 0;
}