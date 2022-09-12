#include "../string/string.h"
#include <stdio.h>
#include <stdlib.h>
#include "../resources/const.h"

int input_strings(const char *file, char *(*text)[MAX_NUMBER_STRINGS]) {
    FILE *fp;
    fp = fopen(file, "r");

    int num_strings = 0;
    for (;          num_strings < MAX_NUMBER_STRINGS; num_strings++){
        (*text)[    num_strings] = (char*)std::calloc(MAX_LEN_STRING, sizeof(char));

        (*text)[    num_strings] = KR_fgets((*text)[num_strings], MAX_LEN_STRING, fp);

        if ((*text)[num_strings] == nullptr) {
            break;
        }
    }

    return num_strings;
}

void output_strings(const char *file, char *(*text)[MAX_NUMBER_STRINGS]) {
    char **p = *text;

    FILE *fp;
    fp = fopen(file, "w");

    for (int i = 0; i < MAX_NUMBER_STRINGS; i++) {
        if (*p == nullptr) {
            break;
        }

        fprintf(fp, "%s\n", *p);

        p++;
    }
}