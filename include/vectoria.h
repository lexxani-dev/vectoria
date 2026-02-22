/* vectoria.h – Public API for Vectoria BLAS-like functions */
#ifndef VECTORIA_H
#define VECTORIA_H

#ifdef __cplusplus
extern "C"
{
#endif

    /*
     * Computes the dot product of two double-precision vectors.
     *
     * Parameters:
     *   n     – number of elements
     *   x     – pointer to first vector (points to the first element used)
     *   incx  – stride (step size) for x; may be negative to traverse backwards
     *   y     – pointer to second vector (points to the first element used)
     *   incy  – stride (step size) for y; may be negative to traverse backwards
     *
     * Operation:
     *   result ← result += x[i*incx] * y[i*incy] for i = 0...n-1
     *
     * Returns:
     *   The sum of x[i*incx] * y[i*incy] for i = 0...n-1
     *
     * Notes:
     *   - All vector pointers must point to arrays of at least 1 + (n-1)*abs(inc) elements.
     *   - Negative increments are supported. If inc < 0, the pointer must still refer to the
     *     first element used by the operation (e.g., for reverse traversal, pass a pointer to
     *     the last logical element).
     *   - Function does not modify input vectors.
     */
    double vct_dot(int n, const double *x, int incx, const double *y, int incy);

    /*
     * Scales a vector x by the scalar alpha (in-place).
     *
     * Parameters:
     *   n      – number of elements
     *   alpha  – scalar multiplier
     *   x      – pointer to vector to be scaled (in-place; points to the first element used)
     *   incx   – stride (step size) for x; may be negative to traverse backwards
     *
     * Operation:
     *   x[i*incx] ← alpha * x[i*incx] for i = 0...n-1
     *
     * Notes:
     *   - x must point to an array of at least 1 + (n-1)*abs(incx) elements.
     *   - Negative increments are supported. If incx < 0, the pointer must still refer to the
     *     first element used by the operation.
     */
    void vct_scal(int n, double alpha, double *x, int incx);

    /*
     * Scales a source vector x by the scalar alpha and stores the result in y (out-of-place).
     *
     * Parameters:
     *   n      – number of elements
     *   alpha  – scalar multiplier
     *   x      – pointer to source vector (input; points to the first element used)
     *   incx   – stride (step size) for x; may be negative to traverse backwards
     *   y      – pointer to destination vector (output; points to the first element used)
     *   incy   – stride (step size) for y; may be negative to traverse backwards
     *
     * Operation:
     *   y[i*incy] ← alpha * x[i*incx] for i = 0...n-1
     *
     * Notes:
     *   - All vector pointers must point to arrays of at least 1 + (n-1)*abs(inc) elements.
     *   - Negative increments are supported. If inc < 0, the pointer must still refer to the
     *     first element used by the operation.
     *   - x and y must not overlap.
     */
    void vct_scal_copy(int n, double alpha, const double *x, int incx, double *y, int incy);

    /*
     * Adds (or subtracts) a scaled vector x to/from vector y (in-place).
     *
     * Parameters:
     *   n      – number of elements
     *   alpha  – scalar multiplier (use negative for subtraction)
     *   x      – pointer to input vector to be scaled (points to the first element used)
     *   incx   – stride (step size) for x; may be negative to traverse backwards
     *   y      – pointer to input/output vector to which the result is added (points to the first element used)
     *   incy   – stride (step size) for y; may be negative to traverse backwards
     *
     * Operation:
     *   y[i*incy] ← alpha * x[i*incx] + y[i*incy] for i = 0...n-1
     *
     * Notes:
     *   - All vector pointers must point to arrays of at least 1 + (n-1)*abs(inc) elements.
     *   - Negative increments are supported. If inc < 0, the pointer must still refer to the
     *     first element used by the operation.
     */
    void vct_axpy(int n, double alpha, const double *x, int incx, double *y, int incy);

    /*
     * Adds (or subtracts) a scaled vector x to/from vector y and stores result in vector z (out-of-place).
     *
     * Parameters:
     *   n      – number of elements
     *   alpha  – scalar multiplier (use negative for subtraction)
     *   x      – pointer to input vector to be scaled (points to the first element used)
     *   incx   – stride (step size) for x; may be negative to traverse backwards
     *   y      – pointer to input vector to which the result is added (points to the first element used)
     *   incy   – stride (step size) for y; may be negative to traverse backwards
     *   z      – pointer to output vector to which the result is stored (points to the first element used)
     *   incz   – stride (step size) for z; may be negative to traverse backwards
     *
     * Operation:
     *   z[i*incz] ← alpha * x[i*incx] + y[i*incy] for i = 0...n-1
     *
     * Notes:
     *   - All vector pointers must point to arrays of at least 1 + (n-1)*abs(inc) elements.
     *   - Negative increments are supported. If inc < 0, the pointer must still refer to the
     *     first element used by the operation.
     *   - x, y, and z must not overlap in a way that affects the result.
     */
    void vct_axpy_copy(int n, double alpha, const double *x, int incx, const double *y, int incy, double *z, int incz);

    /*
     * Copies a vector x into a vector y.
     *
     * Parameters:
     *   n     – number of elements
     *   x     – pointer to input vector which is to be copied (points to the first element used)
     *   incx  – stride (step size) for x; may be negative to traverse backwards
     *   y     – pointer to output vector in which copy of x is to be stored (points to the first element used)
     *   incy  – stride (step size) for y; may be negative to traverse backwards
     *
     * Operation:
     *   y[i*incy] ← x[i*incx] for i = 0...n-1
     *
     * Notes:
     *   - All vector pointers must point to arrays of at least 1 + (n-1)*abs(inc) elements.
     *   - Negative increments are supported. If inc < 0, the pointer must still refer to the
     *     first element used by the operation.
     *   - x and y must not overlap.
     */
    void vct_copy(int n, const double *x, int incx, double *y, int incy);

    /*
     * Swaps the contents of two double-precision vectors element-wise (in-place).
     *
     * Parameters:
     *   n     – number of elements
     *   x     – pointer to first vector (points to the first element used)
     *   incx  – stride (step size) for x; may be negative to traverse backwards
     *   y     – pointer to second vector (points to the first element used)
     *   incy  – stride (step size) for y; may be negative to traverse backwards
     *
     * Operation:
     *   x[i*incx] ↔ y[i*incy] for i = 0...n-1
     *
     * Notes:
     *   - All vector pointers must point to arrays of at least 1 + (n-1)*abs(inc) elements.
     *   - Negative increments are supported. If inc < 0, the pointer must still refer to the
     *     first element used by the operation.
     *   - Swapping is done in-place without allocating extra memory.
     */
    void vct_swap(int n, double *x, int incx, double *y, int incy);

    /*
     * Computes the Euclidean (ℓ₂) norm of a double-precision vector.
     *
     * Parameters:
     *   n     – number of elements
     *   x     – pointer to input vector (points to the first element used)
     *   incx  – stride (step size) for x; may be negative to traverse backwards
     *
     * Operation:
     *   ‖x‖₂ = sqrt( Σ x[i*incx]² ) for i = 0...n-1
     *
     * Returns:
     *   The Euclidean norm of x.
     *
     * Notes:
     *   - x must point to an array of at least 1 + (n-1)*abs(incx) elements.
     *   - Negative increments are supported. If incx < 0, the pointer must still refer to the
     *     first element used by the operation.
     *   - Function does not modify the input vector.
     */
    double vct_nrm2(int n, const double *x, int incx);

    /*
     * Computes the Manhattan (ℓ₁) norm of a double-precision vector.
     *
     * Parameters:
     *   n     – number of elements
     *   x     – pointer to input vector (points to the first element used)
     *   incx  – stride (step size) for x; may be negative to traverse backwards
     *
     * Operation:
     *   ‖x‖₁ = Σ |x[i*incx]| for i = 0...n-1
     *
     * Returns:
     *   The Manhattan norm (absolute sum) of x.
     *
     * Notes:
     *   - x must point to an array of at least 1 + (n-1)*abs(incx) elements.
     *   - Negative increments are supported. If incx < 0, the pointer must still refer to the
     *     first element used by the operation.
     *   - Function does not modify the input vector.
     */
    double vct_asum(int n, const double *x, int incx);

    /*
     * Finds the index of the element with the largest absolute value in a double-precision vector.
     *
     * Parameters:
     *   n     – number of elements
     *   x     – pointer to input vector (points to the first element used)
     *   incx  – stride (step size) for x; may be negative to traverse backwards
     *
     * Operation:
     *   index = argmax_|x[i*incx]| for i = 0...n-1
     *
     * Returns:
     *   The index (0-based, i in 0...n-1) of the element with the largest absolute value.
     *
     * Notes:
     *   - x must point to an array of at least 1 + (n-1)*abs(incx) elements.
     *   - Negative increments are supported. If incx < 0, the pointer must still refer to the
     *     first element used by the operation.
     *   - If n <= 0, the function returns -1.
     *   - Function does not modify the input vector.
     */
    int vct_iamax(int n, const double *x, int incx);

#ifdef __cplusplus
}
#endif

#endif /* VECTORIA_H */