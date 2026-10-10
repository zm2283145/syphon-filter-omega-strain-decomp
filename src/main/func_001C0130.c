#include "types.h"

extern char D_0049EE30[]; /* format string */
extern char D_0048B2F8[];
extern int sprintf(char* buf, const char* fmt, ...); /* sprintf */
extern void func_003F9530(void* target, const char* text);

/* Formats D_0048B2F8 into a local buffer and passes it to func_003F9530. */
void func_001C0130(void* self, void* target)
{
    char buf[0x80];
    sprintf(buf, D_0049EE30, D_0048B2F8);
    func_003F9530(target, buf);
}
