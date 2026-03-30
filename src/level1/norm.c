#include "vectoria_level1.h"
#include <stddef.h>
#include <math.h>

double vct_nrm2(int n, const double *x, int incx)
{
    if (n <= 0 || x == NULL || incx == 0)
        return 0.0;

    double nrm2 = 0.0;

    for (int i = 0; i < n; i++, x += incx)
    {
        nrm2 += (*x) * (*x);
    }
    return sqrt(nrm2);
}