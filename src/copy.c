#include "vectoria.h"

void vct_copy(int n, const double *x, double *y)
{
    if (n <= 0)
        return;
    for (int i = 0; i < n; i++)
        y[i] = x[i];
}