#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
extern "C" {
extern char D_004BD038[];
extern char D_004DFC70[];
void Mem_Free(int heap, void* p, char* file, int line);
void cGOBJ_dtor(void* self, int flag);
void func_0036D5D0(void* p, int flag);
void func_00377BD0(void* p, int flag);
void Model_Unload(void* p);
void operator_delete(void* p);
}
struct SkyM {
    char pad0[0x16C]; void* p16C; unsigned char b170; char pad171[3]; char m174[4];
};
struct SkyG {
    void* vt; char pad4[0x64]; int n68; SkyM* a6C[1];
};
static inline void DelSky(SkyM* p)
{
    AllocGuard g;
    if (p) {
        Model_Unload(p->m174);
        if (p->b170) {
            void* q = p->p16C;
            AllocGuard g2;
            Mem_Free(0, q, D_004BD038, 0x2B);
        }
        func_00377BD0(p->m174, -1);
        func_0036D5D0(p, -1);
    }
    Mem_Free(0, p, D_004BD038, 0x97);
}
extern "C" SkyG* cSKYBOX_GOBJ_dtor(SkyG* self, short flag)
{
    int i;
    if (self) {
        self->vt = D_004DFC70;
        for (i = 0; i < self->n68; i++) {
            if (self->a6C[i])
                DelSky(self->a6C[i]);
        }
        cGOBJ_dtor(self, 0);
        if (flag > 0)
            operator_delete(self);
    }
    return self;
}
