/*
 * main/backpack: range (3 files, 002566B0-002569C0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#include "vslot_pad.h"
#pragma push
#pragma cplusplus on
#include "alloc_guard.h"
#pragma pop

/* library prototypes shared by the blocks below (C linkage) */
int cMemMan_Deallocate();

/* merge_units: begin func_002566B0 */
#pragma push /* merge_units */
#pragma cplusplus on
typedef struct { char pad[0xC]; int serial; char pad10[0x2C - 0x10]; unsigned char b2C; unsigned char b2D; unsigned char b2E; char pad2F[0x3468 - 0x2F]; unsigned char b3468; unsigned char b3469; char pad346A[0x3528 - 0x346A]; int inv; } T_66B0;
typedef struct { char pad[0x94]; int id; } RT_66B0;
class S_66B0 {
public:
    VPAD16(a) VPAD4(b) VPAD1(c)
    virtual void Enable(int on);
    char padv[0xC - 4];
    int id;
    char pad10[0x2FC - 0x10];
    RT_66B0* rt;
    T_66B0* tgt;
    int serial;
};
extern "C" {
RT_66B0* cHotboxMan_CreateInteractBox(int, S_66B0*, int, int);
int ItemInv_Any(int);
void nGobjManager_AddGOBJ(S_66B0*);
}
extern int g_HotboxTracker;
static inline T_66B0* Get_66B0(S_66B0* s) { T_66B0* t = s->tgt; bool ok = !t || t->serial == s->serial; return ok ? t : 0; }
static inline unsigned char CanA(S_66B0* s)
{
    unsigned char r = 0;
    if (Get_66B0(s)) {
        T_66B0* g = Get_66B0(s);
        int ok = g->b2D != 0;
        ok = ok ? g->b2C != 0 : ok;
        ok = ok ? (g->b2E != 0) ^ 1 : ok;
        ok = ok ? g->b3468 != 0 : ok;
        if (ok) r = 1;
    }
    return r;
}
static inline unsigned char CanB(S_66B0* s)
{
    unsigned char r = 0;
    if (Get_66B0(s)) {
        T_66B0* g = Get_66B0(s);
        int ok = g->b2D != 0;
        ok = ok ? g->b2C != 0 : ok;
        ok = ok ? (g->b2E != 0) ^ 1 : ok;
        ok = ok ? g->b3469 != 0 : ok;
        if (ok) r = 1;
    }
    return r;
}

extern "C" void cBackpack_SetBody(S_66B0* s, T_66B0* t)
{
    s->tgt = t;
    {
        int tmp;
        int* p;
        if (t) p = &t->serial; else { tmp = -1; p = &tmp; }
        s->serial = *p;
    }
    if (CanA(s) || CanB(s) || (t && ItemInv_Any(t->inv))) {
        if (!s->rt) {
            s->Enable(1);
            nGobjManager_AddGOBJ(s);
            if (!s->rt) {
                s->rt = cHotboxMan_CreateInteractBox(g_HotboxTracker, s, 0, 1);
                s->rt->id = s->id;
            }
        }
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002566B0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002566B0 */

/* merge_units: begin func_002568F0 */
#pragma push /* merge_units */
typedef struct { char pad[0x314]; float t; } A2O256;
typedef struct { int pad0; int count; A2O256** items; } A2L256;
extern float D_004F7F70;
extern A2L256* g_BackpackList;
extern float D_0048AF18;
extern void cBackpack_Remove(A2O256* o);
void cBackpack_Update(float dt) {
    A2L256* l;
    int i;
    float* t;
    D_004F7F70 += dt;
    l = g_BackpackList;
    for (i = 0; i < l->count; i++) {
        t = &l->items[i]->t;
        if (!(*t < 0.0f)) {
            *t += dt;
            if (!(l->items[i]->t <= D_0048AF18)) {
                cBackpack_Remove(l->items[i--]);
            }
        }
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002568F0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002568F0 */

/* merge_units: begin func_002569C0 */
#pragma push /* merge_units */
#pragma cplusplus on
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
struct Raw_69C0 { int p; };
extern "C" {
void std_list_deleter_voidPtr_erase_listdeleter_listdeleter(int*, void*, char**, char**);
Raw_69C0 std_list_deleter_voidPtr_begin_void(void*);
Raw_69C0 std_list_CrateSavePtr_end(void*);
void std_list_CrateSavePtr_generic_iterator_ctor(char**, const Raw_69C0&);
void cLListIterator_CrateSavePtr_ctor(char**, const Raw_69C0&);
extern int D_004F7F48;
extern char D_004F7F4C;
extern char* D_004F7F50;
}
#pragma opt_common_subs off
extern "C" void cBackpack_PurgeCrateSaves(void) {
    if (D_004F7F48 > 0) {
        char* end;
        {
            char* n;
            char* it;
            std_list_CrateSavePtr_generic_iterator_ctor(&it, std_list_deleter_voidPtr_begin_void(&D_004F7F48));
            n = it;
            while ((cLListIterator_CrateSavePtr_ctor(&end, std_list_CrateSavePtr_end(&D_004F7F48)), n != end)) {
                void* e = F_(n, 0x8, void*);
                {
                    AllocGuard g;
                    cMemMan_Deallocate(0, e, "backpack.cc", 0x202);
                }
                n = F_(n, 0x4, char*);
            }
        }
        {
            int res;
            char* first;
            char* last;
            last = &D_004F7F4C;
            first = D_004F7F50;
            std_list_deleter_voidPtr_erase_listdeleter_listdeleter(&res, &D_004F7F48, &first, &last);
        }
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002569C0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002569C0 */
