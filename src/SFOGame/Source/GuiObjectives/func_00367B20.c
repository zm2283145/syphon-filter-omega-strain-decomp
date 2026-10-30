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







