#ifndef MATH_H
#define MATH_H

// CHDK floating point math functions

// Note: used in modules and platform independent code. 
// Do not add platform dependent stuff in here (#ifdef/#endif compile options or camera dependent values)

#define M_PI		3.14159265358979323846

extern double log(double x);
extern double log2(double x);
extern double log10(double x);
extern double pow(double x, double y);
extern double sqrt(double x);

#endif
