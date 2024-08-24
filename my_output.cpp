#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include "my_output.h"
#include "check_d.h"
#include "run_test.h"
#include "square_solver.h"

void  print_t_v    (struct pattern_for_tests pattern);
void  print_f_v    (struct pattern_for_tests pattern, enum SOLVE_SQUARE_RESULT result, double x1, double x2);
void  print_t      (struct pattern_for_tests pattern);
void  print_f      (struct pattern_for_tests pattern, enum SOLVE_SQUARE_RESULT result, double x1, double x2);

void output_roots   (FILE * const stream, \
                    const enum SOLVE_SQUARE_RESULT number_of_roots, \
                    double x1, double x2)
{
    assert (stream != NULL);
    assert (my_is_finite (x1));
    assert (my_is_finite (x2));

    switch (number_of_roots)
    {
        case NO_ROOTS:
        {
            fprintf (stream, "There is no roots\n");
            break;
        }
        case ONE_ROOT:
        {
            fprintf (stream, "Roots are similar and equal %.5lf\n", x1);
            break;
        }
        case TWO_ROOTS:
        {
            fprintf (stream, "There are 2 roots\nx1 = %.5lf\nx2 = %.5lf\n", x1, x2);
            break;
        }
        case ALL:
        {
            fprintf (stream, "Roots are all real numbers\n");
            break;
        }
        case LINE:
        {
            fprintf (stream, "There is only one root because it is lineal equation\nx = %.5lf\n", x1);
            break;
        }
        default:
        {
            fprintf (stream, "Invalid value for \"number_of_roots\" with type SOLVE_SQUARE_RESULT.\n");
            assert (0 && "Invalid SOLVE_SQUARE_RESULT value");
            break;
        }
    }
}

void print (const struct pattern_for_tests pattern, \
            const enum SOLVE_SQUARE_RESULT result, const double x1, const double x2, \
            const bool truth)
{
    assert (my_is_finite (x1));
    assert (my_is_finite (x2));

    if (pattern.verbose)
    {
        if (truth)
        {
        print_t_v (pattern);
        return;
        }
        print_f_v (pattern, result, x1, x2);
        return;
    }
    if (truth)
    {
        print_t (pattern);
        return;
    }
    print_f (pattern, result, x1, x2);
}

void print_t_v (const struct pattern_for_tests pattern)
{
    fprintf (pattern.stream, ":  Test № %d is succeeded  :\n"
                             " The coefficients:\n"
                             " a :\n"
                             " %.5lf\n"
                             " b :\n"
                             " %.5lf\n"
                             " c :\n"
                             " %.5lf\n"
                             " The result:\n"
                             , pattern.number_of_test, pattern.a, pattern.b, pattern.c);
    output_roots (pattern.stream, pattern.expect_result, pattern.expect_x1, pattern.expect_x2);
    fprintf (pattern.stream, "____________________________\n");
}

void print_f_v (const struct pattern_for_tests pattern, const enum SOLVE_SQUARE_RESULT result, const double x1, const double x2)
{
    assert (my_is_finite (x1));
    assert (my_is_finite (x2));

    fprintf (pattern.stream, ":  Error in test № %d.     :\n"
                             " The coefficients:\n"
                             " a :\n"
                             " %.5lf\n"
                             " b :\n"
                             " %.5lf\n"
                             " c :\n"
                             " %.5lf\n"
                             " Expected result:\n"
                             , pattern.number_of_test, pattern.a, pattern.b, pattern.c);
    output_roots (pattern.stream, pattern.expect_result, pattern.expect_x1, pattern.expect_x2);
    fprintf (pattern.stream, " Real result:\n");
    output_roots (pattern.stream, result, x1, x2);
    fprintf (pattern.stream, "____________________________\n");
}

void print_t (const struct pattern_for_tests pattern)
{
    fprintf (pattern.stream, ":  Test № %d is succeeded  :\n", pattern.number_of_test);
}

void print_f (const struct pattern_for_tests pattern, const enum SOLVE_SQUARE_RESULT result, const double x1, const double x2)
{
    assert (my_is_finite (x1));
    assert (my_is_finite (x2));

    fprintf (pattern.stream, ":  Error in test № %d.     :\n"
                             " Expected result:\n"
                             , pattern.number_of_test);
    output_roots (pattern.stream, pattern.expect_result, pattern.expect_x1, pattern.expect_x2);
    fprintf (pattern.stream, " Real result:\n");
    output_roots (pattern.stream, result, x1, x2);
}
