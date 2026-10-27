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
static inline void HSet(Hnd* h, char* o, int& def) { int* p; h->obj = o; if (o) p = (int*)(o + 0xC); else { def = -1; p = &def; } h->id = *p; }
static inline bool IsMapKind(MRec* r) { return r->kind == 1 || r->kind == 2; }
static inline void beg0(It* o, char* l) { It r; std_list_cHudTargetInfoPtr_begin_void_2(&r, l); cLListIterator_cHudTargetInfoPtr_ctor_listR(o, &r); }
static inline void end0(It* o, char* l) { It r; std_list_cHudTargetInfoPtr_end_void_2(&r, l); cLListIterator_cHudTargetInfoPtr_ctor_listR(o, &r); }
static inline void end1(It* o, char* l) { It r; std_list_cHudTargetsObserverPtr_end(&r, l); cLListIterator_cHudTargetsObserverPtr_ctor(o, &r); }
static inline void beg2(It* o, char* l) { It r; std_list_deleter_voidPtr_begin_void(&r, l); std_list_cHudTargetsObserverPtr_generic_iterator_ctor(o, &r); }
static inline bool ne(It* a, It* b) { return a->p != b->p; }
static inline void adv(It* a) { a->p = F_(a->p, 4, char*); }
static inline MRec* deref(It* a) { return F_(a->p, 8, MRec*); }

extern "C" int cHudTargetManager_AddObjective_cObjectIdR_cObjectiveP_charP(char* mgr, int* id, char* obj, char* text) {
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
                p = (MRec*)cMemMan_Allocate(0, 0x34, &D_004A8F60, 0x216);
            }
            if (p != NULL) p = (MRec*)cHudTargetInfo_ctor(p);
            rec = p;
        }
        It b2;
        rec->id = *id;
        {
            int def;
            HSet(&rec->h, obj, def);
        }
        rec->kind = 1;
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







