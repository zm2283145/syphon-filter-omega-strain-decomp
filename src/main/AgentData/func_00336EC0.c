#pragma cplusplus on
#include "types.h"
typedef struct { char s[0x20]; } S20_36EC0;
typedef struct { char s[0x80]; } S80_36EC0;
typedef struct { int a, b, c; char s1[0x20]; char s2[0x80]; } E336EC0;

extern int D_0052FE80;
extern E336EC0 D_0052FE90[];

/* Appends a copy of e to the fixed 64-entry table. */
extern "C" void func_00336EC0(void* self, E336EC0* e)
{
    if (e && D_0052FE80 < 0x40) {
        D_0052FE90[D_0052FE80++] = *e;
    }
}
