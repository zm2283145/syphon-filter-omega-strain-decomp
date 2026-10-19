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
void* Mem_Alloc(int heap, int size, char* file, int line);
void Mem_Free(int heap, void* p, char* file, int line);
int func_002EAF28(int* h, int a, int b, int c, int d, int e, int f, void* buf, char* name, int size);
int func_002EB650(Seg_00211980** o, int h);
int func_00211DA0(void);
void func_002EC2A8(int a);
int func_003FBBA0(void);
void NetMap_BindReceiver(int a, int b, void* c);
}
static inline int IsHost_00211980(void)
{
    return g_IsMultiplayer ? D_005721C0 : 1;
}
static inline void* New_00211980(int size, int line)
{
    AllocGuard g;
    return Mem_Alloc(0, size, "GameGOBJ.cc", line);
}
static inline void ReleaseD0_00211980(Self_00211980* self)
{
    Shm_00211980* p = self->pD0;
    if (p) {
        if (p->bC) {
            func_002EC2A8(func_00211DA0());
        } else {
            AllocGuard g;
            Mem_Free(0, p, "GameGOBJ.cc", 0xB83);
        }
        self->pD0 = 0;
    }
}
extern "C" void Lift_CreateInfoObject(Self_00211980* self)
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
    if (func_002EAF28(&h, 1, 3, 0, 0, 0, 0, self->p128, "ElevatorInfoObject", D_004F5478))
        return;
    {
        Shm_00211980* p = self->p128;
        if (p) {
            if (p->bC) {
                func_002EC2A8(p->f1C);
            } else {
                AllocGuard g;
                Mem_Free(0, p, "GameGOBJ.cc", 0xCAD);
            }
            self->p128 = 0;
        }
    }
    if (func_002EB650(&seg, h))
        return;
    self->p128 = seg->p1C;
    self->p128->bC = 1;
    self->p128->hE = (self->fC & 0xFF0000) >> 16;
    self->p128->h10 = self->fC;
    self->p128->f1C = h;
    self->p128->f14 = NetLocalId();
    self->p128->f18 = func_003FBBA0();
    self->f10 = self->p128->f18;
    NetMap_BindReceiver(self->p128->f18, NetLocalId(), self);
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