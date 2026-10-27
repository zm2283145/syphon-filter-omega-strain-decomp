/*
 * SFOGame/Source/GuiMissionLobbyScreen: 4 files, 0033D8C0-0033DE00
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0033D8C0 */
#pragma push /* merge_units */
#include "types.h"
typedef struct { char pad[0xAC]; signed char v; } T;
typedef struct { char pad[0x88]; T* t; } S;
/* Returns the linked object's byte at +0xAC, or 1 when none. */
int GuiMissionLobbyScreen_GetDisplayMode(S* s) { if (s->t) return s->t->v; return 1; }
static inline void merge_flush_func_0033D8C0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0033D8C0 */

/* merge_units: begin func_0033D8E0 */
#pragma push /* merge_units */
typedef struct {
    char pad0[0x88];
    void *ui;
    char pad8C[0xA8 - 0x8C];
    void *cur;
    char padAC[0xC8 - 0xAC];
    char a[0xE4 - 0xC8];
    char b[4];
} Obj;
extern void *cDME_GetLobby(void);
extern void SFOLobby_LobbySetDisplay(void *p, int v);
extern void GuiArrayWidget_SetSelected(void *p, int a, int b);
extern void GuiMissionList_SetDisplayMode(void *p, unsigned char mode);
extern void func_002ACC80(void *p, void *cur);

void GuiMissionLobbyScreen_SetDisplayMode(Obj *o, unsigned char mode)
{
    if (mode == 1 || mode == 3 || mode == 2) {
        if (o->cur != o->a) {
            if (cDME_GetLobby()) {
                SFOLobby_LobbySetDisplay(cDME_GetLobby(), 0);
            }
            o->cur = o->a;
        }
        o->cur = o->a;
    } else if (mode == 0) {
        if (o->cur != o->b) {
            if (cDME_GetLobby()) {
                SFOLobby_LobbySetDisplay(cDME_GetLobby(), 1);
            }
            o->cur = o->b;
        }
    }
    if (o->ui) {
        GuiArrayWidget_SetSelected(o->ui, 0, 0);
        GuiMissionList_SetDisplayMode(o->ui, mode);
        func_002ACC80(o->ui, o->cur);
    }
}
static inline void merge_flush_func_0033D8E0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0033D8E0 */

/* merge_units: begin func_0033DA00 */
#pragma push /* merge_units */
typedef struct { unsigned short type; unsigned short b2; char pad4[2]; unsigned short b6; unsigned short btn; } Ev_33DA00;
typedef struct { char pad[0x20]; void* f20; } M_33DA00;
typedef struct { char pad[0x88]; void* f88; void* f8C; int f90; char pad94[4]; void* f98; void* f9C; void* fA0; void* fA4; } O_33DA00;
M_33DA00* Gui_Canvas(void);
void GuiCanvas_SetFocus(void* mgr, void* w);
void GuiWidget_SendMessage(void* a, void* b, int kind, int v, int f);
void GuiLobbyScreen_PushLobbyScreen(O_33DA00* o, int v);
void GuiMLTextWidget_ScrollUp(void* p, int v);
void GuiMLTextWidget_ScrollDown(void* p, int v);
void func_002AEC60(void* p);
int GuiMissionLobbyScreen_ButtonAction(O_33DA00* o, void* w, int v);
int GuiLobbyScreen_onInput(O_33DA00* o, Ev_33DA00* ev);
static inline unsigned char Down_33DA00(Ev_33DA00* e) { unsigned char r = 0; if (e->type == 1 && e->b2 == 0) r = 1; return r; }
static inline unsigned char Btn_33DA00(Ev_33DA00* e, int b) { unsigned char r = 0; if (Down_33DA00(e) && e->btn == b) r = 1; return r; }
static inline unsigned char Plain_33DA00(Ev_33DA00* e, int b) { unsigned char r = 0; if (Btn_33DA00(e, b) && e->b6 == 0) r = 1; return r; }
static inline int Down2_33DA00(Ev_33DA00* e) { return e->type == 1 && e->b2 == 0; }
static inline int Btn2_33DA00(Ev_33DA00* e, int b) { return Down2_33DA00(e) && e->btn == b; }
static inline int Plain2_33DA00(Ev_33DA00* e, int b) { return Btn2_33DA00(e, b) && e->b6 == 0; }

