#include "vectoria.h"

void vct_swap(int n, double *x, double *y)
{
    if (n <= 0)
        return;
    for (int i = 0; i < n; i++)
    {
        double tmp = y[i];
        y[i] = x[i];
        x[i] = tmp;
    }
};