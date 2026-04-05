#include <stdio.h>
#include <assert.h>
#include <math.h>
#include "vectoria_level1.h"

static int eq(double a, double b) { return fabs(a - b) < 1e-12; }

int main(void)
{
    {
        // Base case (inc=1)
        double x[3] = {1, 2, 3};
        double y[3] = {10, 20, 30};

        vct_copy(3, x, 1, y, 1);

        double *px = x, *py = y;
        for (int i = 0; i < 3; i++, px++, py++)
        {
            assert(eq(*px, *py));
        }
    }
    {
        // n<=0
        double x[3] = {1, 2, 3};
        double y[3] = {10, 20, 30};
        double y_before[3] = {10, 20, 30};

        vct_copy(0, x, 1, y, 1);

        const double *pb = y_before;
        double *py = y;
        for (int i = 0; i < 3; i++, pb++, py++)
        {
            assert(eq(*pb, *py));
        }
    }
    {
        // inc=0
        double x[3] = {1, 2, 3};
        double y[3] = {10, 20, 30};
        double y_before[3] = {10, 20, 30};

        vct_copy(3, x, 0, y, 1);

        const double *pb = y_before;
        double *py = y;
        for (int i = 0; i < 3; i++, pb++, py++)
        {
            assert(eq(*pb, *py));
        }
    }
    {
        // inc=0
        double x[3] = {1, 2, 3};
        double y[3] = {10, 20, 30};
        double y_before[3] = {10, 20, 30};

        vct_copy(3, x, 1, y, 0);

        const double *pb = y_before;
        double *py = y;
        for (int i = 0; i < 3; i++, pb++, py++)
        {
            assert(eq(*pb, *py));
        }
    }
    {
        // inc != 1 (stride)
        double x[5] = {1, 2, 3, 4, 5};
        double y[3] = {10, 20, 30};
        double y_expected[3] = {1, 3, 5};

        vct_copy(3, x, 2, y, 1);

        const double *pe = y_expected;
        double *py = y;
        for (int i = 0; i < 3; i++, pe++, py++)
        {
            assert(eq(*py, *pe));
        }
    }
    {
        // inc != 1 (stride)
        double x[3] = {1, 2, 3};
        double y[5] = {10, 20, 30, 40, 50};
        double y_expected[5] = {1, 20, 2, 40, 3};

        vct_copy(3, x, 1, y, 2);

        const double *pe = y_expected;
        double *py = y;
        for (int i = 0; i < 5; i++, pe++, py++)
        {
            assert(eq(*py, *pe));
        }
    }
    {
        // inc<0
        double x[3] = {1, 2, 3};
        double y[3] = {10, 20, 30};
        double y_expected[3] = {3, 2, 1};

        vct_copy(3, &x[2], -1, y, 1);

        const double *pe = y_expected;
        double *py = y;
        for (int i = 0; i < 3; i++, pe++, py++)
        {
            assert(eq(*py, *pe));
        }
    }
    {
        // inc<0
        double x[3] = {1, 2, 3};
        double y[3] = {10, 20, 30};
        double y_expected[3] = {3, 2, 1};

        vct_copy(3, x, 1, &y[2], -1);

        const double *pe = y_expected;
        double *py = y;
        for (int i = 0; i < 3; i++, pe++, py++)
        {
            assert(eq(*py, *pe));
        }
    }
    printf("Ok\n");
    return 0;
}