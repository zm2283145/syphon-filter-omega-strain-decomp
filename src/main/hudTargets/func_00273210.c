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
int Mem_Alloc(...);
int String_Dtor(...);
int func_002731A0(...);
int func_002731B0(...);
int func_002731C0(...);
int func_002731D0(...);
int func_002731E0(...);
int func_002731F0(...);
int List_Begin(...);
int String_AssignString(...);
int IeElement_SetColour(...);
int String_CtorCStr_13B480(...);
int ObjMarker_ConstructIcon(...);
char* ObjMarkerRecord_Init(...);
int ObjMarkerList_Append(...);
extern char D_004A8F60;
extern char D_004A8F70;
extern char D_004FFDA0;
}

struct Hnd { char* obj; int id; };
struct MRec { int id; char* icon0; char* icon1; int pad0C; int kind; Hnd h; };
class OObj { public: int x; virtual void v0(); virtual void OnAdd(MRec* r); };
static inline void HSet(Hnd* h, char* o, int& def) { int* p; h->obj = o; if (o) p = (int*)(o + 0xC); else { def = -1; p = &def; } h->id = *p; }
static inline bool IsMapKind(MRec* r) { return r->kind == 1 || r->kind == 2; }
static inline void beg0(It* o, char* l) { It r; func_002731F0(&r, l); func_002731E0(o, &r); }
static inline void end0(It* o, char* l) { It r; func_002731D0(&r, l); func_002731E0(o, &r); }
static inline void end1(It* o, char* l) { It r; func_002731B0(&r, l); func_002731A0(o, &r); }
static inline void beg2(It* o, char* l) { It r; List_Begin(&r, l); func_002731C0(o, &r); }
static inline bool ne(It* a, It* b) { return a->p != b->p; }
static inline void adv(It* a) { a->p = F_(a->p, 4, char*); }
static inline MRec* deref(It* a) { return F_(a->p, 8, MRec*); }

extern "C" int HudMarkers_SetMapObject(char* mgr, int* id, char* obj, char* text) {
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
                p = (MRec*)Mem_Alloc(0, 0x34, &D_004A8F60, 0x216);
            }
            if (p != NULL) p = (MRec*)ObjMarkerRecord_Init(p);
            rec = p;
        }
        It b2;
        rec->id = *id;
        {
            int def;
            HSet(&rec->h, obj, def);
        }
        rec->kind = 1;
        ObjMarker_ConstructIcon(rec, 0);
        {
            MRec* r = rec;
            IeElement_SetColour(F_(r->icon1, 0x60, int), &D_004FFDA0);
            IeElement_SetColour(F_(r->icon0, 0x60, int), &D_004FFDA0);
        }
        {
            Str s;
            Str* ps = &s;
            String_CtorCStr_13B480(ps, text ? text : (text = &D_004A8F70));
            String_AssignString((char*)rec + 0x28, &s);
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
        ObjMarkerList_Append(mgr + 0xC, &rec);
        return 1;
    }
    return 0;
}







