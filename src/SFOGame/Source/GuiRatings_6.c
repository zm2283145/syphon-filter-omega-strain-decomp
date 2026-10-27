/*
 * SFOGame/Source/GuiRatings: 11 files, 0034DC20-0034E280
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0034DC20 */
#pragma push /* merge_units */
#include "types.h"
#pragma push
#pragma cplusplus on
#include "alloc_guard.h"
#pragma pop
#include "vslot_pad.h"

/* library prototypes shared by the blocks below (C linkage) */
int sprintf(void *, const void *, ...);

#pragma cplusplus on

/* Create the 0x60-byte text record at +0xDC under the allocator guard. */
struct R34DC20 { char pad[0x10]; unsigned char a10; char pad11; unsigned char a12; };
struct S34DC20 { char pad[0xDC]; R34DC20* aDC; };
extern "C" {
extern char D_004BA880[];
extern char D_00587C80[];
void* cMemMan_Allocate(int pool, int size, char* file, int line);
void GuiPersonnelScreen_onWake(S34DC20* o);
void* Gui_Manager(void);
void* GuiManager_GetFont(void* mgr, char* name);
R34DC20* cTextArea_ctor(void* p, int a, int b, int c, int d, void* e, char* f);
void GuiRatings_onWake(S34DC20* o);
}
void GuiRatings_onWake(S34DC20* o)
{
    void* p;
    GuiPersonnelScreen_onWake(o);
    {
        AllocGuard guard;
        p = cMemMan_Allocate(0, 0x60, D_004BA880, 0x83);
    }
    if (p) p = cTextArea_ctor(p, 0, 0, 10, 10, GuiManager_GetFont(Gui_Manager(), "callout"), D_00587C80);
    o->aDC = (R34DC20*)p;
    o->aDC->a10 = 2;
    o->aDC->a12 = 1;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0034DC20(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0034DC20 */

/* merge_units: begin func_0034DD20 */
#pragma push /* merge_units */
#pragma cplusplus on
struct QCol { float r, g, b, a; QCol(float r_, float g_, float b_, float a_) { r = r_; g = g_; b = b_; a = a_; } } __attribute__((aligned(16)));
class W {
public:
    VPAD16(a) VPAD4(b)
    virtual bool IsA(void* type);
    char pad4[0xC];
    int idx;
    unsigned short flags;
    char pad16[0x60 - 0x16];
    float r, g, b, a;
    void SetColor(QCol c) { r = c.r; g = c.g; b = c.b; a = c.a; }
};
typedef struct { char pad[8]; unsigned char used; char pad9[0xB]; } Entry;
struct RList { int f0; int count; Entry *entries; int Count() { return count; } Entry &operator[](unsigned int i) { return entries[i]; } };
struct Self {
    char pad[0x64];
    int f64;
    char pad68[4];
    W *items[24];
    RList list;
};
struct G { char pad[0x25C]; int f25C; };
extern "C" {
extern char *D_00492BB8;
extern char D_004B88F0[];
extern char g_Game[];
extern G *D_004FFC04;
void GuiPersonnelScreen_onAdd(Self *self);
void std_vector_deleter_tAchievementInfo_clear(void *p);
int cGameSystem_GetAgentData(void *a, int i);
void cAgentData_GetRatings(int agent, void *p);
W *GuiWidget_FindChild_charP(void *self, char *name);
void GuiBitmapWidget_SetBitmap(W *w, char *s, int f);
}
static inline W *Cast(W *w, char *type) { return (w && w->IsA(type)) ? w : 0; }
static inline float Alpha(RList *l, int n) { float a = 1.0f; if (n < l->Count()) a = (*l)[n].used ? 1.0f : 0.3f; return a; }
extern "C" void GuiRatings_onAdd(Self *self)
{
    W *grp;
    int i;
    char name[16];
    char text[64];

    GuiPersonnelScreen_onAdd(self);
    std_vector_deleter_tAchievementInfo_clear(&self->list);
    cAgentData_GetRatings(cGameSystem_GetAgentData(g_Game, -1), &self->list);
    grp = GuiWidget_FindChild_charP(self, D_00492BB8);
    if (grp == 0)
        return;
    for (i = 0; i < 24; i++) {
        sprintf(name, "%2.2d", i + 1);
        self->items[i] = Cast(GuiWidget_FindChild_charP(grp, name), D_004B88F0);
        if (self->items[i]) {
            float alpha;
            sprintf(text, "0_%d_%ds.tdx", self->f64, i + 1);
            GuiBitmapWidget_SetBitmap(self->items[i], text, D_004FFC04->f25C);
            self->items[i]->idx = i;
            self->items[i]->flags |= 0x80;
            alpha = Alpha(&self->list, i);
            self->items[i]->SetColor(QCol(1.0f, 1.0f, 1.0f, alpha));
        }
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0034DD20(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0034DD20 */

/* merge_units: begin func_0034DF40 */
#pragma push /* merge_units */
typedef struct { char pad[0xC]; unsigned char aC; } M34DF40;
typedef struct { void* vtable; char pad4[0x60]; int a64; int pad68; int a6C[24]; M34DF40 mCC; } S34DF40;
extern char D_004DECC0[];
extern void GuiPersonnelScreen_ctor(S34DF40* self);
extern void func_00296FA0(M34DF40* m);
S34DF40* GuiRatings_ctor(S34DF40* self)
{
    int i;
    M34DF40* m;
    GuiPersonnelScreen_ctor(self);
    self->vtable = D_004DECC0;
    m = &self->mCC;
    func_00296FA0(m);
    m->aC = 1;
    for (i = 0; i < 24; i++) self->a6C[i] = 0;
    self->a64 = 3;
    return self;
}
static inline void merge_flush_func_0034DF40(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0034DF40 */

/* merge_units: begin func_0034DFD0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "member_dtor_chain.h"

/* Deleting destructor that runs the member destructor. */
DEFINE_MEMBER_DTOR_CHAIN(func_0034DFD0, func_00299360)
static inline void merge_flush_func_0034DFD0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0034DFD0 */

/* merge_units: begin func_0034E040 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "base_dtor_chain.h"

/* Deleting destructor that runs the base destructor. */
DEFINE_BASE_DTOR_CHAIN(func_0034E040, func_00299360)
static inline void merge_flush_func_0034E040(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0034E040 */

/* merge_units: begin func_0034E0A0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vtable_base_dtor.h"

/* Derived destructor: restore vtable, run base destructor, optionally delete. */
DEFINE_VTABLE_BASE_DTOR(GuiPersonnelScreen_dtor_34E0A0, D_004DF0B0, GuiWidget_dtor)
static inline void merge_flush_func_0034E0A0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0034E0A0 */

/* merge_units: begin func_0034E100 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


Rel* func_0034E100(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}
static inline void merge_flush_func_0034E100(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0034E100 */

/* merge_units: begin func_0034E120 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "direct_base_dtor.h"

/* Deleting destructor that runs the base destructor. */
DEFINE_DIRECT_BASE_DTOR(func_0034E120, func_00299360)
static inline void merge_flush_func_0034E120(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0034E120 */

/* merge_units: begin func_0034E180 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "stream_string_dtor.h"

/* Destroy a string holder: free heap storage, optionally delete. */
DEFINE_STREAM_STRING_DTOR(String_Dtor_34E180)
static inline void merge_flush_func_0034E180(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0034E180 */

/* merge_units: begin func_0034E270 */
#pragma push /* merge_units */
void func_0034E270(char* self) {
    *(int*)(self + 4) = 0;
}
static inline void merge_flush_func_0034E270(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0034E270 */

/* merge_units: begin func_0034E280 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "clear_buffer_dtor.h"

/* Clear and free a vector, optionally delete. */
DEFINE_CLEAR_BUFFER_DTOR(func_0034E280, D_004AA5B8)
static inline void merge_flush_func_0034E280(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0034E280 */
