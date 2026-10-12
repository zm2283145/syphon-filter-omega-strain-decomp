#include "types.h"
typedef struct { int id; int idx; int fl; } It_002AC7E0;
typedef struct { char pad0[0x11C]; void* p11C; } S_002AC7E0;
typedef struct {
    int f0; char name[0x20]; int f24; char pad28[0x34 - 0x28]; int f34; int f38;
} E_002AC7E0;
extern S_002AC7E0* D_005065C0;
extern E_002AC7E0* func_0044F290(void* table, int idx);
extern int strcmp(const char* a, const char* b);
int func_002AC7E0(const void* a, const void* b)
{
    E_002AC7E0* e1 = func_0044F290(D_005065C0->p11C, ((It_002AC7E0*)a)->idx);
    E_002AC7E0* e2 = func_0044F290(D_005065C0->p11C, ((It_002AC7E0*)b)->idx);
    int r1;
    int r2;
    if (!e1 || !e2)
        return 0;
    r2 = r1 = 3;
    if (e1->f24 == 0)
        r1 = 1;
    if (e2->f24 == 0)
        r2 = 1;
    if (e1->f24 == 1)
        r1 = 2;
    if (e2->f24 == 1)
        r2 = 2;
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

