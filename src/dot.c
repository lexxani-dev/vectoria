#include "vectoria.h"
#include <stdlib.h>

double vct_dot(int n, const double *x, int incx, const double *y, int incy)
{
  if (n <= 0 || x == NULL || y == NULL || incx == 0 || incy == 0)
  {
    return 0.0;
  }

  double s = 0.0;
  for (int i = 0; i < n; i++)
  {
    s += x[i] * y[i];
  }
  return s;
}