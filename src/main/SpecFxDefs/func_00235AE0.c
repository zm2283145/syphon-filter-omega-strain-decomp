#include "types.h"
#pragma cplusplus on
#include "alloc_guard.h"
extern "C" {
extern char D_004A6E38[];
extern char D_004A6F48[];
extern char D_004DBC70[];
extern char D_004DF860[];
void cGOBJ_dtor(void* p, int flag);
void ParticleInst_Kill(void* p, int flag);
void operator_delete(void* p);
void Mem_Free(int pool, void* p, char* file, int line);
}
struct E_35AE0 { void* a; };
struct LNode_35AE0 { LNode_35AE0* prev; LNode_35AE0* next; E_35AE0* value; };
struct It_35AE0 { LNode_35AE0* n; };
struct List_35AE0 { int x0; int x4; LNode_35AE0* x8; };
extern "C" {
void func_002359D0(It_35AE0* out, List_35AE0* list);
It_35AE0* func_002359E0(It_35AE0* dst, It_35AE0* src);
void func_002359F0(It_35AE0* out, List_35AE0* list);
void ObjectList_EraseRange(It_35AE0* out, List_35AE0* list, LNode_35AE0** first, int** last);
void func_00235D70(List_35AE0* l, int flag);
}
struct S_35AE0 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(int a);
    char pad4[0x28]; unsigned char b2C; unsigned char b2D; unsigned char b2E; char pad2f[0x74 - 0x2F]; List_35AE0 list;
};
struct F_35AE0 { float f; };
#pragma opt_propagation off
#pragma opt_common_subs off
static inline bool Ok(S_35AE0* s) { return s->b2D && s->b2C && !s->b2E; }
static inline void Beg1(It_35AE0* out, List_35AE0* l) { It_35AE0 t; func_002359F0(&t, l); func_002359E0(out, &t); }
static inline void End1(It_35AE0* out, List_35AE0* l) { It_35AE0 t; func_002359D0(&t, l); func_002359E0(out, &t); }
static inline void Beg2(It_35AE0* out, List_35AE0* l) { Beg1(out, l); }
static inline void End2(It_35AE0* out, List_35AE0* l) { End1(out, l); }
static inline void Kill2(E_35AE0* e) { void* q = e->a; if (q) { AllocGuard g2; ParticleInst_Kill(q, -1); Mem_Free(0, q, D_004A6F48, 298); } }
extern "C" S_35AE0* SmokeField_dtor(S_35AE0* self, short flag)
{
    if (self) {
        *(char**)self = D_004DBC70;
        {
            It_35AE0 it;
            It_35AE0 t2;
            It_35AE0 end;
            Beg2(&t2, &self->list);
            { F_35AE0* s = (F_35AE0*)&t2; F_35AE0* d = (F_35AE0*)&it; *d = *s; }
            for (; End2(&end, &self->list), it.n != end.n; it.n = it.n->next) {
                E_35AE0* e = it.n->value;
                AllocGuard g;
                if (e) {
                    Kill2(e);
                }
                Mem_Free(0, e, D_004A6E38, 702);
            }
        }
        {
            It_35AE0 r; LNode_35AE0* first; int* last;
            last = &self->list.x4;
            first = self->list.x8;
            ObjectList_EraseRange(&r, &self->list, &first, &last);
        }
        {
            List_35AE0* l = &self->list;
            if (l) func_00235D70(l, 0);
        }
        if (self) {
            *(char**)self = D_004DF860;
            if (Ok(self)) self->v22(1);
            cGOBJ_dtor(self, 0);
        }
        if (flag > 0)
            operator_delete(self);
    }
    return self;
}
