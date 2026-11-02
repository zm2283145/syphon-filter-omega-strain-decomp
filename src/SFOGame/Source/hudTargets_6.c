/*
 * SFOGame/Source/hudTargets: 3 files, 00273570-00273B40
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00273570 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on

union It8 { char* p; long long ll; };
union It { char* p; float f; };
struct Str { char* p; int a, b; };

class Obs {
public:
    virtual void v0();
    virtual void v1();
    virtual void OnAdd(char* rec);
};

extern "C" {
int cMemMan_Allocate(...);
int String_Dtor(...);
int cLListIterator_cHudTargetsObserverPtr_ctor(...);
int std_list_cHudTargetsObserverPtr_end(...);
int std_list_cHudTargetsObserverPtr_generic_iterator_ctor(...);
int std_list_cHudTargetInfoPtr_end_void_2(...);
int cLListIterator_cHudTargetInfoPtr_ctor_listR(...);
int std_list_cHudTargetInfoPtr_begin_void_2(...);
int std_list_deleter_voidPtr_begin_void(...);
int std_basic_string_char_char_traits_char_assign_basicstringR(...);
int cInterfaceElement_SetFilterColor(...);
int std_basic_string_char_char_traits_char_ctor_charP(...);
int cHudTargetInfo_SetModel(...);
char* cHudTargetInfo_ctor(...);
int std_list_cHudTargetInfoPtr_push_back(...);
extern char D_004A8F60;
extern char D_004A8F70;
extern char D_004FFDA0;
}

struct Hnd { char* obj; int id; };
struct MRec { int id; char* icon0; char* icon1; int pad0C; int kind; Hnd h; };
class OObj { public: int x; virtual void v0(); virtual void OnAdd(MRec* r); };
static inline bool IsMapKind(MRec* r) { return r->kind == 1 || r->kind == 2; }
static inline void beg0(It* o, char* l) { It r; std_list_cHudTargetInfoPtr_begin_void_2(&r, l); cLListIterator_cHudTargetInfoPtr_ctor_listR(o, &r); }
static inline void end0(It* o, char* l) { It r; std_list_cHudTargetInfoPtr_end_void_2(&r, l); cLListIterator_cHudTargetInfoPtr_ctor_listR(o, &r); }
static inline void end1(It* o, char* l) { It r; std_list_cHudTargetsObserverPtr_end(&r, l); cLListIterator_cHudTargetsObserverPtr_ctor(o, &r); }
static inline void beg2(It* o, char* l) { It r; std_list_deleter_voidPtr_begin_void(&r, l); std_list_cHudTargetsObserverPtr_generic_iterator_ctor(o, &r); }
static inline bool ne(It* a, It* b) { return a->p != b->p; }
static inline void adv(It* a) { a->p = F_(a->p, 4, char*); }
static inline MRec* deref(It* a) { return F_(a->p, 8, MRec*); }

extern "C" int cHudTargetManager_AddObjective_cObjectIdR_charP_charP(char* mgr, int* id, char* name, char* text) {
    It it;
    MRec* rec;
    It b;
    It e;
    It e1;
    It e2;
    beg0(&b, mgr + 0xC);
    it = b;
    while ((end0(&e, mgr + 0xC), ne(&it, &e))) {
        MRec* r = deref(&it);
        if (r->id == *id && IsMapKind(r)) break;
        adv(&it);
    }
    end0(&e1, mgr + 0xC);
    if (!ne(&it, &e1)) {
        {
            MRec* p;
            {
                AllocGuard g;
                p = (MRec*)cMemMan_Allocate(0, 0x34, &D_004A8F60, 0x1F5);
            }
            if (p != NULL) p = (MRec*)cHudTargetInfo_ctor(p);
            rec = p;
        }
        It b2;
        rec->id = *id;
        rec->kind = 2;
        {
            Str s;
            std_basic_string_char_char_traits_char_ctor_charP(&s, name);
            std_basic_string_char_char_traits_char_assign_basicstringR((char*)rec + 0x1C, &s);
            String_Dtor(&s, 0);
        }
        cHudTargetInfo_SetModel(rec, 0);
        {
            MRec* r = rec;
            cInterfaceElement_SetFilterColor(F_(r->icon1, 0x60, int), &D_004FFDA0);
            cInterfaceElement_SetFilterColor(F_(r->icon0, 0x60, int), &D_004FFDA0);
        }
        {
            Str s;
            Str* ps = &s;
            std_basic_string_char_char_traits_char_ctor_charP(ps, text ? text : (text = &D_004A8F70));
            std_basic_string_char_char_traits_char_assign_basicstringR((char*)rec + 0x28, &s);
            String_Dtor(&s, 0);
        }
        {
            beg2(&b2, mgr);
            char* n = b2.p;
            for (; (end1(&e2, mgr), n != e2.p); n = F_(n, 4, char*)) {
                OObj* o = F_(n, 8, OObj*);
                o->OnAdd(rec);
            }
        }
        std_list_cHudTargetInfoPtr_push_back(mgr + 0xC, &rec);
        return 1;
    }
    return 0;
}
static inline void merge_flush_func_00273570(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00273570 */

