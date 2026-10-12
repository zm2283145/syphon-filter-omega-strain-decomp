#pragma cplusplus on

#include "types.h"
#include "alloc_guard.h"
typedef struct { char pad[0x28]; void* model; } Pt2_ItemDef;
extern "C" {
extern int D_00587FF4;
extern Pt2_ItemDef* D_00587FF8;
extern char D_00587FF0[];
void func_0038CC70(void*);
void Mem_Free(int, void*, char*, int);
void func_004719A0(void*);
}


static inline void Pt2_Free(void* p) {
    AllocGuard g;
    Mem_Free(0, p, "inventory.cc", 0xD8);
}
#pragma opt_strength_reduction off
extern "C" void func_004702A0(void) {
    int i;
    for (i = 0; i < D_00587FF4; i++) {
        func_0038CC70(D_00587FF8[i].model);
        Pt2_Free(D_00587FF8[i].model);
    }
    func_004719A0(D_00587FF0);
}