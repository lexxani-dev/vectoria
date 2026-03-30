#include "vectoria_level1.h"
#include <stddef.h>

void vct_scal(int n, double alpha, double *x, int incx)
{
    if (n <= 0 || x == NULL || incx == 0 || alpha == 1.0)
        return;

    for (int i = 0; i < n; i++, x += incx)
    {
        *x = alpha * (*x);
    }
}

void vct_scal_copy(int n, double alpha, const double *x, int incx, double *y, int incy)
{
    if (n <= 0 || x == NULL || y == NULL || incx == 0 || incy == 0)
        return;

    for (int i = 0; i < n; i++, x += incx, y += incy)
    {
        *y = alpha * (*x);
    }
}