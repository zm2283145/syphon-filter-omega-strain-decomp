#include "types.h"
typedef struct { int w[9]; } ECAE0;
typedef struct { int x0; unsigned int count; } VCAE0;
extern int func_0020CC20(ECAE0* first, ECAE0* last);
extern unsigned int func_0020B380(VCAE0* v);
extern void func_00209950(const char* msg);
extern char D_004A3E70[];
extern void* func_0020B2F0(VCAE0* v);
extern ECAE0* func_0020AF10(void* alloc, int n, int hint);
extern ECAE0** func_001F3510(VCAE0* v);
extern int* func_0020AF50(VCAE0* v);
extern ECAE0* func_0020AEE0(VCAE0* v);
extern void func_0020B220(void* alloc, ECAE0* p, ECAE0* src);
#pragma optimization_level 1
void func_0020CAE0(VCAE0* v, ECAE0* first, ECAE0* last)
{
    int x; int* px = &x; /* unused address-taken local: reproduces the retail 16-byte frame slot */
    int n = func_0020CC20(first, last);
    if (v->count > func_0020B380(v))
        func_00209950(D_004A3E70);
    if (n != 0) {
        ECAE0* p;
        *func_001F3510(v) = func_0020AF10(func_0020B2F0(v), n, 0);
        *func_0020AF50(v) = n;
        for (p = func_0020AEE0(v); first != last; first++) {
            func_0020B220(func_0020B2F0(v), p, first);
            p++;
            v->count++;
        }
    }
}
#pragma optimization_level reset


