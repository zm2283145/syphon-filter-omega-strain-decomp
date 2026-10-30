/*
 * SFOGame/Source/GuiObjectives: 3 files, 00367AF0-00367D60
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00367AF0 */
#pragma push /* merge_units */
#include "types.h"
extern int strcmp(void* obj);
/* True when strcmp returns 0 for the global object "GuiObjectives". */
int GuiObjectives_IsClass(void)
{
    return strcmp("GuiObjectives") == 0;
}
static inline void merge_flush_func_00367AF0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00367AF0 */

/* merge_units: begin func_00367B20 */
#pragma push /* merge_units */
// GuiObjectives::SetActiveTab(int,bool). SendMessage arg as (int)D_004BBC58 (hoisted invariant); w48->Sub()->F2(!quiet&&x94)
// via inline Sub() accessor fixes a0/a1 (this vs bool) coloring.
#pragma cplusplus on
typedef struct W {
    char pad0[0x14];
    unsigned short flags;
    char pad16[0x88 - 0x16];
    struct W* sub;
    char pad8C[0x94 - 0x8C];
    int x94;
    void F4(bool on) { if (on) flags |= 4; else flags &= ~4; }
    void F2(bool on) { if (on) flags |= 2; else flags &= ~2; }
    W* Sub() { return sub; }
} W;
typedef struct P {
    char pad0[0x48];
    W* w48;
    char pad4C[0x58 - 0x4C];
    int sel;
    char pad5C[0x60 - 0x5C];
    W* tab[2];
    W* lbl[2];
    char pad70[0x88 - 0x70];
    unsigned char x88;
} P;
extern "C" {
extern char D_004BBC58[];
extern void GuiWidget_SendMessage(P* p, W* l, int a, int s, int b);
extern void GuiArrayWidget_SetSelected(W* w, int a, int b);
extern void* Gui_Canvas(void);
extern void GuiCanvas_SetFocus(void* s, W* w);
}

static inline void SetF4(W* w, bool on) { if (on) w->flags |= 4; else w->flags &= ~4; }
static inline void SetF2(W* w, bool on) { if (on) w->flags |= 2; else w->flags &= ~2; }
static inline void SetF2b(W* w, bool on) { if (on) w->flags |= 2; else w->flags &= ~2; }

extern "C" void GuiObjectives_SetActiveTab(P* p, int idx, int quiet)
{
    int i;
    if (p->tab[idx] == 0) return;
    for (i = 0; i < 2; i++) {
        if (p->tab[i]) {
            p->tab[i]->F4(i == idx);
            p->tab[i]->F2(i == idx);
        }
        if (p->lbl[i]) {
            if (idx == i) GuiWidget_SendMessage(p, p->lbl[i], 6, (int)D_004BBC58, 0);
            else GuiWidget_SendMessage(p, p->lbl[i], 0xB, 0, 0);
        }
    }
    if (p->w48 && p->w48->sub) {
        if (quiet) {
            GuiArrayWidget_SetSelected(p->w48, 0, 0);
            p->w48->flags &= ~0x80;
        } else {
            p->w48->flags |= 0x80;
            GuiCanvas_SetFocus(Gui_Canvas(), p->w48);
        }
        p->w48->Sub()->F2(!quiet && p->w48->x94);
    }
    if (!p->x88 && p->lbl[1]) {
        if (idx == 1) {
            p->lbl[1]->flags |= 0x80;
            GuiCanvas_SetFocus(Gui_Canvas(), p->lbl[1]);
        } else {
            p->lbl[1]->flags &= ~0x80;
        }
    }
    p->sel = idx;
}
static inline void merge_flush_func_00367B20(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00367B20 */

/* merge_units: begin func_00367D60 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "label_text_refresh.h"

struct L367D60 {
    char pad[0x34];
    float x;
    char pad38[0x3C - 0x38];
    float w;
    float h;
    char pad44[0x5C - 0x44];
    unsigned int rowH;
    char pad60[0x94 - 0x60];
    int count;
};
struct O367D60 { char pad[0x20]; int a20; char pad24[0x60 - 0x24]; int a60; };
struct S367D60 {
    char pad[0x48];
    void* lists[3];
    L367D60* list;
    char pad58[0x5C - 0x58];
    int sel;
    char pad60[0x78 - 0x60];
    int top;
    int minH;
    L367D60* w80;
    int a84;
    unsigned char b88;
};

extern "C" {
extern char D_004BBC70[];
extern char D_004BBC80[];
void* ObjMan_GetService(void);
int cObjectiveMan_GetObjectiveCount(void* mgr);
int cObjectiveMan_GetFailedObjectives(void* mgr, O367D60** out, int max);
int cObjectiveMan_GetSucceededObjectives(void* mgr, O367D60** out, int max, unsigned char flag);
int cObjectiveMan_GetParameters(void* mgr, O367D60** out, int max);
int cObjectiveMan_GetCurrentObjectives(void* mgr, O367D60** out, int max);
void GuiTextListWidget_Clear(void* list);
void GuiTextListWidget_AddItem(void* list, int a, int b, int c);
int GuiTextListWidget_FindItem_int(void* list, int sel);
#if 0 /* merge_units */
void GuiArrayWidget_SetSelected(void* list, int a, int b);
#endif /* merge_units */
#define GuiArrayWidget_SetSelected(a0, a1, a2) (GuiArrayWidget_SetSelected((W *)(a0), (a1), (a2))) /* merge_units */

void GuiWidget_SetPosition(L367D60* w, float x, float y);
void GuiArrayWidget_SetVisibleSize(L367D60* w, int a, int b);
int sprintf(char* buf, const char* fmt, ...);
}

