#include "vectoria_level1.h"
#include <math.h>
#include <stddef.h>

int vct_iamax(int n, const double *x, int incx)
{
    if (n <= 0 || x == NULL || incx == 0)
    {
        return -1;
    }

    int idx_max = 0;
    double max_val = fabs(*x);

    for (int i = 1; i < n; i++, x += incx)
    {
        if (fabs(*x) > max_val)
        {
            max_val = fabs(*x);
            idx_max = i;
        }
    }

    return idx_max;
}