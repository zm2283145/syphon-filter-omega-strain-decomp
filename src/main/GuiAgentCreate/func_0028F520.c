#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
struct V28F520 { virtual void v0(int f); virtual int v1(); virtual int v2(); virtual int v3(); virtual int v4(); virtual int v5(); virtual int v6(); virtual int v7(); virtual int v8(); virtual int v9(); virtual int v10(); virtual int v11(); virtual int v12(); virtual int v13(); virtual int v14(); virtual int v15(); virtual int v16(); virtual int v17(); virtual int v18(); virtual int v19(); virtual int v20(); virtual int v21(); virtual void v22(int f); };
struct O28F520 { void* vt; char pad[0x5C]; V28F520* items[4]; char pad70[4]; V28F520* p74; };
extern "C" {
extern char D_004DD1B0[];
extern char D_0055DDA0[];
void Mem_Free(int pool, void* p, char* file, int line);
void func_00403310(void* p);
void func_0040F540(void);
void func_0041F370(void* p, int f);
void operator_delete(void* p);
}
static inline void Del28F520(V28F520* o, int line)
{
    AllocGuard g;
    o->v0(-1);
    Mem_Free(0, o, "GuiAgentCreate.cc", line);
}
extern "C" O28F520* func_0028F520(O28F520* self, short del)
{
    if (self) {
        int i;
        self->vt = D_004DD1B0;
        Del28F520(self->p74, 0x169);
        for (i = 0; i < 4; i++) {
            self->items[i]->v22(1);
            Del28F520(self->items[i], 0x16D);
        }
        func_00403310(D_0055DDA0);
        func_0040F540();
        func_0041F370(self, 0);
        if (del > 0)
            operator_delete(self);
    }
    return self;
}