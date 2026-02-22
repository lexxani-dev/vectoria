#include "vectoria.h"
#include <stddef.h>
#include <math.h>

double vct_absum(int n, const double *x, int incx)
{
    if (n <= 0 || x == NULL || incx == 0)
        return 0.0;

    double sum = 0.0;

    for (int i = 0; i < n; i++, x += incx)
    {
        sum += fabs(*x);
    }
    return sum;
}