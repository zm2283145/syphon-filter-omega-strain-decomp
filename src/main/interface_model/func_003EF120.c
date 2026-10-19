#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"

struct VObj_3EF120 { virtual void dtor(int f); };
typedef struct LNode_3EF120 { struct LNode_3EF120* prev; struct LNode_3EF120* next; VObj_3EF120* val; } LNode_3EF120;
struct It_3EF120 { LNode_3EF120* n; };

struct Self_3EF120;
extern "C" {
extern char D_004BE030[];
extern int g_TextureMgr;
void Mem_Free(int pool, void* p, char* file, int line);
It_3EF120 func_003ED850(void* l);
void func_003ED860(It_3EF120* out, It_3EF120* in);
It_3EF120 func_003ED870(void* l);
void Tex_Release(int a, int b, int c);
void ReceiverList_Dtor_3EF5E0(void* p, int f);
void String_Dtor(void* p, int f);
void operator_delete(void* p);
Self_3EF120* func_003EF120(Self_3EF120* self, short f);
}
struct ItE_3EF120 : It_3EF120 { ItE_3EF120(const It_3EF120& t) { func_003ED860((It_3EF120*)this, (It_3EF120*)&t); } };struct Self_3EF120 {
    char pad0[0x18]; int h18; char pad1c[0x6C - 0x1C];
    unsigned short n6C; unsigned short n6E; char pad70[0x80 - 0x70];
    VObj_3EF120** a80; Self_3EF120** a84; void* p88; char l8C[0xD0 - 0x8C];
    void* pD0; void* pD4;
};
static inline ItE_3EF120 B0_3EF120(void* l) { return ItE_3EF120(func_003ED870(l)); }
static inline ItE_3EF120 E0_3EF120(void* l) { return ItE_3EF120(func_003ED850(l)); }
static inline ItE_3EF120 BeginE_3EF120(void* l) { return B0_3EF120(l); }
static inline ItE_3EF120 End_3EF120(void* l) { return E0_3EF120(l); }
static inline bool Ne_3EF120(const It_3EF120& a, const ItE_3EF120& b) { return a.n != b.n; }
static inline void FreeV_3EF120(VObj_3EF120* o, int line) { AllocGuard g; o->dtor(-1); Mem_Free(0, o, D_004BE030, line); }
static inline void FreeS_3EF120(Self_3EF120* o, int line) { AllocGuard g; func_003EF120(o, -1); Mem_Free(0, o, D_004BE030, line); }
static inline void FreeP_3EF120(void* o, int line) { AllocGuard g; Mem_Free(0, o, D_004BE030, line); }

extern "C" Self_3EF120* func_003EF120(Self_3EF120* self, short f)
{
    if (self) {
        It_3EF120 it = BeginE_3EF120(self->l8C);
        while (Ne_3EF120(it, End_3EF120(self->l8C))) {
            FreeV_3EF120(it.n->val, 0x1E7);
            it.n = it.n->next;
        }
        { int i; for (i = 0; i < self->n6E; i++) FreeS_3EF120(self->a84[i], 0x1EB); }
        { int j; for (j = 0; j < self->n6C; j++) FreeV_3EF120(self->a80[j], 0x1EE); }
        if (self->h18 >= 0) Tex_Release(g_TextureMgr, self->h18, 1);
        if (self->pD0) FreeP_3EF120(self->pD0, 0x1F7);
        if (self->pD4) FreeP_3EF120(self->pD4, 0x1FB);
        if (self->p88) FreeP_3EF120(self->p88, 0x1FE);
        if (self->l8C) ReceiverList_Dtor_3EF5E0(self->l8C, 0);
        if ((char*)self + 0xC) String_Dtor((char*)self + 0xC, 0);
        if (self) String_Dtor(self, 0);
        if (f > 0) operator_delete(self);
    }
    return self;
}