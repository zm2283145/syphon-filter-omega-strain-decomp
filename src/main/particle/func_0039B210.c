#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
extern "C" {
int Mem_Alloc(int, int, char *, int);
extern char D_004BC5D0;
}
typedef struct { int p; int a; int b; int n; } E39B;
extern "C" E39B D_0053B560[4];
extern "C" void func_0039B210(int n) {
int i;
int p;
E39B *e;
int sz;
int m;
i = 0;
e = D_0053B560;
sz = n << 5;
m = n;
    do {
        {
            AllocGuard g;
            p = Mem_Alloc(0, sz, &D_004BC5D0, 0xD70);
        }
        
        e->p = p;
        e->n = m;
        e++;
    } while (++i < 4);
}