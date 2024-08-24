#include <assert.h>
#include <math.h>
#include "square_solver.h"
#include "check_d.h"

enum SOLVE_SQUARE_RESULT solve_lineal (const double b, const double c, double * const x)
{
    assert (my_is_finite (b));
    assert (my_is_finite (c));

    assert (x != NULL);

    if (is_null (b))
    {
        return (is_null (c)) ? ALL : NO_ROOTS;
    }

    *x = -c / b;
    *x = (is_null (*x)) ? 0.0 : *x;
    return LINE;
}

enum SOLVE_SQUARE_RESULT solve_square   (const double a, const double b, const double c, \
                                        double * const x1, double * const x2)
{
    assert (my_is_finite (a));
    assert (my_is_finite (b));
    assert (my_is_finite (c));

    assert (x1 != NULL);
    assert (x2 != NULL);
    assert (x1 != x2);

    if (is_null (a))
    {
        return solve_lineal (b, c, x1);
    }

    double d = b * b - 4 * a * c;
    if (is_null (d))
    {
        *x1 = -b / (2 * a);
        *x1 = is_null(*x1) ? 0.0 : *x1;

        return ONE_ROOT;
    }

    if (d < 0)
    {
        return NO_ROOTS;
    }

    double sqrt_of_d = sqrt (d);

    *x1 = (-b + sqrt_of_d) / (2 * a);
    *x2 = (-b - sqrt_of_d) / (2 * a);

    *x1 = is_null(*x1) ? 0.0 : *x1;
    *x2 = is_null(*x2) ? 0.0 : *x2;

    return (is_equal (*x1, *x2)) ? ONE_ROOT : TWO_ROOTS;
}
