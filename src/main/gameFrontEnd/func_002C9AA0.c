#include "types.h"
extern char D_004FFB50[];
extern char D_004F2CC0[];
extern void* Service_Lookup(char* a, char* b);
extern void func_001C7D80(void* p);
typedef struct { char pad[0x30C]; int handle; } Obj9AA0;
void func_002C9AA0(Obj9AA0* o)
{
    void* s = Service_Lookup(D_004FFB50, D_004F2CC0);
    if (s)
        func_001C7D80(s);
    o->handle = -1;
}