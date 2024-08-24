#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include "check_d.h"

bool is_INF (double x)
{
    return is_NAN (x * 0);
}

bool is_NAN (double x)
{
    return isnan (x);
}

bool my_is_finite (double x)
{
    return !(is_NAN (x) || is_INF (x));
}

bool is_equal (const double a, const double b)
{
    assert (my_is_finite (a));
    assert (my_is_finite (b));

    static const double ACCURACY = 0.0001;
    return (fabs(a - b) < ACCURACY);
}

bool is_null (const double number)
{
    assert (my_is_finite (number));

    return is_equal (number, 0);
}
