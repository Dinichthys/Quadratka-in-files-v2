#include <stdio.h>
#include <assert.h>
#include "run_test.h"
#include "check_d.h"
#include "my_output.h"
#include "square_solver.h"

void  swap                             (enum SOLVE_SQUARE_RESULT result, double* x1, double* x2);
void  run_test                         (struct pattern_for_tests pattern);

void swap (const enum SOLVE_SQUARE_RESULT result, double * const x1, double * const x2)
{
    assert (x1 != NULL);
    assert (x2 != NULL);
    assert (x1 != x2);

    if ((result == TWO_ROOTS) && ((*x1 - *x2) < 0))
    {
        double change = *x1;
        *x1 = *x2;
        *x2 = change;
    }
}

void run_test (const struct pattern_for_tests pattern)
{
    assert (pattern.stream != NULL);
    assert (my_is_finite (pattern.a));
    assert (my_is_finite (pattern.b));
    assert (my_is_finite (pattern.c));
    assert (my_is_finite (pattern.expect_x1));
    assert (my_is_finite (pattern.expect_x2));

    double x1 = 0.0;
    double x2 = 0.0;

    enum SOLVE_SQUARE_RESULT result = solve_square (pattern.a, pattern.b, pattern.c, &x1, &x2);

    swap (result, &x1, &x2);

    if ((result != pattern.expect_result) ||
       (!(is_null (x1 - pattern.expect_x1))) ||
       (!(is_null (x2 - pattern.expect_x2))))
    {
        print (pattern, result, x1, x2, false);
        return;
    }
    print (pattern, result, x1, x2, true);
}

void run_all_tests (FILE * const stream, const bool verbose)
{
    assert (stream != NULL);

    int number_of_test = 1;

    static const struct pattern_for_tests pattern[] =
    {
        { stream, number_of_test++, 0,         0,        0,         ALL,       0,        0,       verbose },
        { stream, number_of_test++, 0,         0,        3.5,       NO_ROOTS,  0,        0,       verbose },
        { stream, number_of_test++, 0,         10,       4,         LINE,     -0.4,      0,       verbose },
        { stream, number_of_test++, 0,         3,        0,         LINE,      0,        0,       verbose },
        { stream, number_of_test++, 2.5,       5,        2.5,       ONE_ROOT, -1,        0,       verbose },
        { stream, number_of_test++, 1,        -7,        12,        TWO_ROOTS, 4,        3,       verbose },
        { stream, number_of_test++, 4,        -16,       15,        TWO_ROOTS, 2.5,      1.5,     verbose },
        { stream, number_of_test++,-2,         5,        0,         TWO_ROOTS, 2.5,      0,       verbose },
        { stream, number_of_test++, 1,        -2.82843,  2,         ONE_ROOT,  1.41421,  0,       verbose },
        { stream, number_of_test++, 0.33333,  -0.66666,  0.33333,   ONE_ROOT,  1,        0,       verbose },
        { stream, number_of_test++, 2.5,      -0.85833,  0.00833,   TWO_ROOTS, 0.33333,  0.01,    verbose }
    };
    number_of_test--;
    for (int i = 1; i < number_of_test; i++)
    {
        run_test (pattern [i]);
    }
    fprintf (stream, "All tests are done\n");
}
