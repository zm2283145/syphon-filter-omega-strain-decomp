#include "types.h"
#pragma cplusplus on
#include "alloc_guard.h"
extern "C" {
extern char D_004A6E38[];
extern char D_004A6F38[];
extern char SnowField_vtable[];
extern char D_004DF860[];
void cGOBJ_dtor(void* p, int flag);
void ParticleInst_Kill(void* p, int flag);
void operator_delete(void* p);
void Mem_Free(int pool, void* p, char* file, int line);
}
struct E_345D0 { void* a; };
struct LNode_345D0 { LNode_345D0* prev; LNode_345D0* next; E_345D0* value; };
struct It_345D0 { LNode_345D0* n; };
struct List_345D0 { int x0; int x4; LNode_345D0* x8; };
extern "C" {
void func_00232EE0(It_345D0* out, List_345D0* list);
It_345D0* func_00232EF0(It_345D0* dst, It_345D0* src);
void func_00232F00(It_345D0* out, List_345D0* list);
void ObjectList_EraseRange(It_345D0* out, List_345D0* list, LNode_345D0** first, int** last);
void func_00234860(List_345D0* l, int flag);
}
struct S_345D0 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(int a);
    char pad4[0x28]; unsigned char b2C; unsigned char b2D; unsigned char b2E; char pad2f[0x74 - 0x2F]; List_345D0 list;
};
struct F_345D0 { float f; };
#pragma opt_propagation off
#pragma opt_common_subs off
static inline bool Ok(S_345D0* s) { return s->b2D && s->b2C && !s->b2E; }
static inline void Beg1(It_345D0* out, List_345D0* l) { It_345D0 t; func_00232F00(&t, l); func_00232EF0(out, &t); }
static inline void End1(It_345D0* out, List_345D0* l) { It_345D0 t; func_00232EE0(&t, l); func_00232EF0(out, &t); }
static inline void Beg2(It_345D0* out, List_345D0* l) { Beg1(out, l); }
static inline void End2(It_345D0* out, List_345D0* l) { End1(out, l); }
static inline void Kill2(E_345D0* e) { void* q = e->a; if (q) { AllocGuard g2; ParticleInst_Kill(q, -1); Mem_Free(0, q, D_004A6F38, 0x14F); } }
extern "C" S_345D0* func_002345D0(S_345D0* self, short flag)
{
    if (self) {
        *(char**)self = SnowField_vtable;
        {
            It_345D0 it;
            It_345D0 t2;
            It_345D0 end;
            Beg2(&t2, &self->list);
            { F_345D0* s = (F_345D0*)&t2; F_345D0* d = (F_345D0*)&it; *d = *s; }
            for (; End2(&end, &self->list), it.n != end.n; it.n = it.n->next) {
                E_345D0* e = it.n->value;
                AllocGuard g;
                if (e) {
                    Kill2(e);
                }
                Mem_Free(0, e, D_004A6E38, 0x382);
            }
        }
        {
            It_345D0 r; LNode_345D0* first; int* last;
            last = &self->list.x4;
            first = self->list.x8;
            ObjectList_EraseRange(&r, &self->list, &first, &last);
        }
        {
            List_345D0* l = &self->list;
            if (l) func_00234860(l, 0);
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
