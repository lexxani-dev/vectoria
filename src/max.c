#include <math.h>
#include <stdlib.h>
#include "vectoria.h"

int vct_iamax(int n, const double *x)
{
    if (n <= 0 || x == NULL)
    {
        return -1;
    }
    int idx_max = 0;
    double max_val;
    if (!isnan(x[0]))
    {
        max_val = fabs(x[0]);
    }
    else
    {
        max_val = 0.0;
    }
    for (int i = 1; i < n; i++)
    {
        if (isnan(x[i]))
        {
            continue;
        }
        else if (!isfinite(x[i]))
        {
            max_val = fabs(x[i]);
            idx_max = i;
            break;
        }
        else if (fabs(x[i]) > max_val)
        {
            max_val = fabs(x[i]);
            idx_max = i;
        }
    }
    return idx_max;
}