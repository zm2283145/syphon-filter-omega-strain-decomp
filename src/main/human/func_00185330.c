#include "types.h"
typedef struct { char pad[0x3524]; void* weapons; } H_185330;
typedef struct { char pad[0x30]; H_185330* player; } G_185330;
extern G_185330* D_004FFC0C;
extern void func_001423E0(void* w);
extern void func_00143DF0(void* w, int id, int a, int b, int c, int d);
extern int func_00143D20(int id);
extern void func_00142C50(void* w, int slot);
int Script_SetPlayerWeapons(int* args)
{
    volatile int b;
    volatile int a;
    int pa;
    int pb;
    void* w;
    b = args[1];
    pb = b;
    a = args[0];
    pa = a;
    w = D_004FFC0C->player->weapons;
    func_001423E0(w);
    if (pa > -1) func_00143DF0(w, pa, 1, 0, 1, 0);
    if (pb > -1) {
        func_00143DF0(w, pb, 1, 0, 1, 0);
        if (pa < 0) pa = pb;
    }
    if (pa >= 0) func_00142C50(w, func_00143D20(pa));
    return 0;
}
