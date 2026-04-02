#include <stdio.h>
#include <assert.h>
#include <math.h>
#include "vectoria_level1.h"

static int eq(double a, double b) { return fabs(a - b) < 1e-12; }

int main(void)
{
    { // Base case (alpha>0, inc=1)
        double x[5] = {1, 2, 3};
        double y[3] = {10, 20, 30};
        double alpha = 2.0;
        double y_expected[3] = {12, 24, 36};

        vct_axpy(3, alpha, x, 1, y, 1);

        const double *pe = y_expected;
        double *py = y;
        for (int i = 0; i < 3; i++, pe++, py++)
            assert(eq(*py, *pe));
    }
    { // n<=0 (-> y must remain unchanged as n<=0 is invalid)
        double x[3] = {1, 2, 3};
        double y[3] = {10, 20, 30};
        double y_before[3] = {10, 20, 30};
        double alpha = 2;

        vct_axpy(0, alpha, x, 1, y, 1);

        const double *pb = y_before;
        double *py = y;
        for (int i = 0; i < 3; i++, pb++, py++) // inc=1 here
            assert(eq(*pb, *py));
    }
    { // inc=0 (-> y must remain unchanged as inc=0 is invalide stride)
        double x[3] = {1, 2, 3};
        double y[3] = {10, 20, 30};
        double y_before[3] = {10, 20, 30};
        double alpha = 2;

        vct_axpy(3, alpha, x, 0, y, 1);

        const double *pb = y_before;
        double *py = y;
        for (int i = 0; i < 3; i++, pb++, py++) // inc=1 here
            assert(eq(*pb, *py));
    }
    { // inc=0 (-> y must remain unchanged as inc=0 is invalide stride)
        double x[3] = {1, 2, 3};
        double y[3] = {10, 20, 30};
        double y_before[3] = {10, 20, 30};
        double alpha = 2;

        vct_axpy(3, alpha, x, 1, y, 0);

        const double *pb = y_before;
        double *py = y;
        for (int i = 0; i < 3; i++, pb++, py++) // inc=1 here
            assert(eq(*pb, *py));
    }
    { // inc != 1 (stride)
        double x[5] = {1, 2, 3, 4, 5};
        double y[3] = {10, 20, 30};
        double alpha = 2.0;
        double y_expected[3] = {12, 26, 40}; // y + 2*x_strided

        vct_axpy(3, alpha, x, 2, y, 1);

        const double *pe = y_expected;
        double *py = y;
        for (int i = 0; i < 3; i++, pe++, py++)
            assert(eq(*py, *pe));
    }
    { // inc != 1 (stride)
        double x[3] = {1, 2, 3};
        double y[5] = {10, 100, 20, 100, 30};
        double alpha = 2.0;
        double y_expected[5] = {12, 100, 24, 100, 36}; // y_strided + 2*x

        vct_axpy(3, alpha, x, 1, y, 2);

        const double *pe = y_expected;
        double *py = y;
        for (int i = 0; i < 5; i++, pe++, py++)
            assert(eq(*py, *pe));
    }
    { // inc<0
        double x[3] = {1, 2, 3};
        double y[3] = {10, 20, 30};
        double alpha = 2.0;
        double y_expected[3] = {16, 24, 32};

        vct_axpy(3, alpha, &x[2], -1, y, 1);

        const double *pe = y_expected;
        double *py = y;

        for (int i = 0; i < 3; i++, pe++, py++)
        {
            assert(eq(*py, *pe));
        }
    }
    { // inc<0
        double x[3] = {1, 2, 3};
        double y[3] = {10, 20, 30};
        double alpha = 2.0;
        double y_expected[3] = {12, 24, 36};

        vct_axpy(3, alpha, x, 1, &y[2], -1);

        const double *pe = y_expected;
        double *py = y;

        for (int i = 0; i < 3; i++, pe++, py++)
        {
            assert(eq(*py, *pe));
        }
    }
    { // alpha=0
        double x[3] = {1, 2, 3};
        double y[3] = {10, 20, 30};
        double alpha = 0.0;
        double y_expected[3] = {10, 20, 30};

        vct_axpy(3, alpha, x, 1, y, 1);

        const double *pe = y_expected;
        double *py = y;

        for (int i = 0; i < 3; i++, pe++, py++)
        {
            assert(eq(*py, *pe));
        }
    }
    { // alpha<0
        double x[3] = {1, 2, 3};
        double y[3] = {10, 20, 30};
        double alpha = -2.0;
        double y_expected[3] = {8, 16, 24};

        vct_axpy(3, alpha, x, 1, y, 1);

        const double *pe = y_expected;
        double *py = y;

        for (int i = 0; i < 3; i++, pe++, py++)
        {
            assert(eq(*py, *pe));
        }
    }
}