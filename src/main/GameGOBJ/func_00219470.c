#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
extern "C" {
extern char D_004A4550[];
extern char D_004DB280[];
extern unsigned char D_005721C8;
void Mem_Free(int heap, void* p, char* file, int line);
void cGameGOBJ_dtor(void* p, int flag);
void func_001810D0(void* p, int flag);
int func_00211DA0(void);
void func_00219730(void* p, int flag);
void func_0021C090(void* p, int flag);
void func_002EC2A8(int a);
void func_0036E220(void* p, int flag);
void operator_delete(void* p);
}
struct E_00219470 { char pad[0x48]; char m48[0xE4 - 0x48]; char mE4[4]; };
struct D_00219470s { char pad[0xC]; unsigned char c; };
struct S_00219470 { void* vt; char pad4[0x90]; char m94[0x10]; char mA4[0x10]; char mB4[0x1C]; D_00219470s* pD0; char padd4[0x10]; E_00219470* pE4; };
static inline void Free_00219470(void* p, int line) { AllocGuard g; Mem_Free(0, p, D_004A4550, line); }
static inline void M3_0021C090(void* m) { if (m) { if (m) { if (m) func_0021C090(m, 0); } } }
static inline void M3_001810D0(void* m) { if (m) { if (m) { if (m) func_001810D0(m, 0); } } }
extern "C" S_00219470* cPathedGOBJ_dtor(S_00219470* self, short flag)
{
    if (self) {
        void* m;
        E_00219470* e;
        D_00219470s* d;
        self->vt = D_004DB280;
        e = self->pE4;
        if (e) {
            AllocGuard g;
            if (e) {
                func_0036E220(e->mE4, -1);
                func_0036E220(e->m48, -1);
            }
            Mem_Free(0, e, D_004A4550, 0x266);
        }
        if (D_005721C8) {
            d = self->pD0;
            if (d) {
                if (d->c) func_002EC2A8(func_00211DA0());
                else Free_00219470(d, 0xB83);
                self->pD0 = 0;
            }
        } else {
            d = self->pD0;
            if (d) {
                Free_00219470(d, 0x270);
                self->pD0 = 0;
            }
        }
        m = self->mB4; if (m) func_00219730(m, -1);
        M3_0021C090(self->mA4);
        M3_001810D0(self->m94);
        cGameGOBJ_dtor(self, 0);
        if (flag > 0)
            operator_delete(self);
    }
    return self;
}