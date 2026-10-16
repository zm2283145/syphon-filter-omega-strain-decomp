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
void HudTracker_Kill(void* p);
int IeElement_Create(int id);
void* HudTracker_Construct(void* self, int a1, void* a2);
void IeElement_SetColour(int a, char* b);
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
            HudTracker_Kill(s->cur->obj);
            {
                AllocGuard g;
                o = Mem_Alloc(0, 0x90, D_004A8F60, 0x273);
            }
            if (o) {
                T_2AD0* c = s->cur;
                HudTracker_Construct(o, IeElement_Create(D_004FFD78), c);
                *(char**)o = D_004E0360;
            }
            s->cur->obj = o;
            IeElement_SetColour(s->cur->u->f60, D_004FFDA0);
        }
        if (t) {
            HudTracker_Kill(t->obj);
            {
                AllocGuard g;
                o = Mem_Alloc(0, 0x90, D_004A8F60, 0x284);
            }
            if (o) {
                HudTracker_Construct(o, IeElement_Create(D_004FFD80), t);
                *(char**)o = D_004E0360;
            }
            t->obj = o;
            IeElement_SetColour(t->u->f60, D_004FFD90);
        }
        s->cur = t;
    }
}
#pragma pop
