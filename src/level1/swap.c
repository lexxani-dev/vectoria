#include "vectoria_level1.h"
#include <stddef.h>

void vct_swap(int n, double *x, int incx, double *y, int incy)
{
    if (n <= 0 || x == NULL || y == NULL || incx == 0 || incy == 0)
        return;

    for (int i = 0; i < n; i++, x += incx, y += incy)
    {
        double tmp = *y;
        *y = *x;
        *x = tmp;
    }
}