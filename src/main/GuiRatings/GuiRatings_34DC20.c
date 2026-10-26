/*
 * main/GuiRatings: range (2 files, 0034DC20-0034DD20)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#pragma push
#pragma cplusplus on
#include "alloc_guard.h"
#pragma pop
#include "vslot_pad.h"

/* library prototypes shared by the blocks below (C linkage) */
int sprintf(void *, const void *, ...);

/* merge_units: begin func_0034DC20 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Create the 0x60-byte text record at +0xDC under the allocator guard. */
struct R34DC20 { char pad[0x10]; unsigned char a10; char pad11; unsigned char a12; };
struct S34DC20 { char pad[0xDC]; R34DC20* aDC; };
extern "C" {
extern char D_004BA880[];
extern char D_00587C80[];
void* Mem_Alloc(int pool, int size, char* file, int line);
void GuiPersonnelScreen_Wake(S34DC20* o);
void* Gui_GetScreenList(void);
void* GuiFont_Find(void* mgr, char* name);
R34DC20* TextObj_Construct(void* p, int a, int b, int c, int d, void* e, char* f);
void GuiRatings_Wake(S34DC20* o);
}
void GuiRatings_Wake(S34DC20* o)
{
    void* p;
    GuiPersonnelScreen_Wake(o);
    {
        AllocGuard guard;
        p = Mem_Alloc(0, 0x60, D_004BA880, 0x83);
    }
    if (p) p = TextObj_Construct(p, 0, 0, 10, 10, GuiFont_Find(Gui_GetScreenList(), "callout"), D_00587C80);
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
void GuiPersonnelScreen_Init(Self *self);
void std_vector_deleter_tAchievementInfo_clear(void *p);
int Agent_GetSelected(void *a, int i);
void AgentData_GetRatings(int agent, void *p);
W *GuiWidget_FindChildByName(void *self, char *name);
void GuiBitmapWidget_SetImage(W *w, char *s, int f);
}
static inline W *Cast(W *w, char *type) { return (w && w->IsA(type)) ? w : 0; }
static inline float Alpha(RList *l, int n) { float a = 1.0f; if (n < l->Count()) a = (*l)[n].used ? 1.0f : 0.3f; return a; }
extern "C" void GuiRatings_Init(Self *self)
{
    W *grp;
    int i;
    char name[16];
    char text[64];

    GuiPersonnelScreen_Init(self);
    std_vector_deleter_tAchievementInfo_clear(&self->list);
    AgentData_GetRatings(Agent_GetSelected(g_Game, -1), &self->list);
    grp = GuiWidget_FindChildByName(self, D_00492BB8);
    if (grp == 0)
        return;
    for (i = 0; i < 24; i++) {
        sprintf(name, "%2.2d", i + 1);
        self->items[i] = Cast(GuiWidget_FindChildByName(grp, name), D_004B88F0);
        if (self->items[i]) {
            float alpha;
            sprintf(text, "0_%d_%ds.tdx", self->f64, i + 1);
            GuiBitmapWidget_SetImage(self->items[i], text, D_004FFC04->f25C);
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
