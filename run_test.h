#ifndef RUN_TEST_H
#define RUN_TEST_H

#include <stdbool.h>
#include <stdio.h>
#include "square_solver.h"

struct pattern_for_tests
{
    FILE* stream;

    int number_of_test;

    double a;
    double b;
    double c;

    enum   SOLVE_SQUARE_RESULT expect_result;
    double expect_x1;
    double expect_x2;

    bool verbose;
};

void  run_all_tests                    (FILE* stream, bool verbose);

#endif
