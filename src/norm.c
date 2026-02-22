#include <math.h>
#include "vectoria.h"

double vct_nrm2(int n, const double *x)
{
    if (n <= 0)
        return 0.0;
    double nrm2 = 0.0;
    for (int i = 0; i < n; i++)
    {
        nrm2 += x[i] * x[i];
    }
    return sqrt(nrm2);
}

double vct_absum(int n, const double *x)
{
    if (n <= 0)
        return 0.0;
    double sum = 0.0;
    for (int i = 0; i < n; i++)
    {
        sum += fabs(x[i]);
    }
    return sum;
}