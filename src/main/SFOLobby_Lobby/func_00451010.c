#include "types.h"
extern int func_0044F290(void*);
int func_00451010(char* p) {
    /* .set reorder barrier keeps the empty then-arm */
    if (*(int*)(p + 0x20) == 0) { asm { .set reorder } return 0; }
    return func_0044F290(p + 0x1C);
}