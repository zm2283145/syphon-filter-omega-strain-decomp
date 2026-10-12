#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
extern "C" {
extern char D_004A8F60[];
extern char D_004E0360[];
extern int D_004FFD78;
extern int D_004FFD80;
extern char D_004FFD90[];
extern char D_004FFDA0[];
void* Mem_Alloc(int pool, int size, char* file, int line);
void func_003E9770(void* p);
int func_003EF010(int id);
void* func_003E99B0(void* self, int a1, void* a2);
void func_003E7EE0(int a, char* b);
}
struct U_2AD0 { char pad[0x60]; int f60; };
struct T_2AD0 { void* vt; U_2AD0* u; void* obj; };
struct S_2AD0 { char pad[0x3C]; T_2AD0* cur; };

#pragma push
#pragma opt_propagation off
extern "C" void func_00272AD0(S_2AD0* s, T_2AD0* t)
{
    void* o;
    if (s->cur != t) {
        if (s->cur) {
            func_003E9770(s->cur->obj);
            {
                AllocGuard g;
                o = Mem_Alloc(0, 0x90, D_004A8F60, 0x273);
            }
            if (o) {
                T_2AD0* c = s->cur;
                func_003E99B0(o, func_003EF010(D_004FFD78), c);
                *(char**)o = D_004E0360;
            }
            s->cur->obj = o;
            func_003E7EE0(s->cur->u->f60, D_004FFDA0);
        }
        if (t) {
            func_003E9770(t->obj);
            {
                AllocGuard g;
                o = Mem_Alloc(0, 0x90, D_004A8F60, 0x284);
            }
            if (o) {
                func_003E99B0(o, func_003EF010(D_004FFD80), t);
                *(char**)o = D_004E0360;
            }
            t->obj = o;
            func_003E7EE0(t->u->f60, D_004FFD90);
        }
        s->cur = t;
    }
}
#pragma pop
