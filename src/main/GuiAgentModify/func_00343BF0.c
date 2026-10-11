#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
struct V00343BF0 { virtual void v0(int f); virtual int v1(); virtual int v2(); virtual int v3(); virtual int v4(); virtual int v5(); virtual int v6(); virtual int v7(); virtual int v8(); virtual int v9(); virtual int v10(); virtual int v11(); virtual int v12(); virtual int v13(); virtual int v14(); virtual int v15(); virtual int v16(); virtual int v17(); virtual int v18(); virtual int v19(); virtual int v20(); virtual int v21(); virtual void v22(int f); char pad4[0x2420 - 4]; short h2420; char pad2422[0x2C74 - 0x2422]; int x2C74; };
struct O00343BF0 { void* vt; char pad[0x88]; V00343BF0* p8C; V00343BF0* p90; };
extern "C" {

extern char D_004BA0A0[];
extern char D_0055DDA0[];
extern char D_004DE920[];
extern char D_004E1220[];
extern int D_00506500;
void Mem_Free(int pool, void* p, char* file, int line);
void func_00403310(void* p);
void func_0040F540(void);
void func_002BDC10(void* p);
void func_0041F370(void* p, int f);
void operator_delete(void* p);
}
static inline void Del00343BF0(V00343BF0* o, int line)
{
    AllocGuard g;
    o->v0(-1);
    Mem_Free(0, o, D_004BA0A0, line);
}
extern "C" O00343BF0* func_00343BF0(O00343BF0* self, short del)
{
    if (self) {
        int i;
        self->vt = D_004DE920;
        Del00343BF0(self->p90, 0x176);
        self->p8C->v22(1);
        Del00343BF0(self->p8C, 0x178);
        func_00403310(D_0055DDA0);
        func_0040F540();
        if (self) {
            self->vt = D_004E1220;
            func_0041F370(self, 0);
        }
        if (del > 0)
            operator_delete(self);
    }
    return self;
}