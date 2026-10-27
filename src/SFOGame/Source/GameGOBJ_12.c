/*
 * SFOGame/Source/GameGOBJ: 2 files, 00211980-00211DA0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00211980 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
extern "C" {
#include "net_local_id.h"
}
struct Shm_00211980 { int f0; int f4; int f8; unsigned char bC; char padD; unsigned short hE; unsigned short h10; char pad12[2]; int f14; int f18; int f1C; int f20; int f24; int f28; int f2C; };
struct Seg_00211980 { char pad[0x1C]; Shm_00211980* p1C; };
struct Self_00211980 { char pad0[0xC]; unsigned int fC; int f10; char pad14[0xD0 - 0x14]; Shm_00211980* pD0; char padD4[0x128 - 0xD4]; Shm_00211980* p128; };
extern "C" {
extern unsigned char D_005721D0;
extern int D_004F5478;
void* cMemMan_Allocate(int heap, int size, char* file, int line);
void cMemMan_Deallocate(int heap, void* p, char* file, int line);
int NetCreateObject(int* h, int a, int b, int c, int d, int e, int f, void* buf, char* name, int size);
int NetGetObject(Seg_00211980** o, int h);
int func_00211DA0(void);
void NetFreeObject(int a);
int cNetObj_GetNetID(void);
void cNetObj_AddSystem(int a, int b, void* c);
}
static inline int IsHost_00211980(void)
{
    return g_IsMultiplayer ? D_005721C0 : 1;
}
static inline void* New_00211980(int size, int line)
{
    AllocGuard g;
    return cMemMan_Allocate(0, size, "GameGOBJ.cc", line);
}
static inline void ReleaseD0_00211980(Self_00211980* self)
{
    Shm_00211980* p = self->pD0;
    if (p) {
        if (p->bC) {
            NetFreeObject(func_00211DA0());
        } else {
            AllocGuard g;
            cMemMan_Deallocate(0, p, "GameGOBJ.cc", 0xB83);
        }
        self->pD0 = 0;
    }
}
extern "C" void cElevatorGOBJ_CreateElevatorInfo(Self_00211980* self)
{
    int h;
    Seg_00211980* seg;
    if (!IsHost_00211980() && self->p128)
        return;
    if (!self->p128 && (!IsHost_00211980() || !D_005721D0)) {
        Shm_00211980* p = (Shm_00211980*)New_00211980(0x30, 0xC64);
        if (p) {
            p->f0 = 0;
            p->f4 = 0;
            p->bC = 0;
            p->f20 = 0;
            p->f24 = 0;
            p->f28 = 0;
            p->f2C = 0;
        }
        self->p128 = p;
        return;
    }
    if (NetCreateObject(&h, 1, 3, 0, 0, 0, 0, self->p128, "ElevatorInfoObject", D_004F5478))
        return;
    {
        Shm_00211980* p = self->p128;
        if (p) {
            if (p->bC) {
                NetFreeObject(p->f1C);
            } else {
                AllocGuard g;
                cMemMan_Deallocate(0, p, "GameGOBJ.cc", 0xCAD);
            }
            self->p128 = 0;
        }
    }
    if (NetGetObject(&seg, h))
        return;
    self->p128 = seg->p1C;
    self->p128->bC = 1;
    self->p128->hE = (self->fC & 0xFF0000) >> 16;
    self->p128->h10 = self->fC;
    self->p128->f1C = h;
    self->p128->f14 = NetLocalId();
    self->p128->f18 = cNetObj_GetNetID();
    self->f10 = self->p128->f18;
    cNetObj_AddSystem(self->p128->f18, NetLocalId(), self);
    {
        Shm_00211980* p = self->p128;
        if (self->pD0 && p) {
            p->f4 = self->pD0->f4;
            p->f0 = self->pD0->f0;
            ReleaseD0_00211980(self);
        }
        self->pD0 = p;
    }
}
static inline void merge_flush_func_00211980(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00211980 */

/* merge_units: begin func_00211DA0 */
#pragma push /* merge_units */
/*
 * Matched functions from GameGOBJ.cc (byte-identical with the retail executable).
 */

#include "gobj_types.h"

extern int D_004F5480;

int func_00211DA0(void) {
    return D_004F5480;
}
static inline void merge_flush_func_00211DA0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00211DA0 */
