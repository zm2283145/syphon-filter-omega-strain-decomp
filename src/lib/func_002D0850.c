#include "types.h"
extern char D_004AD448[];
extern char* strncpy(char*, const char*, int);
int func_002D0850(char* dst) {
    strncpy(dst, D_004AD448, 0x40);
    return 0;
}