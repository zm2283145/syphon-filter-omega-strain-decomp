/*
 * SFOGame/Source/hudTargets: 1 file, 00273B40
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00273B40 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
#pragma inline_depth(10)

union It { char* p; float f; };
struct L { int sz; char* s0; char* first; };
struct Mgr { L obs; L recs; L l18; L l24; float range; int p34; int p38; char* sel; };

class OObj { public: int x; virtual void Update(int a); };

extern "C" {
int cMemMan_Deallocate(...);
int String_Dtor(...);
int cLListIterator_cHudTargetsObserverPtr_ctor(...);
int std_list_cHudTargetsObserverPtr_end(...);
int std_list_cHudTargetsObserverPtr_generic_iterator_ctor(...);
int std_list_cHudTargetInfoPtr_end_void_2(...);
int cLListIterator_cHudTargetInfoPtr_ctor_listR(...);
int std_list_deleter_voidPtr_begin_void(...);
int std_list_cHudTargetInfoPtr_generic_iterator_ctor(...);
int std_list_cHudTargetInfoPtr_generic_iterator_opCast(...);
int std_list_deleter_voidPtr_generic_iterator_ctor_listdeleterR(...);
int std_list_deleter_voidPtr_erase_listdeleter(...);
int cHudRadar_SetDanger(float, char*, int);
int cIE_GOBJ_AnimateOff(...);
int std_list_deleter_cSafePtr_cGOBJ_erase_listdeleter_listdeleter(...);
int std_list_deleter_voidPtr_erase_listdeleter_listdeleter(...);
int cHudTargetInfo_Update(float, char*, char*, char*, float*);
extern unsigned char D_0048B308;
extern char D_004A8F60;
extern char* g_Hud;
void cHudTargetManager_Update(Mgr* mgr, int arg);
}

static inline void beg0(It* o, char* l) { It r; std_list_deleter_voidPtr_begin_void(&r, l); std_list_cHudTargetInfoPtr_generic_iterator_ctor(o, &r); }
static inline void end0(It* o, char* l) { It r; std_list_cHudTargetInfoPtr_end_void_2(&r, l); cLListIterator_cHudTargetInfoPtr_ctor_listR(o, &r); }
static inline void beg2(It* o, char* l) { It r; std_list_deleter_voidPtr_begin_void(&r, l); std_list_cHudTargetsObserverPtr_generic_iterator_ctor(o, &r); }
static inline void end1(It* o, char* l) { It r; std_list_cHudTargetsObserverPtr_end(&r, l); cLListIterator_cHudTargetsObserverPtr_ctor(o, &r); }
static inline void clr18(char* a) { int r; char* f; char* l; l = a + 0x1C; f = F_(a, 0x20, char*); std_list_deleter_cSafePtr_cGOBJ_erase_listdeleter_listdeleter(&r, a + 0x18, &f, &l); }
static inline void clr24(char* a) { int r; char* f; char* l; l = a + 0x28; f = F_(a, 0x2C, char*); std_list_deleter_voidPtr_erase_listdeleter_listdeleter(&r, a + 0x24, &f, &l); }
static inline void er2(char* l, It* a, It* o) { It c; It b; std_list_cHudTargetInfoPtr_generic_iterator_opCast(&b, a); std_list_deleter_voidPtr_erase_listdeleter(&c, l, &b); std_list_cHudTargetInfoPtr_generic_iterator_ctor(o, &c); }
static inline void er(char* l, It* it, It* out) { It o; It a; std_list_deleter_voidPtr_generic_iterator_ctor_listdeleterR(&a, it); er2(l, &a, &o); out->p = o.p; }
static inline void Beg0(It* o, char* l) { beg0(o, l); }
static inline void End0(It* o, char* l) { end0(o, l); }
static inline void Beg2(It* o, char* l) { beg2(o, l); }
static inline void End1(It* o, char* l) { end1(o, l); }

void cHudTargetManager_Update(Mgr* mgr, int arg)
{
    It it;
    float dist;
    It t;
    It e;
    It e2;
    It e3;
    It b1;
    clr18((char*)mgr);
    clr24((char*)mgr);
    Beg0(&b1, (char*)&mgr->recs);
    dist = 0.0f;
    it.p = b1.p;
    while ((End0(&e, (char*)&mgr->recs), it.p != e.p)) {
        char* rec = F_(it.p, 8, char*);
        if (cHudTargetInfo_Update(mgr->range, rec, (char*)&mgr->l24, (char*)&mgr->l18, &dist) == 0) {
            if (rec == mgr->sel) mgr->sel = 0;
            {
                AllocGuard g;
                if (rec != NULL) {
                    if (D_0048B308 != 0) {
                        cIE_GOBJ_AnimateOff(F_(rec, 8, int));
                        cIE_GOBJ_AnimateOff(F_(rec, 4, int));
                    }
                    char* s;
                    s = rec + 0x28;
                    if (s != NULL) String_Dtor(s, 0);
                    s = rec + 0x1C;
                    if (s != NULL) String_Dtor(s, 0);
                }
                cMemMan_Deallocate(0, rec, &D_004A8F60, 0x193);
            }
            {
                It r;
                er((char*)&mgr->recs, &it, &r);
                t.p = r.p;
                it = t;
            }
        } else {
            it.p = F_(it.p, 4, char*);
        }
    }
    if (mgr->sel != 0) {
        bool found = false;
        It b2;
        Beg0(&b2, (char*)&mgr->l24);
        char* n = b2.p;
        for (; (End0(&e2, (char*)&mgr->l24), n != e2.p); n = F_(n, 4, char*)) {
            if (F_(n, 8, char*) == mgr->sel) { found = true; break; }
        }
        if (!found) mgr->sel = 0;
    }
    cHudRadar_SetDanger(dist, g_Hud + 0xD0, 0);
    {
        It b3;
        Beg2(&b3, (char*)mgr);
        char* n = b3.p;
        for (; (End1(&e3, (char*)mgr), n != e3.p); n = F_(n, 4, char*)) {
            F_(n, 8, OObj*)->Update(arg);
        }
    }
}
static inline void merge_flush_func_00273B40(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00273B40 */
