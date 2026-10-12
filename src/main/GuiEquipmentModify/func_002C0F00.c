#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
struct V002C0F00 { virtual void v0(int f); virtual int v1(); virtual int v2(); virtual int v3(); virtual int v4(); virtual int v5(); virtual int v6(); virtual int v7(); virtual int v8(); virtual int v9(); virtual int v10(); virtual int v11(); virtual int v12(); virtual int v13(); virtual int v14(); virtual int v15(); virtual int v16(); virtual int v17(); virtual int v18(); virtual int v19(); virtual int v20(); virtual int v21(); virtual void v22(int f); char pad4[0x2420 - 4]; short h2420; char pad2422[0x2C74 - 0x2422]; int x2C74; };
struct O002C0F00 { void* vt; char pad[0x48]; V002C0F00* p4C; V002C0F00* p50; };
extern "C" {

extern char D_0055DDA0[];
extern char D_004DDEE0[];
extern char D_004E1220[];
extern int D_00506500;
void Mem_Free(int pool, void* p, char* file, int line);
void func_00403310(void* p);
void func_0040F540(void);
void func_002BDC10(void* p);
void func_0041F370(void* p, int f);
void operator_delete(void* p);
}
static inline void Del002C0F00(V002C0F00* o, int line)
{
    AllocGuard g;
    o->v0(-1);
    Mem_Free(0, o, "GuiEquipmentModify.cc", line);
}
extern "C" O002C0F00* func_002C0F00(O002C0F00* self, short del)
{
    if (self) {
        int i;
        self->vt = D_004DDEE0;
        func_002BDC10(self);
        Del002C0F00(self->p50, 0x169);
        self->p4C->h2420 = 0;
        self->p4C->x2C74 = 0;
        self->p4C->v22(1);
        Del002C0F00(self->p4C, 0x16D);
        func_0041F370(self, 0);
        if (del > 0)
            operator_delete(self);
    }
    return self;
}