#include <stdio.h>
#include <assert.h>
#include <math.h>
#include "vectoria_level1.h"

static int eq(double a, double b) { return fabs(a - b) < 1e-12; }

int main(void)
{
    { // Base case (inc=1)
        double x[5] = {1, 2, 3, 4, 5};
        assert(eq(vct_absum(5, x, 1), 15.00));
    }
    { // n<=0
        double x[5] = {1, 2, 3, 4, 5};
        assert(eq(vct_absum(0, x, 1), 0.00));
    }
    { // inc!=1
        // NOTE:
        // absum = sum_{i=0..n-1} |x[i*incx]|
        // -> there is potential for out of bounds exceptions
        // Required buffer length (assuming pointers refer to the first element used):
        // len_x >= 1 + (n-1)*abs(incx)
        double x[5] = {1, 2, 3, 4, 5};
        assert(eq(vct_absum(5, x, 2), 9.00));
    }
    { // inc<0
        double x[5] = {1, 2, 3, 4, 5};
        assert(eq(vct_absum(5, &x[4], -1), 15.00));
    }
    { // inc=0
        double x[5] = {1, 2, 3, 4, 5};
        assert(eq(vct_absum(5, x, 0), 0.00));
    }
    printf("Ok\n");
    return 0;
}