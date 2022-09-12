#include "sort.h"
#include "../resources/const.h"
#include "../string/string.h"

void sort(char *(*text)[MAX_NUMBER_STRINGS], int num_string) {
    for (int i = 0; i < num_string; i++) {
        for (int j = num_string - 1; j > 0; j--) {
            if (KR_strcmp_letonly((*text)[j], (*text)[j - 1])) {
                KR_strswap(&((*text)[j]), &((*text)[j - 1]));
            }
        }
    }  
}