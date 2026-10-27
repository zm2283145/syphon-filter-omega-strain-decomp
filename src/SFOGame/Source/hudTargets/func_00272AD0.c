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
void* cMemMan_Allocate(int pool, int size, char* file, int line);
void cIE_GOBJ_AnimateOff(void* p);
int cInterfaceModel_CreateInstance(int id);
void* cIE_GOBJ_ctor(void* self, int a1, void* a2);
void cInterfaceElement_SetFilterColor(int a, char* b);
}
struct U_2AD0 { char pad[0x60]; int f60; };
struct T_2AD0 { void* vt; U_2AD0* u; void* obj; };
struct S_2AD0 { char pad[0x3C]; T_2AD0* cur; };

#pragma push
#pragma opt_propagation off
extern "C" void cHudTargetManager_SetObjectiveTarget(S_2AD0* s, T_2AD0* t)
{
    void* o;
    if (s->cur != t) {
        if (s->cur) {
            cIE_GOBJ_AnimateOff(s->cur->obj);
            {
                AllocGuard g;
                o = cMemMan_Allocate(0, 0x90, D_004A8F60, 0x273);
            }
            if (o) {
                T_2AD0* c = s->cur;
                cIE_GOBJ_ctor(o, cInterfaceModel_CreateInstance(D_004FFD78), c);
                *(char**)o = D_004E0360;
            }
            s->cur->obj = o;
            cInterfaceElement_SetFilterColor(s->cur->u->f60, D_004FFDA0);
        }
        if (t) {
            cIE_GOBJ_AnimateOff(t->obj);
            {
                AllocGuard g;
                o = cMemMan_Allocate(0, 0x90, D_004A8F60, 0x284);
            }
            if (o) {
                cIE_GOBJ_ctor(o, cInterfaceModel_CreateInstance(D_004FFD80), t);
                *(char**)o = D_004E0360;
            }
            t->obj = o;
            cInterfaceElement_SetFilterColor(t->u->f60, D_004FFD90);
        }
        s->cur = t;
    }
}
#pragma pop
