#include "string/string.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp;
    fp = fopen("aboba.txt", "r");

    printf("%p", fp);

    char *s = (char*)std::calloc(10000, sizeof(char));
    while (s = KR_fgets(s, 10000, fp)) {
        if (s == nullptr) {
            break;
        }

        printf("%s\n", s);
    }
}