int GuiMissionLobbyScreen_onInput(O_33DA00* o, Ev_33DA00* ev)
{
    if (Plain_33DA00(ev, 0x10) || Plain2_33DA00(ev, 0x8000)) {
        if (Gui_Canvas()->f20 == o->f88) {
            void* t = 0;
            switch (o->f90) {
            case 0: t = o->f9C; break;
            case 1: t = o->fA0; break;
            case 2: t = o->f98; break;
            case 3: t = o->fA4; break;
            }
            if (t) {
                GuiCanvas_SetFocus(Gui_Canvas(), t);
                { void* w = Gui_Canvas()->f20; GuiWidget_SendMessage(w, Gui_Canvas(), 0x10, 0, 0); }
                return 1;
            }
        } else if (!Plain2_33DA00(ev, 0x8000)) {
            GuiLobbyScreen_PushLobbyScreen(o, 1);
            return 1;
        }
    }
    if (Plain_33DA00(ev, 2)) {
        GuiMLTextWidget_ScrollUp(o->f8C, 0);
        return 1;
    }
    if (Plain2_33DA00(ev, 1)) {
        GuiMLTextWidget_ScrollDown(o->f8C, 0);
        return 1;
    }
    if (Plain2_33DA00(ev, 0x100)) {
        func_002AEC60(o->f8C);
        return 1;
    }
    if (Plain2_33DA00(ev, 0x2000) && GuiMissionLobbyScreen_ButtonAction(o, Gui_Canvas()->f20, 0)) {
        { void* w = Gui_Canvas()->f20; GuiWidget_SendMessage(w, Gui_Canvas(), 0x10, 0, 0); }
        return 1;
    }
    return GuiLobbyScreen_onInput(o, ev);
}
static inline void merge_flush_func_0033DA00(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0033DA00 */

/* merge_units: begin func_0033DE00 */
#pragma push /* merge_units */
typedef struct { char pad[0x28]; char key[4]; char p2c[0x68 - 0x2C]; unsigned int flags; } G3DE00;
typedef struct { int id; char a[0x20]; char b[0x40]; unsigned char c; } E3DE00;
typedef struct { char d[0x4]; int count; } L3DE00;
typedef struct {
    char p0[0x8C]; void* p8C; char p90[0xAC - 0x90];
    char lAC[4]; int count;
} T3DE00;
extern void GuiLobbyScreen_onAdvanceTime(T3DE00* self);
#if 0 /* merge_units */
extern G3DE00* Gui_Canvas(void);
#endif /* merge_units */
#define Gui_Canvas() ((G3DE00 *)Gui_Canvas()) /* merge_units */

extern T3DE00** func_0033DEF0(void* key);
#if 0 /* merge_units */
extern int cDME_GetLobby(void);
#endif /* merge_units */
#define cDME_GetLobby() ((int)cDME_GetLobby()) /* merge_units */

extern E3DE00* SFOLobbyList_GetSlot(void* list, int i);
extern void GuiChatWindow_AddChatLine(void* p, char* a, char* b, unsigned char c);
extern void SFOLobbyList_ClearList(void* list);
void GuiMissionLobbyScreen_onAdvanceTime(T3DE00* self)
{
    G3DE00* g;
    int on;
    int i;
    GuiLobbyScreen_onAdvanceTime(self);
    on = *func_0033DEF0(Gui_Canvas()->key) == self;
    g = Gui_Canvas();
    if (on)
        g->flags |= 3;
    else
        g->flags &= ~3;
    if (cDME_GetLobby() && self->count) {
        for (i = 0; i < self->count; i++) {
            E3DE00* e = SFOLobbyList_GetSlot(self->lAC, i);
            if (e)
                GuiChatWindow_AddChatLine(self->p8C, e->a, e->b, e->c);
        }
        SFOLobbyList_ClearList(self->lAC);
    }
}
#undef Gui_Canvas /* merge_units */
#undef cDME_GetLobby /* merge_units */
static inline void merge_flush_func_0033DE00(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0033DE00 */
