#ifndef IO
#define IO

#include "../resources/const.h"

int input_strings(const char *file, char *(*text)[MAX_NUMBER_STRINGS]);

void output_strings(const char *file, char *(*text)[MAX_NUMBER_STRINGS]);

#endif