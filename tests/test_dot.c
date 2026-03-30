#include <stdio.h>
#include <assert.h>
#include <math.h>
#include "vectoria_level1.h"

static int eq(double a, double b) { return fabs(a - b) < 1e-12; }

int main(void)
{
    { // Base case (inc=1)
        double x[3] = {1, 2, 3}, y[3] = {4, 5, 6};
        assert(eq(vct_dot(3, x, 1, y, 1), 32.0));
    }
    { // n=0
        double x[] = {1}, y[] = {2};
        assert(eq(vct_dot(0, x, 1, y, 1), 0.00));
    }
    { // inc != 1
        // NOTE:
        // dot = sum_{i=0..n-1} x[i*incx] * y[i*incy]
        // -> there's potential for out of bounds exceptions
        // Required buffer lengths (assuming pointers refer to the first element used):
        //   len_x >= 1 + (n-1)*abs(incx)
        //   len_y >= 1 + (n-1)*abs(incy)
        double x[5] = {1, 2, 3, 4, 5}, y[3] = {6, 7, 8};
        assert(eq(vct_dot(3, x, 2, y, 1), 67.00));
    }
    { // inc < 0
        double x[3] = {1, 2, 3}, y[3] = {4, 5, 6};
        assert(eq(vct_dot(3, &x[2], -1, y, 1), 28.0));
    }
    { // incx=0 (incy is analogous)
        double x[3] = {1, 2, 3}, y[3] = {4, 5, 6};
        assert(eq(vct_dot(3, x, 0, y, 1), 0.00));
    }

    printf("Ok\n");
    return 0;
}