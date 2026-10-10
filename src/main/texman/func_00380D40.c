#include "types.h"
extern char D_004BC2D0[];
extern int sprintf(char* buf, const char* fmt, ...);
extern void func_0036DFB0(void* obj, char* name, void* obj2);
extern void func_0037FEA0(void* self, void* obj, __int128* name);
/* Formats a 16-byte name into a buffer, applies it to obj, then forwards to func_0037FEA0. */
void func_00380D40(void* self, __int128 name, void* obj)
{
    char buf[80];
    sprintf(buf, D_004BC2D0, &name);
    func_0036DFB0(obj, buf, obj);
    func_0037FEA0(self, obj, &name);
}
