#include "vectoria_level1.h"
#include <stddef.h>

void vct_copy(int n, const double *x, int incx, double *y, int incy)
{
    if (n <= 0 || x == NULL || y == NULL || incx == 0 || incy == 0)
        return;

    for (int i = 0; i < n; i++, x += incx, y += incy)
        *y = *x;
}