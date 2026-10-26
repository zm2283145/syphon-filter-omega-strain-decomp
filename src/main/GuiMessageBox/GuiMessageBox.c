/*
 * main/GuiMessageBox: 3 files, 002A7DF0-002A8390
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin GuiMessageBox_2A7DF0 */
#pragma push /* merge_units */
#include "types.h"

typedef struct Label14 {
    int unk00;
    void* title;   /* 0x04 */
    void* body;    /* 0x08 */
    int pad[2];
} Label14;

typedef struct LabelSet {
    char pad00[0x54];
    int current;           /* 0x54 */
    Label14 labels[4];     /* 0x58 */
} LabelSet;

const unsigned int D_004AB580[4] = { 0x0, 0x0, 0x0, 0x0 };
extern void GuiTextWidget_SetText(void* widget, const char* text, int flags);

/* Sets the title/body text of the current label, using "" for null strings. */
void GuiMessageBox_SetMessageText(LabelSet* set, const char* title, const char* body) {
    Label14* label = &set->labels[set->current];
    if (label->title) {
        GuiTextWidget_SetText(label->title, title ? title : ((char*)D_004AB580), 0);
    }
    if (label->body) {
        GuiTextWidget_SetText(label->body, body ? body : ((char*)D_004AB580), 0);
    }
}
#pragma pop /* merge_units */
/* merge_units: end GuiMessageBox_2A7DF0 */

/* merge_units: begin GuiMessageBox_2A7E90 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vslot_pad.h"
struct W7E { char p0[0x14]; unsigned short flags; };
struct E7E { W7E* w0; W7E* w4; W7E* w8; W7E* wC; W7E* w10; };
class S7E {
public:
    VPAD8(a) VPAD4(b) VPAD2(c) VPAD1(d) virtual W7E* DefFocus();
    char p4[0x10];
    unsigned short flags;
    char p16[0xA];
    W7E* focus;
    char p24[0x24];
    int mode;
    int x4C;
    int x50;
    int sel;
    E7E e[3];
};
class St7E;
extern "C" {
extern char* D_0048BB90;
extern char* D_0048BB98;
extern char* D_0048BBA0;
extern char* D_0048BBA8;
extern const unsigned int D_004AB580[4];
char* Loc_LookupText(char* key);
#if 0 /* merge_units */
void GuiTextWidget_SetText(W7E* w, char* text, int flags);
#endif /* merge_units */
#define GuiTextWidget_SetText(a0, a1, a2) (GuiTextWidget_SetText((void *)(a0), (const char *)(a1), (a2))) /* merge_units */

St7E* Gui_GetScreenStack(void);
void GuiScreen_SetFocus(St7E* s, W7E* w);
void GuiWidget_SendEvent(S7E* o, St7E* s, int a, int b, int c);
}
extern "C" void GuiMessageBox_Setup(S7E* self, int mode, char* t1, char* t2, int a4, int a5)
{
    E7E* e;
    W7E* w;
    self->mode = mode;
    self->x4C = a4;
    self->x50 = a5;
    if (mode == 6) {
        int i;
        for (i = 0; i < 3; i++) {
            if (self->e[i].w0) {
                w = self->e[i].w0;
                if (i == 2) w->flags |= 2; else w->flags &= (unsigned short)~2;
                w = self->e[i].w0;
                if (i == 2) w->flags |= 4; else w->flags &= ~4;
            }
        }
        self->sel = 2;
    } else if (t1 && *t1) {
        int i;
        for (i = 0; i < 3; i++) {
            if (self->e[i].w0) {
                w = self->e[i].w0;
                if (i == 1) w->flags |= 2; else w->flags &= (unsigned short)~2;
                w = self->e[i].w0;
                if (i == 1) w->flags |= 4; else w->flags &= ~4;
            }
        }
        self->sel = 1;
    } else {
        int i;
        for (i = 0; i < 3; i++) {
            if (self->e[i].w0) {
                w = self->e[i].w0;
                if (i == 0) w->flags |= 2; else w->flags &= (unsigned short)~2;
                w = self->e[i].w0;
                if (i == 0) w->flags |= 4; else w->flags &= ~4;
            }
        }
        self->sel = 0;
    }
    e = &self->e[self->sel];
    if (e->wC && e->w10) {
        switch (self->mode) {
        case 0:
        case 1:
            e->wC->flags &= ~2;
            e->w10->flags &= ~2;
            break;
        case 2:
            e->wC->flags |= 2;
            GuiTextWidget_SetText(e->wC, Loc_LookupText(D_0048BB90), 0);
            e->w10->flags &= (unsigned short)~2;
            break;
        case 4:
        case 5:
            e->wC->flags |= 2;
            GuiTextWidget_SetText(e->wC, Loc_LookupText(D_0048BB98), 0);
            e->w10->flags |= 2;
            GuiTextWidget_SetText(e->w10, Loc_LookupText(D_0048BBA0), 0);
            break;
        case 6:
            e->wC->flags |= 2;
            GuiTextWidget_SetText(e->wC, Loc_LookupText(D_0048BB90), 0);
            e->w10->flags |= 2;
            GuiTextWidget_SetText(e->w10, Loc_LookupText(D_0048BBA8), 0);
            break;
        default:
            e->wC->flags |= 2;
            GuiTextWidget_SetText(e->wC, Loc_LookupText(D_0048BB90), 0);
            e->w10->flags |= 2;
            GuiTextWidget_SetText(e->w10, Loc_LookupText(D_0048BBA8), 0);
            break;
        }
    }
    e = &self->e[self->sel];
    if (e->w4) GuiTextWidget_SetText(e->w4, t1 ? t1 : (t1 = (char*)D_004AB580), 0);
    if (e->w8) GuiTextWidget_SetText(e->w8, t2 ? t2 : (t2 = (char*)D_004AB580), 0);
    if (self->flags & 8) {
        if (self->mode == 5) self->focus = self->e[self->sel].w10;
        else self->focus = self->DefFocus();
        GuiScreen_SetFocus(Gui_GetScreenStack(), self->focus);
        GuiWidget_SendEvent(self, Gui_GetScreenStack(), 0x10, 2, 0);
    }
}
#undef GuiTextWidget_SetText /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end GuiMessageBox_2A7E90 */

/* merge_units: begin GuiMessageBox_2A8390 */
#pragma push /* merge_units */
typedef struct { char pad[0x14]; unsigned short flags; } E2A8390;
typedef struct { E2A8390* e; char pad[0x10]; } Ent2A8390;
typedef struct { char pad[0x54]; int sel; Ent2A8390 ent[3]; } S2A8390;
void GuiMessageBox_SetActiveMessageBox(S2A8390* s, int sel)
{
    int i;
    for (i = 0; i < 3; i++) {
        if (s->ent[i].e) {
            if (sel == i)
                s->ent[i].e->flags |= 2;
            else
                s->ent[i].e->flags &= ~2;
            {
                E2A8390* e = s->ent[i].e;
                if (sel == i)
                    e->flags |= 4;
                else
                    e->flags &= ~4;
            }
        }
    }
    s->sel = sel;
}
#pragma pop /* merge_units */
/* merge_units: end GuiMessageBox_2A8390 */
