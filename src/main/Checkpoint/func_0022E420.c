#include "types.h"
extern int func_002E9A10(void* reg);
extern int func_003C9C30(void* desc);
extern int NetMsg_RegisterType(void* type, int version, void* factory);
extern char D_004F7950[];
extern void func_0022E4F0(void);
unsigned char func_0022E420(void* reg)
{
    long long file;
    unsigned char ok = 0;
    if (func_002E9A10(reg) == 0 && func_003C9C30(&file) != 0 &&
        NetMsg_RegisterType(D_004F7950, 2, func_0022E4F0) == 0)
        ok = 1;
    return ok;
}