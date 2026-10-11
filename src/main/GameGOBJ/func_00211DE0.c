#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
struct Shm_00211DE0 { int f0; int f4; int f8; unsigned char bC; char padD; unsigned short hE; unsigned short h10; char pad12[2]; int f14; int f18; int f1C; int f20; };
struct Seg_00211DE0 { char pad[0x1C]; Shm_00211DE0* p1C; };
struct Self_00211DE0 { char pad0[0x10]; int f10; unsigned char b14; char pad15[0xD0 - 0x15]; Shm_00211DE0* pD0; char padD4[0x128 - 0xD4]; Shm_00211DE0* p128; };
extern "C" {
extern unsigned char D_005723C8;
extern char D_004A4550[];
extern char D_004A4A18[];
void Mem_Free(int heap, void* p, char* file, int line);
int func_002EB650(Seg_00211DE0** o, int h);
int func_00211DA0(void);
void func_002EC2A8(int a);
Self_00211DE0* Object_LookupById(int* id);
void func_002189E0(Self_00211DE0* o, int v);
void NetMap_BindReceiver(int a, int b, void* c);
}
#pragma define_section DROPDTOR ".dtors_drop" far_absolute RX
struct Busy_00211DE0 {
    Busy_00211DE0() { if (!D_005723C8) D_005723C8 = 1; }
    __declspec(weak) __declspec(DROPDTOR) ~Busy_00211DE0() { D_005723C8 = 0; }
};
static inline void ReleaseD0_00211DE0(Self_00211DE0* self)
{
    Shm_00211DE0* p = self->pD0;
    if (p) {
        if (p->bC) {
            func_002EC2A8(func_00211DA0());
        } else {
            AllocGuard g;
            Mem_Free(0, p, D_004A4550, 0xB83);
        }
        self->pD0 = 0;
    }
}
extern "C" void func_00211DE0(void* unused, int h)
{
    Busy_00211DE0 busy;
    Seg_00211DE0* seg;
    int id[1];
    Shm_00211DE0* p;
    Self_00211DE0* o;
    if (!func_002EB650(&seg, h)) {
        p = seg->p1C;
        id[0] = p->h10 | (p->hE << 16);
        o = Object_LookupById(id);
        if (o) {
            {
                Shm_00211DE0* old = o->p128;
                if (old && p) {
                    AllocGuard g;
                    Mem_Free(0, old, D_004A4A18, 0x247);
                }
            }
            o->p128 = p;
            if (o->pD0 && p) {
                p->f4 = o->pD0->f4;
                p->f0 = o->pD0->f0;
                ReleaseD0_00211DE0(o);
            }
            o->pD0 = p;
            if (p->f20 != o->pD0->f0)
                func_002189E0(o, p->f20);
            o->p128->f1C = h;
            o->p128->bC = 1;
            o->b14 = 0;
            o->f10 = p->f18;
            NetMap_BindReceiver(p->f18, p->f14, o);
        }
    }
}