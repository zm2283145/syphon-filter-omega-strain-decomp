#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
extern "C" {
#include "net_local_id.h"
}
struct Shm_00212220 { int f0; int f4; int f8; unsigned char bC; char padD; unsigned short hE; unsigned short h10; char pad12[2]; int f14; int f18; int f1C; };
struct Seg_00212220 { char pad[0x1C]; Shm_00212220* p1C; };
struct Self_00212220 { char pad0[0xC]; unsigned int fC; int f10; char pad14[0xCC - 0x14]; int fCC; Shm_00212220* pD0; char padD4[8]; unsigned char bDC; };
extern "C" {
extern unsigned char D_005721D0;
extern char D_004A4550[];
extern char D_004A4590[];
extern int D_004F5480;
void* Mem_Alloc(int heap, int size, char* file, int line);
void Mem_Free(int heap, void* p, char* file, int line);
int func_002EAF28(int* h, int a, int b, int c, int d, int e, int f, void* buf, char* name, int size);
int func_002EB650(Seg_00212220** o, int h);
int func_00211DA0(void);
void func_002EC2A8(int a);
int func_003FBBA0(void);
void NetMap_BindReceiver(int a, int b, void* c);
}
static inline void* New_00212220(int size, int line)
{
    AllocGuard g;
    return Mem_Alloc(0, size, D_004A4550, line);
}
extern "C" void func_00212220(Self_00212220* self)
{
    int ok;
    if (D_005721C8)
        ok = D_005721C0;
    else
        ok = 1;
    if (!ok || !D_005721D0) {
        if (!self->pD0) {
            Shm_00212220* p = (Shm_00212220*)New_00212220(0x20, 0xB37);
            if (p) {
                p->f0 = 0;
                p->f4 = 0;
                p->bC = 0;
            }
            self->pD0 = p;
        }
    } else {
        int h;
        Seg_00212220* seg;
        Shm_00212220* p;
        if (func_002EAF28(&h, 1, 3, 0, 0, 0, 0, self->pD0, D_004A4590, D_004F5480))
            return;
        p = self->pD0;
        if (p) {
            if (p->bC) {
                func_002EC2A8(func_00211DA0());
            } else {
                AllocGuard g;
                Mem_Free(0, p, D_004A4550, 0xB83);
            }
            self->pD0 = 0;
        }
        if (func_002EB650(&seg, h))
            return;
        self->pD0 = seg->p1C;
        self->pD0->bC = 1;
        self->pD0->hE = (self->fC & 0xFF0000) >> 16;
        self->pD0->h10 = self->fC;
        self->pD0->f1C = h;
        if (self->fCC != self->pD0->f8) {
            self->fCC = self->pD0->f8;
            self->bDC = 0;
        }
        self->pD0->f14 = NetLocalId();
        self->pD0->f18 = func_003FBBA0();
        {
            int r = self->f10;
            NetMap_BindReceiver(r, NetLocalId(), self);
        }
    }
}