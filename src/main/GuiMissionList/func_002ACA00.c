#include "types.h"
typedef struct { int id; int idx; int fl; } It_002ACA00;
typedef struct { char pad0[0x11C]; void* p11C; } S_002ACA00;
typedef struct {
    int f0; char name[0x20]; int f24; char pad28[0x34 - 0x28]; int f34; int f38; char pad3C[0x44 - 0x3C]; int f44;
} E_002ACA00;
extern S_002ACA00* D_005065C0;
extern E_002ACA00* func_0044F290(void* table, int idx);
extern int strcmp(const char* a, const char* b);
int func_002ACA00(const void* a, const void* b)
{
    E_002ACA00* e1 = func_0044F290(D_005065C0->p11C, ((It_002ACA00*)a)->idx);
    E_002ACA00* e2 = func_0044F290(D_005065C0->p11C, ((It_002ACA00*)b)->idx);
    int r1;
    int r2;
    if (!e1 || !e2)
        return 0;
    r2 = r1 = 5;
    if (e1->f44 == 1)
        r1 = 1;
    if (e2->f44 == 1)
        r2 = 1;
    if (e1->f44 == 2)
        r1 = 2;
    if (e2->f44 == 2)
        r2 = 2;
    if (r1 != r2)
        return r1 - r2;
    if (e1->f24 == 0)
        r1 = 3;
    if (e2->f24 == 0)
        r2 = 3;
    if (e1->f24 == 1)
        r1 = 4;
    if (e2->f24 == 1)
        r2 = 4;
    if (r1 != r2)
        return r1 - r2;
    r1 += e1->f38 - 4;
    r2 += e2->f38 - 4;
    if (r1 != r2)
        return r1 - r2;
    r1 += e1->f34 - 4;
    r2 += e2->f34 - 4;
    if (r1 != r2)
        return r1 - r2;
    return strcmp(e1->name, e2->name);
}
