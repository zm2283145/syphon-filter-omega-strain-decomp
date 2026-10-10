#include "types.h"
typedef struct {
    int target; int f4; unsigned char b8; unsigned char b9; char padA[2];
    int fC; int f10; int f14; unsigned char b18; char pad19[3];
    int f1C; int f20; int f24;
} AnimTrans_f3;
typedef struct { char pad[0x6C]; int list; } AnimSel_f3;
extern unsigned char D_00533880;
extern int D_00533888;
extern char D_004BCFE0[];
extern void Alloc_Lock(int);
extern void Alloc_Unlock(int);
extern void* Mem_Alloc(int, int, char*, int);
extern void func_003B0020(int* list, AnimTrans_f3** item);
static inline void* AllocL_f3(int size, char* file, int line)
{
    void* p;
    if (D_00533880) Alloc_Lock(9);
    D_00533888++;
    p = Mem_Alloc(0, size, file, line);
    if (D_00533880) Alloc_Unlock(9);
    D_00533888--;
    return p;
}
AnimTrans_f3* AnimSelector_BeginTransition(AnimSel_f3* sel, int a, int b, int target)
{
    AnimTrans_f3* t[1];
    AnimTrans_f3* p;
    p = AllocL_f3(0x28, D_004BCFE0, 0x47F);
    if (p) {
        p->target = target;
        p->f4 = 0;
        p->b8 = 0;
        p->b9 = 0;
        p->fC = b;
        p->f10 = a;
        p->f14 = 0;
        p->b18 = 0;
        p->f1C = 0;
        p->f20 = 0;
        p->f24 = 0;
    }
    t[0] = p;
    func_003B0020(&sel->list, t);
    return t[0];
}