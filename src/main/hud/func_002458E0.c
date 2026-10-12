#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
typedef struct { int key; int x4; int id; int c; int d; } Ent_2458E0;
typedef struct Node_2458E0 { struct Node_2458E0* prev; struct Node_2458E0* next; Ent_2458E0* ent; } Node_2458E0;
typedef struct { Node_2458E0* n; } It_2458E0;
struct Eq_2458E0 {};
struct Pred_2458E0 { Eq_2458E0 op; void** ref; Pred_2458E0(const Eq_2458E0& e, void** r) : op(e), ref(r) {} };
struct V6A0_2458E0 { int owner; virtual void v0(); virtual void v1(); virtual void v2(); virtual void Destroy(int f); };
struct Own_2458E0 { int owner; };
typedef struct {
    char pad0[0x54]; void* x54; char pad58[0xC]; int x64; int x68; char pad6C[0x10]; char x7C[0x14]; char x90[0x40];
    Own_2458E0 xD0; char padD4[0x2C]; char x100[0x534]; void* x634; char pad638[0x68]; V6A0_2458E0* x6A0; char pad6A4[0x44]; char x6E8[4];
} Self_2458E0;
extern "C" {
extern char D_004A7210[];
extern char D_004DC4A0[];
extern int D_004FFC04;
void Mem_Free(int pool, void* allocation, char* file, int line);
void ActiveList_EraseMatching(void* list, Pred_2458E0 p);
void func_00242E30(It_2458E0* out, char* l);
void func_002426B0(It_2458E0* out, char* l);
void func_002426A0(It_2458E0* out, It_2458E0* in);
void func_003E7EC0(int a, int b);
void func_003E9770(int a);
void func_003E8EB0(int a);
void func_003E79F0(void* p, int f);
void func_002CB160(int a);
void func_00245D80(void* p, int f);
void cGOBJ_dtor(void* p, int f);
void func_003FA4B0(void* p, int f);
void func_00261950(void* p, int f);
void func_00273F00(void* p, int f);
void func_00245C90(void* p, int f);
void func_00246FF0(void* p, int f);
void __dl__FPv(void* p);
}
static inline Pred_2458E0 MakePred_(void** r) { Eq_2458E0 e; return Pred_2458E0(e, r); }
static inline void Unreg_(Self_2458E0* s, int* o) { *o = 0; ActiveList_EraseMatching(s->x90, MakePred_((void**)&o)); }
static inline void BeginI_(It_2458E0* out, char* l) { It_2458E0 t; func_00242E30(&t, l); func_002426A0(out, &t); }
static inline void EndI_(It_2458E0* out, char* l) { It_2458E0 t; func_002426B0(&t, l); func_002426A0(out, &t); }
static inline void Begin_(It_2458E0* out, char* l) { BeginI_(out, l); }
static inline void End_(It_2458E0* out, char* l) { EndI_(out, l); }
static inline void DelEnt_(Ent_2458E0* e) { AllocGuard g; if (e) { if (e->c) func_003E7EC0(e->c, 0); if (e->d) func_003E9770(e->d); } Mem_Free(0, e, D_004A7210, 0x1A9); }
static inline void DelV_(V6A0_2458E0* v) { AllocGuard g; v->Destroy(-1); Mem_Free(0, v, D_004A7210, 0x1B7); }
static inline void Del54_(void* p) { AllocGuard g; func_003E79F0(p, -1); Mem_Free(0, p, D_004A7210, 0x1B9); }
extern "C" Self_2458E0* func_002458E0(Self_2458E0* self, short flag)
{
    if (self) {
        It_2458E0 it;
        It_2458E0 end;
        Ent_2458E0* e;
        Node_2458E0* n;
        Unreg_(self, (int*)self->x6A0);
        Unreg_(self, (int*)&self->xD0);
        Begin_(&it, self->x6E8);
        for (n = it.n; End_(&end, self->x6E8), n != end.n; n = n->next) {
            n->ent->c = 0;
            n->ent->d = 0;
            e = n->ent;
            DelEnt_(e);
        }
        if (!self->x64 && self->x68)
            func_003E8EB0(self->x68);
        if (self->x6A0) {
            DelV_(self->x6A0);
        }
        Del54_(self->x54);
        func_002CB160(D_004FFC04);
        if (self->x6E8)
            func_00245D80(self->x6E8, 0);
        if (&self->x634) {
            self->x634 = D_004DC4A0;
            cGOBJ_dtor(&self->x634, 0);
        }
        func_003FA4B0(self->x100, -1);
        func_00261950(&self->xD0, -1);
        func_00273F00(self->x90, -1);
        if (self->x7C)
            func_00245C90(self->x7C, -1);
        if (self)
            if (self)
                if (self)
                    func_00246FF0(self, 0);
        if (flag > 0)
            __dl__FPv(self);
    }
    return self;
}





