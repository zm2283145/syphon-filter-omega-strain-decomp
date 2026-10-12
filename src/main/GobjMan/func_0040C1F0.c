#include "types.h"

extern char D_00571B80[];
extern int sprintf(char* buf, const char* fmt, ...);

/* Formats the id's high byte (bits 16-23) and low half into a static buffer and returns it. */
char* func_0040C1F0(unsigned int* id)
{
    sprintf(D_00571B80, "(%d %d)", (*id & 0xFF0000) >> 16, *id & 0xFFFF);
    return D_00571B80;
}
