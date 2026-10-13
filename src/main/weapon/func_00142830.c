#include "types.h"
typedef struct { int a; int id; int c; int d; } E_830;
typedef struct { int pad; E_830 e[7]; char pad2[0x84 - 0x74]; signed char held; } INV_830;
extern int D_004FFD30;
extern void* WeaponInv_GetHeldItem(INV_830* self);
extern void* WeaponDb_Get(int db, int id);
extern int func_00142960(INV_830* self, void* a, void* b);
extern int func_001429D0(INV_830* self, int slot, int req, int quiet);
extern void func_00143D60(INV_830* self);
int func_00142830(INV_830* self, void* who, int req)
{
    int total = 0;
    void* held = WeaponInv_GetHeldItem(self);
    int i;
    if (held && func_00142960(self, held, who)) {
        total = func_001429D0(self, self->held, req, 0);
        req -= total;
    }
    for (i = 0; req && i < 6; i++) {
        if (i != (unsigned char)self->held && self->e[i].id != -1) {
            if (func_00142960(self, WeaponDb_Get(D_004FFD30, self->e[i].id), who)) {
                int n = func_001429D0(self, (unsigned char)i, req, 0);
                total += n;
                req -= n;
            }
        }
    }
    func_00143D60(self);
    return total;
}
