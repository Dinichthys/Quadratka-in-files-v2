#ifndef MY_OUTPUT_H
#define MY_OUTPUT_H

#include <stdbool.h>
#include <stdio.h>
#include "square_solver.h"
#include "run_test.h"

void  output_roots (FILE* stream, enum SOLVE_SQUARE_RESULT result, double x1, double x2);
void  print        (struct pattern_for_tests pattern, enum SOLVE_SQUARE_RESULT result, double x1, double x2, bool truth);

#endif
