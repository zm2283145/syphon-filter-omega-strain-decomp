#include "types.h"
extern unsigned char* D_005061D0;
extern void* D_004FFD30;
extern void* WeaponDb_Get(void* db, int id);
static inline short R16_00284870(void) { unsigned char lo = *D_005061D0++; unsigned char hi = *D_005061D0++; return lo + (hi << 8); }
static inline int R32_00284870(void) { unsigned short lo = R16_00284870(); return lo + ((unsigned short)R16_00284870() << 16); }
static inline float RF_00284870(void) { int i = R32_00284870(); return *(float*)&i; }
typedef struct { char pad[0x18]; float a[6]; char pad30[0x20]; float b; char pad54[0x14]; void* w; int id; } S_00284870;
static inline void SetW_00284870(S_00284870* p, int id) { void* db = D_004FFD30; p->id = id; p->w = WeaponDb_Get(db, id); }
void func_00284870(S_00284870* p) {
    p->a[0] = RF_00284870();
    p->a[1] = RF_00284870();
    p->a[2] = RF_00284870();
    p->a[3] = RF_00284870();
    p->a[4] = RF_00284870();
    p->a[5] = RF_00284870();
    p->b = RF_00284870();
    p->id = R32_00284870();
    SetW_00284870(p, p->id);
}