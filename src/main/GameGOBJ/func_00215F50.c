#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
extern "C" {
extern char D_004DB040[];
extern char D_004A4550[];
extern unsigned char D_005721C8;
void Mem_Free(int heap, void* p, char* file, int line);
void func_002EC2A8(int a);
void** func_002151B0(void* v, int i);
void func_0036E220(void* p, int flag);
void func_001736C0(void* p, int flag);
void func_0013A040(void* p, int flag);
void func_00145F10(void* p, int flag);
void func_00215E40(void* p, int flag);
void* cPathedGOBJ_dtor(void* p, int flag);
void operator_delete(void* p);
}
struct ElevSnd { char pad[0x48]; char a[0xE4 - 0x48]; char b[0x190 - 0xE4]; };
struct ElevHandle { char pad[0xC]; unsigned char c; char padD[0x1C - 0xD]; int h; };
struct cElevatorGOBJ {
    void* vt;
    char pad4[0xD0 - 4];
    void* pD0;
    char padD4[0xE8 - 0xD4];
    char mE8[0x10];
    char mF8[4];
    int nFC;
    void** p100;
    char pad104[4];
    char m108[0x10];
    char m118[0x10];
    ElevHandle* p128;
    char pad12C[0x150 - 0x12C];
    ElevSnd snd[4];
};
#pragma opt_strength_reduction off
static inline void Free_215F50(void* p, int line) { AllocGuard g; Mem_Free(0, p, D_004A4550, line); }
static inline void SndDtor(ElevSnd* s) { if (s) { func_0036E220(s->b, -1); func_0036E220(s->a, -1); } }
extern "C" cElevatorGOBJ* cElevatorGOBJ_dtor(cElevatorGOBJ* self, short flag)
{
    if (self) {
        int i;
        self->vt = D_004DB040;
        if (D_005721C8) {
            ElevHandle* d = self->p128;
            if (d) {
                if (d->c) func_002EC2A8(d->h);
                else Free_215F50(d, 0xCAD);
                self->p128 = 0;
            }
        } else {
            if (self->p128) {
                void* t = *(void* volatile*)&self->pD0;
                self->pD0 = 0;
                self->p128 = 0;
            }
        }
        for (i = 0; i < self->nFC; i++) {
            void* p = *func_002151B0(self->mF8, i);
            Free_215F50(p, 0x5D8);
            self->p100[i] = 0;
        }
        SndDtor(&self->snd[3]);
        SndDtor(&self->snd[2]);
        SndDtor(&self->snd[1]);
        SndDtor(&self->snd[0]);
        if (self->m118) func_001736C0(self->m118, -1);
        if (self->m108) func_0013A040(self->m108, -1);
        if (self->mF8) func_00145F10(self->mF8, -1);
        if (self->mE8) func_00215E40(self->mE8, -1);
        cPathedGOBJ_dtor(self, 0);
        if (flag > 0)
            operator_delete(self);
    }
    return self;
}

