#include "types.h"
typedef struct { char pad[0xC]; int idC; int id10; char pad14[0x7C]; int f90; } Obj_0360;
int NetMap_BindReceiver(int, int, Obj_0360*);
Obj_0360* Hotbox_CreateRuntime(int, int, int, int);
int NetGame_InitLocalSlot(int*, int);
int func_002EBBA0(int, int*);
extern int D_00494178;
extern int D_004FFBD0;
extern int D_005721A8;
extern unsigned char D_005721C0;
extern unsigned char D_005721C8;
#pragma inline_depth(10)
static inline int LocalId_0360(void)
{
    int r;
    int a = D_005721A8; /* read before the flag test: retail loads it ahead of the branch */
    if (D_005721C8) {
        if (D_00494178 == -1) NetGame_InitLocalSlot(&D_00494178, a);
        r = D_00494178;
    } else r = 0;
    return r;
}
static inline int NetId_0360(void)
{
    int id;
    int ok = D_005721C8 ? D_005721C0 : 1;
    if (ok) {
        id = LocalId_0360();
    } else {
        int tmp[1];
        func_002EBBA0(D_005721A8, tmp);
        id = tmp[0];
    }
    return id;
}
void func_00170360(int arg0, int* arg1)
{
    Obj_0360* o = Hotbox_CreateRuntime(D_004FFBD0, arg0, 1, 0);
    o->idC = *arg1;
    o->id10 = *arg1;
    if (D_005721C8) {
        int t = o->id10;
        NetMap_BindReceiver(t, NetId_0360(), o);
    }
    o->f90 = 3;
}