#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <ctype.h>
#include "my_input.h"

bool is_end_of_input (FILE * const stream)
{
    assert (stream != NULL);

    int ch = 0;
    while ((((ch = getc (stream)) != '\n')) && (ch != EOF) && (isspace ((unsigned char)ch)))
    {
        ;
    }
    return ((ch == '\n') || (ch == EOF));
}

int clear_input (FILE * const stream)
{
    assert (stream != NULL);

    int ch = 0;
    while (((ch = getc (stream)) != '\n') && (ch != EOF))
    {
        ;
    }
    return ch;
}

bool input_coefficients (FILE * stream_in, FILE * stream_out,  \
                        double * const a, double * const b, double * const c)
{
    assert (stream_in != NULL);
    assert (stream_out != NULL);
    assert (stream_in != stream_out);
    assert (a != NULL);
    assert (b != NULL);
    assert (c != NULL);
    assert (a != b);
    assert (a != c);
    assert (b != c);

    static const int MAX_TRIES = 50;

    fprintf (stream_out, "This is the solver of square equation."
                         " Input 3 coefficients of it by real numbers"
                         " separated by the space to discover the roots.\n");
    int d = 0;
    int ch = 0;
    int tries = 0;
    while (tries < MAX_TRIES)
    {
        if (((d = fscanf (stream_in, "%lf %lf %lf", a, b, c)) == 3) && (is_end_of_input (stream_in)))
        {
           return true;
        }
        if (d == EOF)
        {
            fprintf (stream_out, "There is end of input\n");
            return false;
        }
        ch = clear_input (stream_in);
        if (ch == EOF)
        {
            fprintf (stream_out, "There is end of input\n");
            return false;
        }
        fprintf (stream_out, "Incorrect input. Try again.\n");
        tries++;
    }
    fprintf (stream_out, "Restart the program and try again.\n");
    return false;
}
