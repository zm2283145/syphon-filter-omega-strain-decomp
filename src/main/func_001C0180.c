#include "types.h"

extern char D_0049EE30[];
extern char D_0048B2F8[];
extern int sprintf(char* buf, const char* fmt, ...);
extern void Archive_Open(void* target, char* text, int a, int b);

/* Formats D_0048B2F8 with the D_0049EE30 format and passes the text to Archive_Open. */
void func_001C0180(void* self, void* target)
{
    char buf[0x80];
    sprintf(buf, D_0049EE30, D_0048B2F8);
    Archive_Open(target, buf, 1, 0);
}
