#include <assert.h>
#include <stdio.h>
#include "work_with_user.h"
#include "square_solver.h"
#include "my_input.h"
#include "my_output.h"

void user_version (FILE * const stream_in, FILE * const stream_out)
{
    assert (stream_in != NULL);
    assert (stream_out != NULL);
    assert (stream_in != stream_out);

    double a  = 0.0;
    double b  = 0.0;
    double c  = 0.0;
    double x1 = 0.0;
    double x2 = 0.0;

    if (!(input_coefficients (stream_in, stream_out, &a, &b, &c)))
    {
        return;
    }
    enum SOLVE_SQUARE_RESULT number_of_roots = solve_square (a, b, c, &x1, &x2);
    output_roots (stream_out, number_of_roots, x1, x2);
}
