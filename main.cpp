#include "IO/io.h"
#include <stdio.h>
#include <stdlib.h>
#include "resources/const.h"
#include "sort/sort.h"

const char *filein  = "resources/gamlet.txt";
const char *fileout = "resources/gamletout.txt";

int main() {
    char *text[MAX_NUMBER_STRINGS] = {0};

    int num_string = input_strings(filein, &text);

    sort(&text, num_string);

    output_strings(fileout, &text);
}