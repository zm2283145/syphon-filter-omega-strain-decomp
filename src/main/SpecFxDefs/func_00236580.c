#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
extern "C" {
extern char D_004A6E38[];
extern char D_004A6F58[];
extern char D_004DBD80[];
extern char D_004DF860[];
void Mem_Free(int heap, void* p, char* file, int line);
void cGOBJ_dtor(void* p, int flag);
void func_003A2BA0(void* p, int flag);
void operator_delete(void* p);
}
struct E_00236580 { void* a; };
struct S_00236580 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(int a);
    char pad4[0x28]; unsigned char b2C; unsigned char b2D; unsigned char b2E; char pad2f[0x7C - 0x2F]; E_00236580** arr; int pad80; int n;
};
static inline void Free_00236580(void* p, int line) { AllocGuard g; Mem_Free(0, p, D_004A6E38, line); }
extern "C" S_00236580* func_00236580(S_00236580* self, short flag)
{
    if (self) {
        int i;
        *(char**)self = D_004DBD80;
        for (i = 0; i < self->n; i++) {
            E_00236580* e = self->arr[i];
            AllocGuard g;
            if (e) {
                if (e->a) { void* q = e->a; AllocGuard g2; func_003A2BA0(q, -1); Mem_Free(0, q, D_004A6F58, 0x10A); }
            }
            Mem_Free(0, e, D_004A6E38, 0x1A8);
        }
        Free_00236580(self->arr, 0x1AA);
        if (self) {
            bool ok;
            *(char**)self = D_004DF860;
            ok = self->b2D && self->b2C && !self->b2E;
            if (ok) self->v22(1);
            cGOBJ_dtor(self, 0);
        }
        if (flag > 0)
            operator_delete(self);
    }
    return self;
}