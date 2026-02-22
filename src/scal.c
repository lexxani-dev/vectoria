#include "vectoria.h"

void vct_scal(int n, double alpha, double *x)
{
    if (n <= 0 || alpha == 1.0)
        return;
    for (int i = 0; i < n; i++)
    {
        x[i] = alpha * x[i];
    }
}

void vct_scal_copy(int n, double alpha, const double *x, double *y)
{
    if (n <= 0)
        return;
    for (int i = 0; i < n; i++)
    {
        y[i] = alpha * x[i];
    }
}