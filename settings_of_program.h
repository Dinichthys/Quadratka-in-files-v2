#ifndef SETTINGS_OF_PROGRAM
#define SETTINGS_OF_PROGRAM

#include <stdio.h>

typedef struct settings_of_program
{
    FILE* stream_in;
    FILE* stream_out;
    bool test_or_user;
    bool verbose;
    bool stop_program;
} settings_of_program_t;

void  parc_argv (int argc, char * const * argv, settings_of_program_t *set);

#endif
