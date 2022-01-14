#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "gnuplot.h"

#define TITLE       "teilaufgabe23"
#define FILENAME    "teilaufgabe23"

//  Computes the current y value
float _compute_value(float k) {
    return 10 / ( k * ( pow(logf(k), 2) ) );
}

PointsHolder plot(unsigned int iter) {

    PointsHolder points_holder = {malloc(0), 0};

    float y = 0;

    for(float k = 2; k <= iter; k += 0.1) {

        points_holder.point = (Point*) realloc(points_holder.point, (points_holder.size + 1) * sizeof(Point));
        points_holder.size++;

        Point* p_point = points_holder.point + points_holder.size - 1;
        p_point->x = k;
        p_point->y = 

        y += _compute_value(k);
    }

    return points;
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