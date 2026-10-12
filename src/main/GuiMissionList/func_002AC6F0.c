#include "types.h"
typedef struct { int id; int idx; int fl; } It_002AC6F0;
typedef struct {
    char pad0[0xAC]; unsigned char bAC; char padAD[0xBC - 0xAD]; unsigned char bBC; char padBD[0x110 - 0xBD];
    int count; It_002AC6F0* data; int f118; void* p11C;
} S_002AC6F0;
typedef int (*Cmp_002AC6F0)(const void*, const void*);
extern S_002AC6F0* D_005065C0;
extern int func_002ACA00(const void* a, const void* b);
extern int func_002AC980(const void* a, const void* b);
extern int func_002AC900(const void* a, const void* b);
extern int func_002AC7E0(const void* a, const void* b);
extern void qsort(void* base, int n, int size, Cmp_002AC6F0 cmp);
#pragma opt_dead_assignments off
void func_002AC6F0(S_002AC6F0* self)
{
    Cmp_002AC6F0 cmp;
    if (!self->count || !self->p11C)
        return;
    cmp = 0;
    switch (self->bAC) {
    case 0:
        cmp = self->bBC ? 0 : func_002ACA00;
        break;
    case 1:
        cmp = func_002AC980;
        break;
    case 2:
        cmp = func_002AC900;
        break;
    case 3:
        cmp = func_002AC7E0;
        break;
    case 4:
        break;
    }
    if (cmp) {
        D_005065C0 = self;
        { int n = self->count; qsort(self->data, n, 12, cmp); }
    }
}


#pragma opt_dead_assignments reset

