#include <stdio.h>
#include <assert.h>
#include <math.h>
#include "vectoria_level1.h"

int main(void)
{
    { // Base case (inc=1)
        double x[3] = {1, 2, 3};
        assert(vct_iamax(3, x, 1) == 2);
    }
    { // If max is ambiguous, first index of occurrence is expected
        double x[3] = {1, 2, 2};
        assert(vct_iamax(3, x, 1) == 1);
    }
    { // n<=0
        double x[3] = {1, 2, 3};
        assert(vct_iamax(0, x, 1) == -1);
    }
    { // inc=0
        double x[3] = {1, 2, 3};
        assert(vct_iamax(3, x, 0) == -1);
    }
    { // inc<0
        double x[3] = {1, 2, 3};
        assert(vct_iamax(3, &x[2], -1) == 0);
    }
    { // |max|
        double x[3] = {-7, 2, 3};
        assert(vct_iamax(3, x, 1) == 0);
    }
    printf("Ok\n");
    return 0;
}