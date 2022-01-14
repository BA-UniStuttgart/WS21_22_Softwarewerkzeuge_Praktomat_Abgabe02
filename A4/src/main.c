#include <stdlib.h>
#include <math.h>
#include "gnuplot.h"

#define TITLE "teilaufgabe24"   
#define FILENAME "teilaufgabe24"

//  y value for x in range 0..=9
double y_0_9(double x) {
    return 1 - (1 / exp(x));
}

//  y value for x in range 10..=17
double y_10_17(double x) {
    return 20 - pow(x - 14, 2);
}

//  y value for x in range 18..=22
double y_18_22(double x) {
    return 1 - 1 / exp(30 - x);
}

//  y value for x in range 23..=24
double y_23_24(double x) {
    return 2 * x - 45;
}

//  y value for x in range 25..=26
double y_25_26(double x) {
    return 5;
}

//  y value for x = 27
double y_27(double x) {
    return -4.2 * x + 118.4;
}

//  y value for x in range 28..=29
double y_28_29(double x) {
    return y_18_22(x);
}

//  y value for x in range 0..=29
double y(double x) {

    if(x >= 0 && x <= 9)
        return y_0_9(x);

    if(x >= 10 && x <= 17)
        return y_10_17(x);

    if(x >= 18 && x <= 22)
        return y_18_22(x);
    
    if(x >= 23 && x <= 24)
        return y_23_24(x);
    
    if(x >= 25 && x <= 26)
        return y_25_26(x);
    
    if(x == 27)
        return y_27(x);
    
    return y_28_29(x);
}

int main() {

    GnuPlotOpen(TITLE, FILENAME);

    for(double x = 0; x < 30; x += 1)
        GnuPlotValue(x, y(x));

    GnuPlotClose();
    return 0;
}