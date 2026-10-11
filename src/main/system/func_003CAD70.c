#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
#pragma inline_depth(10)

struct VObj_3CAD70 { virtual void dtor(int f); };
typedef struct LNode_3CAD70 { struct LNode_3CAD70* prev; struct LNode_3CAD70* next; VObj_3CAD70* val; } LNode_3CAD70;
struct It_3CAD70 { LNode_3CAD70* n; };
typedef struct { void* buf; } Sub_3CAD70;
typedef struct { void* vt; int f4; int f8; unsigned int fC; int f10; int f14; Sub_3CAD70* p18; int f1C; char list[0x10]; } Self_3CAD70;
extern "C" {
extern char D_004BD1A8[];
extern char D_004BD1E8[];
extern char D_004DFDA0[];
extern char D_004DFDE0[];
void Mem_Free(int pool, void* p, char* file, int line);
It_3CAD70 func_0013B160(void* l);
void func_003CAB20(It_3CAD70* out, const It_3CAD70& in);
It_3CAD70 func_003CAB30(void* l);
void func_003CAB40(It_3CAD70* out, const It_3CAD70& in);
void func_003CB010(void* p, int f);
void operator_delete(void* p);
}
struct ItA_3CAD70 : It_3CAD70 { ItA_3CAD70(const It_3CAD70& t) { func_003CAB40(this, t); } };
struct ItB_3CAD70 : It_3CAD70 { ItB_3CAD70(const It_3CAD70& t) { func_003CAB20(this, t); } };
static inline ItA_3CAD70 E0_3CAD70(void* l) { return ItA_3CAD70(func_0013B160(l)); }
static inline ItB_3CAD70 B0_3CAD70(void* l) { return ItB_3CAD70(func_003CAB30(l)); }
static inline ItB_3CAD70 BX1(void* l) { return B0_3CAD70(l); }
static inline ItB_3CAD70 Begin_3CAD70(void* l) { return BX1(l); }
static inline ItA_3CAD70 End_3CAD70(void* l) { return E0_3CAD70(l); }

static inline void FreeV_3CAD70(VObj_3CAD70* o, int line) { AllocGuard g; o->dtor(-1); Mem_Free(0, o, D_004BD1A8, line); }
static inline void SubDtor_3CAD70(Sub_3CAD70* s) { if (s) { void* b = s->buf; if (b) { AllocGuard g; Mem_Free(0, b, D_004BD1E8, 0x34); } } }
static inline void BaseDtor_3CAD70(Self_3CAD70* self)
{
    if (self) {
        self->vt = D_004DFDE0;
        self->f4 = 0;
        self->fC = 0xF0FFFFF0;
        Sub_3CAD70* p = self->p18;
        if (p) { AllocGuard g; SubDtor_3CAD70(p); Mem_Free(0, p, D_004BD1A8, 0x54); }
    }
}

static inline LNode_3CAD70* EndN_3CAD70(void* l) { return End_3CAD70(l).n; }
extern "C" Self_3CAD70* func_003CAD70(Self_3CAD70* self, short f)
{
    if (self) {
        self->vt = D_004DFDA0;
        {
            VObj_3CAD70* o;
            LNode_3CAD70* e = EndN_3CAD70(self->list);
            It_3CAD70 it = Begin_3CAD70(self->list);
            while (it.n != e) {
                o = it.n->val; FreeV_3CAD70(o, 0x9E);
                it.n = it.n->next;
            }
        }
        if (self->list) func_003CB010(self->list, 0);
        BaseDtor_3CAD70(self);
        if (f > 0) operator_delete(self);
    }
    return self;
}