/* merge_units: begin func_00273890 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma mpwc_relax on


extern "C" {
char* nGobjManager_LookupGOBJ_cObjectIdR(...);
int cGOBJ_Enemy(...);
extern char* g_LocalPlayer;
}
static inline void HSet(Hnd* h, char* o, int& def) { int* p; h->obj = o; if (o) p = (int*)(o + 0xC); else { def = -1; p = &def; } h->id = *p; }

extern "C" int cHudTargetManager_Add(char* mgr, int* id, int force) {
    It it;
    MRec* rec;
    It b;
    It e;
    It e1;
    It e2;
    beg0(&b, mgr + 0xC);
    it = b;
    while ((end0(&e, mgr + 0xC), ne(&it, &e))) {
        MRec* r = deref(&it);
        if (r->id == *id && r->kind == 0) break;
        adv(&it);
    }
    end0(&e1, mgr + 0xC);
    if (!ne(&it, &e1)) {
        char* obj = nGobjManager_LookupGOBJ_cObjectIdR(id);
        if (obj != NULL && (force || F_(obj, 0x58, int) != 0)) {
            int en = (unsigned char) cGOBJ_Enemy(F_(g_LocalPlayer, 0x30, int), obj);
            {
                MRec* p;
                {
                    AllocGuard g;
                    p = (MRec*)cMemMan_Allocate(0, 0x34, &D_004A8F60, 0x1D6);
                }
                if (p != NULL) p = (MRec*)cHudTargetInfo_ctor(p);
                rec = p;
            }
            It b2;
            rec->id = *id;
            rec->kind = 0;
            cHudTargetInfo_SetModel(rec, en);
            {
                beg2(&b2, mgr);
                char* n = b2.p;
                for (; (end1(&e2, mgr), n != e2.p); n = F_(n, 4, char*)) {
                    OObj* o = F_(n, 8, OObj*);
                    o->OnAdd(rec);
                }
            }
            std_list_cHudTargetInfoPtr_push_back(mgr + 0xC, &rec);
            return 1;
        }
    }
    return 0;
}
static inline void merge_flush_func_00273890(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00273890 */

/* merge_units: begin func_00273B40 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma mpwc_relax on
#pragma inline_depth(10)

struct L { int sz; char* s0; char* first; };
struct Mgr { L obs; L recs; L l18; L l24; float range; int p34; int p38; char* sel; };

class OObj_00273B40 { public: int x; virtual void Update(int a); };

extern "C" {
int cMemMan_Deallocate(...);
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
extern char* g_Hud;
void cHudTargetManager_Update(Mgr* mgr, int arg);
}

static inline void beg0_00273B40(It* o, char* l) { It r; std_list_deleter_voidPtr_begin_void(&r, l); std_list_cHudTargetInfoPtr_generic_iterator_ctor(o, &r); }
static inline void clr18(char* a) { int r; char* f; char* l; l = a + 0x1C; f = F_(a, 0x20, char*); std_list_deleter_cSafePtr_cGOBJ_erase_listdeleter_listdeleter(&r, a + 0x18, &f, &l); }
static inline void clr24(char* a) { int r; char* f; char* l; l = a + 0x28; f = F_(a, 0x2C, char*); std_list_deleter_voidPtr_erase_listdeleter_listdeleter(&r, a + 0x24, &f, &l); }
static inline void er2(char* l, It* a, It* o) { It c; It b; std_list_cHudTargetInfoPtr_generic_iterator_opCast(&b, a); std_list_deleter_voidPtr_erase_listdeleter(&c, l, &b); std_list_cHudTargetInfoPtr_generic_iterator_ctor(o, &c); }
static inline void er(char* l, It* it, It* out) { It o; It a; std_list_deleter_voidPtr_generic_iterator_ctor_listdeleterR(&a, it); er2(l, &a, &o); out->p = o.p; }
static inline void Beg0(It* o, char* l) { beg0_00273B40(o, l); }
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
            F_(n, 8, OObj_00273B40*)->Update(arg);
        }
    }
}
static inline void merge_flush_func_00273B40(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00273B40 */