static inline void SetSize(L367D60* w, float ww, float hh)
{
    w->w = ww;
    w->h = hh;
}

/* Refresh the object list tabs and resize the list widget to its rows. */
extern "C" void GuiObjectives_UpdateObjectives(S367D60* self)
{
    void* mgr;
    char buf[0x20];
    O367D60* tmp[0x14];
    O367D60* objs[0x20];
    int sel;
    int i;

    mgr = ObjMan_GetService();
    if (mgr == 0) return;
    {
        LtrWidget* w = Ltr_Cast(GuiWidget_FindChild_charP(self, D_004BBC70));
        if (w) {
            int n = cObjectiveMan_GetSucceededObjectives(mgr, tmp, 0x14, 1);
            sprintf(buf, D_004BBC80, n, cObjectiveMan_GetObjectiveCount(mgr));
            GuiTextWidget_SetText(w, buf, 0);
        }
    }
    sel = self->sel;
    for (i = 0; i < 4; i++) {
        if (self->lists[i] != 0) {
            int n;
            int j;
            switch (i) {
            case 0: n = cObjectiveMan_GetCurrentObjectives(mgr, objs, 0x20); break;
            case 1: n = cObjectiveMan_GetParameters(mgr, objs, 0x20); break;
            case 2: n = cObjectiveMan_GetSucceededObjectives(mgr, objs, 0x20, self->b88); break;
            case 3: n = cObjectiveMan_GetFailedObjectives(mgr, objs, 0x20); break;
            default: return;
            }
            GuiTextListWidget_Clear(self->lists[i]);
            for (j = 0; j < n; j++) {
                if (objs[j]->a60 != 0)
                    GuiTextListWidget_AddItem(self->lists[i], objs[j]->a60, objs[j]->a20, 0);
            }
        }
    }
    if (self->lists[0] != 0 && sel != -1) {
        int idx = GuiTextListWidget_FindItem_int(self->lists[0], sel);
        if (idx != -1) GuiArrayWidget_SetSelected(self->lists[0], 0, idx);
    }
    {
        L367D60* l = self->list;
        if (l != 0) {
            int count;
            unsigned int rowH;
            int rows;
            rowH = l->rowH;
            count = l->count;
            rows = l->h / (float)rowH;
            if (rows != count) {
                int total = count * rowH;
                int y = self->top + (total - self->minH);
                if (total < self->minH) {
                    total = self->minH;
                    y = self->top;
                }
                GuiWidget_SetPosition(l, l->x, (float)y);
                SetSize(self->list, self->list->w, (float)total);
                if (self->w80 != 0)
                    GuiWidget_SetPosition(self->w80, self->w80->x, (float)(y + self->a84));
            }
            GuiArrayWidget_SetVisibleSize(self->list, 1, self->list->count);
        }
    }
}
#undef GuiArrayWidget_SetSelected /* merge_units */
static inline void merge_flush_func_00367D60(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00367D60 */
