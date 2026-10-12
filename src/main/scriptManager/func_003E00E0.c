#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
typedef struct { void* buf; } S3E00;
typedef struct { char pad[0x18]; char vec[4]; int n; S3E00** items; } M3E00;
extern "C" {
extern void Mem_Free(int, void*, char*, int);
extern void PtrVector_Resize(char*, int, int*);
extern char D_004BD4C0[];
}
#pragma opt_strength_reduction off
extern "C" void ScriptStr_Release(M3E00* m, S3E00* s) {
    int z[1];
    void* buf = s->buf;
    int i, n;
    if (buf) {
        AllocGuard g;
        Mem_Free(0, buf, "scriptManager.hh", 0x90);
    }
    n = m->n - 1;
    for (i = 0; n >= i; i++) {
        if (m->items[i] == s) {
            m->items[i] = m->items[n];
            n--;
        }
    }
    z[0] = 0;
    PtrVector_Resize(m->vec, n + 1, z);
    {
        AllocGuard g;
        Mem_Free(0, s, D_004BD4C0, 0x683);
    }
}
