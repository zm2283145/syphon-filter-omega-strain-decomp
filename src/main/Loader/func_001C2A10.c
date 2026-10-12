#include "types.h"
typedef struct { int unk0; int size; unsigned int base; char* cur; } PopReader_1C2A10;
extern int Pop_FindTag(PopReader_1C2A10* r, int tag);
extern void func_00165E60(void* a, char* name, int x);
extern void* func_001698C0(void);
extern void func_00257480(PopReader_1C2A10* r);
void Loader_LoadInventoryDefs(void* a0, PopReader_1C2A10* r)
{
    if ((unsigned char)Pop_FindTag(r, 0x3A564E49)) {
        int n;
        int i;
        int mis;
        n = *(int*)r->cur;
        r->cur += 4;
        func_00165E60(func_001698C0(), "Loading Inventory defs...", 0);
        for (i = 0; i < n; i++)
            func_00257480(r);
        mis = (int)((unsigned long long)(unsigned int)r->cur & 3);
        if (mis)
            r->cur += 4 - mis;
    }
}