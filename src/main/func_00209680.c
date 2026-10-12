#include "types.h"
typedef struct { int a, b, c; } E9680;
typedef struct { int x0; unsigned int count; } V9680;
extern int func_002099C0(E9680* first, E9680* last);
extern unsigned int func_00209980(V9680* v);
extern void func_00209950(const char* msg);
extern char D_004A3E70[];
extern void* func_00209920(V9680* v);
extern E9680* func_002098E0(void* alloc, int n, int hint);
extern E9680** func_001F4150(V9680* v);
extern int* func_002098B0(V9680* v);
extern E9680* func_00209880(V9680* v);
extern void func_002097C0(void* alloc, E9680* p, E9680* src);
#pragma optimization_level 1
void func_00209680(V9680* v, E9680* first, E9680* last)
{
    int x; int* px = &x; /* unused address-taken local: reproduces the retail 16-byte frame slot */
    int n = func_002099C0(first, last);
    if (v->count > func_00209980(v))
        func_00209950(D_004A3E70);
    if (n != 0) {
        E9680* p;
        *func_001F4150(v) = func_002098E0(func_00209920(v), n, 0);
        *func_002098B0(v) = n;
        for (p = func_00209880(v); first != last; first++) {
            func_002097C0(func_00209920(v), p, first);
            p++;
            v->count++;
        }
    }
}
#pragma optimization_level reset

