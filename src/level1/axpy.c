#include "vectoria_level1.h"
#include <stddef.h>

void vct_axpy(int n, double alpha, const double *x, int incx, double *y, int incy)
{
    if (n <= 0 || x == NULL || y == NULL || incx == 0 || incy == 0)
        return;

    for (int i = 0; i < n; i++, x += incx, y += incy)
    {
        *y += alpha * (*x);
    }
}

void vct_axpy_copy(int n, double alpha, const double *x, int incx, const double *y, int incy, double *z, int incz)
{
    if (n <= 0 || x == NULL || y == NULL || incx == 0 || incy == 0 || incz == 0)
        return;

    for (int i = 0; i < n; i++, x += incx, y += incy, z += incz)
    {
        *z = alpha * (*x) + (*y);
    }
}