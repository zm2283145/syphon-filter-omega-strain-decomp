#include "types.h"
typedef struct { char pad[0x18]; int a18; } E34EA00;
typedef struct { int a0; int count; E34EA00* data; unsigned char aC; } L34EA00;
extern char D_004FFB50[];
extern void func_00296F20(L34EA00* l);
extern void func_00299270(L34EA00* l, int flags);
extern void* Agent_GetSelected(void* list, int idx);
extern void func_00333260(void* ag, int a, int b, L34EA00* l);
extern void func_00356850(void* o, int i, int v);
void func_0034EA00(void* o, int idx)
{
    L34EA00 l;
    func_00296F20(&l);
    l.aC = 1;
    func_00333260(Agent_GetSelected(D_004FFB50, -1), 4, 0, &l);
    if (idx >= 0 && idx < l.count) func_00356850(o, idx, ((E34EA00*)((char*)l.data + idx * 28))->a18);
    func_00299270(&l, 0);
}
