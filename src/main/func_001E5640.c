#include "types.h"
extern int Root_GetParent(void* r);
extern void func_001A76A0(void* r);
extern char* Root_Identity(void* r);
char* func_001E5640(void* r)
{
    if (Root_GetParent(r)) {
        func_001A76A0(r);
        return Root_Identity(r) + 0x20;
    }
    return Root_Identity(r) + 0x70;
}