/*
 * main/GuiScoresEquip: range (4 files, 0035CFB0-0035D3D0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0035CFB0 */
#pragma push /* merge_units */
#include "types.h"
#pragma cplusplus on
#include "child_list_iter.h"

/* Set or clear flag 2 on every other child. */
extern "C" void func_0035CFB0(ChildWidget* o, int on);
void func_0035CFB0(ChildWidget* o, int on)
{
    ChildIter e;
    void* l;
    ChildNode* n;
    if (o == 0) return;
    n = ChildList_Begin(CHILD_LIST(o));
    l = CHILD_LIST(o);
    for (; ChildList_End(&e, l), n != e.p; n = n->next) {
        ChildWidget* c = n->obj;
        if (c != o) {
            if (on) c->flags |= 2;
            else c->flags &= ~2;
        }
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_0035CFB0 */

/* merge_units: begin func_0035D0A0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vslot_pad.h"
class W35D0A0 {
public:
    VPAD16(a) VPAD4(b)
    virtual bool IsA(void* type);
    char pad[0x10]; unsigned short a14;
};
struct S35D0A0 { char pad[0x224]; int a224; };
extern "C" {
extern char D_004BB4D8[];
extern char D_004BB4E8[];
extern char D_004BB500[];
extern char D_004BB520[];
extern char D_004BB530[];
extern char D_004BB540[];
extern char D_004A9870[];
W35D0A0* GuiWidget_FindChildByName(void* self, char* name);
char* Loc_LookupText(char* key);
void func_0041BEB0(W35D0A0* w, char* text, int flags);
void func_0035D0A0(S35D0A0* o, int mode);
}
static inline W35D0A0* cast35D0A0(W35D0A0* w)
{
    return (w && w->IsA(D_004A9870)) ? w : 0;
}
/* Switches the screen between its two modes: toggles two widgets and relabels a third. */
void func_0035D0A0(S35D0A0* o, int mode)
{
    W35D0A0* a;
    W35D0A0* b;
    W35D0A0* c;
    o->a224 = mode;
    a = GuiWidget_FindChildByName(o, D_004BB4D8);
    b = GuiWidget_FindChildByName(o, D_004BB4E8);
    if (a) {
        if (!mode) a->a14 |= 2;
        else a->a14 &= ~2;
    }
    if (b) {
        if (mode) b->a14 |= 2;
        else b->a14 &= ~2;
    }
    c = cast35D0A0(GuiWidget_FindChildByName(o, D_004BB500));
    if (c) {
        char* t = Loc_LookupText(mode == 0 ? D_004BB520 : D_004BB540);
        func_0041BEB0(c, t ? t : D_004BB530, 0);
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_0035D0A0 */

/* merge_units: begin func_0035D1F0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "alloc_guard.h"
struct V0035D1F0 { virtual void v0(int f); virtual int v1(); virtual int v2(); virtual int v3(); virtual int v4(); virtual int v5(); virtual int v6(); virtual int v7(); virtual int v8(); virtual int v9(); virtual int v10(); virtual int v11(); virtual int v12(); virtual int v13(); virtual int v14(); virtual int v15(); virtual int v16(); virtual int v17(); virtual int v18(); virtual int v19(); virtual int v20(); virtual int v21(); virtual void v22(int f); char pad4[0x2420 - 4]; short h2420; char pad2422[0x2C74 - 0x2422]; int x2C74; };
struct O0035D1F0 { void* vt; char pad[0x1A0]; V0035D1F0* items[4]; V0035D1F0* p1B4; };
extern "C" {

extern char D_0055DDA0[];
extern char D_004DF140[];
extern char D_004E1220[];
extern int D_00506500;
void Mem_Free(int pool, void* p, char* file, int line);
void func_00403310(void* p);
void func_0040F540(void);
void func_002BDC10(void* p);
void func_0041F370(void* p, int f);
void operator_delete(void* p);
}
static inline void Del0035D1F0(V0035D1F0* o, int line)
{
    AllocGuard g;
    o->v0(-1);
    Mem_Free(0, o, "GuiScoresEquip.cc", line);
}
extern "C" O0035D1F0* func_0035D1F0(O0035D1F0* self, short del)
{
    if (self) {
        int i;
        self->vt = D_004DF140;
        Del0035D1F0(self->p1B4, 0xB9);
        for (i = 0; i < 4; i++) {
            self->items[i]->h2420 = 0;
            self->items[i]->x2C74 = 0;
            self->items[i]->v22(1);
            Del0035D1F0(self->items[i], 0xBF);
        }
        func_0040F540();
        func_0041F370(self, 0);
        if (del > 0)
            operator_delete(self);
    }
    return self;
}
#pragma pop /* merge_units */
/* merge_units: end func_0035D1F0 */

/* merge_units: begin func_0035D3D0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vtable_base_dtor.h"

/* Derived destructor: restore vtable, run cGOBJ base destructor, optionally delete. */
DEFINE_VTABLE_BASE_DTOR(func_0035D3D0, D_004DA470, cGOBJ_dtor)
#pragma pop /* merge_units */
/* merge_units: end func_0035D3D0 */
