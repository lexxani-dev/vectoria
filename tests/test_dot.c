#include <stdio.h>
#include <assert.h>
#include <math.h>
#include "vectoria_level1.h"

static int eq(double a, double b) { return fabs(a - b) < 1e-12; }

int main(void)
{

    { // Base case
        double x[3] = {1, 2, 3}, y[3] = {4, 5, 6};
        assert(eq(vct_dot(3, x, y), 32.0));
    }
    { // n=0
        double x[] = {1}, y[] = {2};
        assert(eq(vct_dot(0, x, y), 0.00));
    }
    { // Negatives + zero-values
        double x[] = {-1, 0, 4}, y[] = {3, -4, -0.5};
        assert(eq(vct_dot(3, x, y), (-1) * 3 + 0 * (-4) + 4 * (-0.5)));
    }
    { // NaN
        double x[] = {NAN, 1}, y[] = {4, 3};
        double r = vct_dot(2, x, y);
        assert(isnan(r));
    }
    { // Inf
        double x[] = {INFINITY, 1}, y[] = {2, 3};
        double r = vct_dot(2, x, y);
        assert(isinf(r));
    }
    { // +Inf * (negative) -> -Inf
        double x[] = {INFINITY, 1}, y[] = {-2, 0};
        double r = vct_dot(2, x, y);
        assert(isinf(r) && signbit(r));
    }
    { // -Inf * (negative) -> +Inf
        double x[] = {-INFINITY}, y[] = {-1};
        double r = vct_dot(1, x, y);
        assert(isinf(r) && !signbit(r));
    }
    { // Inf * 0 -> NaN
        double x[] = {INFINITY, 0}, y[] = {0, 1};
        double r = vct_dot(2, x, y);
        assert(isnan(r));
    }
    { // (+Inf) + (-Inf) in sum -> NaN
        double x[] = {INFINITY, INFINITY}, y[] = {1, -1};
        double r = vct_dot(2, x, y);
        assert(isnan(r));
    }
    { // Mixed without NaN -> +Inf
        double x[] = {INFINITY, 3}, y[] = {2, 4};
        double r = vct_dot(2, x, y);
        assert(isinf(r) && !signbit(r));
    }
    { // Product overflow
        double x[] = {__DBL_MAX__, 1}, y[] = {1.5, 0};
        double r = vct_dot(2, x, y);
        assert(isinf(r) && !signbit(r));
    }
    { // Summation overflow
        double x[] = {__DBL_MAX__ / 2, __DBL_MAX__ / 2}, y[] = {2, 2};
        double r = vct_dot(2, x, y);
        assert(isinf(r) && !signbit(r));
    }
    { // Product underflow -> DBL_MIN * 0.5 -> 0.0
        double x[] = {__DBL_MIN__}, y[] = {0.5};
        double r = vct_dot(1, x, y);
        assert(eq(r, 0.0));
    }
    { // Two tiny products -> both underflow to 0.0
        double x[] = {__DBL_MIN__, __DBL_MIN__}, y[] = {__DBL_MIN__, __DBL_MIN__};
        double r = vct_dot(2, x, y);
        assert(eq(r, 0.0));
    }
    { // Opposite signed tiny products -> both underflow to 0.0
        double x[] = {__DBL_MIN__, __DBL_MIN__}, y[] = {__DBL_MIN__, -__DBL_MIN__};
        double r = vct_dot(2, x, y);
        assert(eq(r, 0.0));
    }
    { // Just above 0 -> _DBL_MIN_ * 2 > 0
        double x[] = {__DBL_MIN__}, y[] = {2};
        double r = vct_dot(1, x, y);
        assert(r > 0.0);
    }

    printf("Ok\n");
    return 0;
}