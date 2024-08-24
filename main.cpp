#include <stdio.h>
#include <stdbool.h>
#include "settings_of_program.h"
#include "run_test.h"
#include "work_with_user.h"

int main (const int argc, char * const argv[])
{
    settings_of_program_t set = { stdin, stdout, false, false, false };

    parc_argv (argc, argv, &set);
    if (set.stop_program)
    {
        fclose (set.stream_in);
        fclose (set.stream_out);
        return 0;
    }
    if (set.test_or_user)
    {
        run_all_tests (set.stream_out, set.verbose);
    }
    else
    {
        user_version (set.stream_in, set.stream_out);
    }
    fclose (set.stream_in);
    fclose (set.stream_out);
}
