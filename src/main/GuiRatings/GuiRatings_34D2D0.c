/*
 * main/GuiRatings: range (2 files, 0034D2D0-0034D600)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* library prototypes shared by the blocks below (C linkage) */
int sprintf(void *, const void *, ...);

/* merge_units: begin func_0034D2D0 */
#pragma push /* merge_units */
#pragma cplusplus on
struct O_34D2D0;
typedef struct { int f0; char pad4[4]; unsigned char b8; char pad9[0xB]; } E_34D2D0;
struct O_34D2D0 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual int v19();
    char s4[0x60];
    int f64;
    char pad68[0xD4 - 0x68];
    E_34D2D0* ents;
};
typedef struct { unsigned short type; unsigned short b2; char pad4[2]; unsigned short b6; unsigned short btn; } Ev_34D2D0;
typedef struct { char pad[0x10]; int f10; } Sel_34D2D0;
typedef struct { char pad[0x20]; Sel_34D2D0* f20; } M_34D2D0;
typedef struct { char pad[0x25C]; int f25C; } G_34D2D0;
extern "C" {
extern G_34D2D0* D_004FFC04;
char D_004BA818[] = "GuiSlideShow"; void GuiRatings_MoveFocus(O_34D2D0* o, int k);
M_34D2D0* Gui_Canvas(void);
void* Gui_Manager(void);
void GuiWidget_SendMessage(void* a, void* b, int kind, int v, int f);
void* GuiManager_OpenGui(void* mgr, char* a, char* b);
void GuiCanvas_Transition(void* mgr, void* o, void* w);
char* std_basic_string_char_char_traits_char_c_str(void* s);
void GuiSlideShow_SetInfo(void* w, int a, char* s, int b);
void GuiSlideShow_Clear(void* w);
int GuiSlideShow_AddSection(void* w, int v);
void GuiSlideShow_AddSlide(void* w, int r, char* s, int v, char* t);
int GuiPersonnelScreen_onInput(O_34D2D0* o, Ev_34D2D0* ev);
int GuiRatings_onInput(O_34D2D0* o, Ev_34D2D0* ev);
}
static inline unsigned char Down_34D2D0(Ev_34D2D0* e) { unsigned char r = 0; if (e->type == 1 && e->b2 == 0) r = 1; return r; }
static inline unsigned char Plain_34D2D0(Ev_34D2D0* e) { unsigned char r = 0; if (Down_34D2D0(e) && e->b6 == 0) r = 1; return r; }
static inline bool Down2_34D2D0(Ev_34D2D0* e) { return e->type == 1 && e->b2 == 0; }
static inline bool Btn2_34D2D0(Ev_34D2D0* e, int b) { return Down2_34D2D0(e) && e->btn == b; }
static inline bool Plain2_34D2D0(Ev_34D2D0* e, int b) { return Btn2_34D2D0(e, b) && e->b6 == 0; }

int GuiRatings_onInput(O_34D2D0* o, Ev_34D2D0* ev)
{
    if (Plain_34D2D0(ev)) {
        switch ((unsigned int)ev->btn) {
        case 0x8000: GuiRatings_MoveFocus(o, 0); return 1;
        case 0x2000: GuiRatings_MoveFocus(o, 1); return 1;
        case 0x1000: GuiRatings_MoveFocus(o, 2); return 1;
        case 0x4000: GuiRatings_MoveFocus(o, 3); return 1;
        }
    }
    if (Plain2_34D2D0(ev, 0x40) && Gui_Canvas()->f20->f10 != -1) {
        int idx = Gui_Canvas()->f20->f10;
        void* w;
        E_34D2D0** ep = &o->ents;
        if (((E_34D2D0*)((char*)o->ents + idx * 20))->b8) {
            GuiWidget_SendMessage(o, Gui_Canvas(), 0x10, 1, 0);
            w = GuiManager_OpenGui(Gui_Manager(), D_004BA818, "ZEUSHELL");
            if (w) {
                char b0[16];
                char b1[16];
                char* s = std_basic_string_char_char_traits_char_c_str(o->s4);
                int r;
                GuiSlideShow_SetInfo(w, o->v19(), s, idx);
                GuiSlideShow_Clear(w);
                r = GuiSlideShow_AddSection(w, (*ep)[idx].f0);
                sprintf(b0, "0_%d_%d.tdx", o->f64, idx + 1);
                if (idx % 4 == 2) idx--;
                sprintf(b1, "0_%d_%d", o->f64, idx + 1);
                GuiSlideShow_AddSlide(w, r, b0, D_004FFC04->f25C, b1);
                GuiCanvas_Transition(Gui_Canvas(), o, w);
            }
        } else {
            GuiWidget_SendMessage(o, Gui_Canvas(), 0x10, 4, 0);
        }
        return 1;
    }
    return GuiPersonnelScreen_onInput(o, ev);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0034D2D0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0034D2D0 */

/* merge_units: begin func_0034D600 */
#pragma push /* merge_units */
typedef struct { char pad[0x10]; int f10; } W34D;
typedef struct { char pad[0xC]; int fc; char p[4]; } E34D;
typedef struct { char pad[0x10]; int f10; char pad2[0x58]; int f6c[0x1A]; E34D* fd4; } O34D;
#if 0 /* merge_units */
extern int Gui_Canvas(void);
#endif /* merge_units */
#define Gui_Canvas() ((int)Gui_Canvas()) /* merge_units */

#if 0 /* merge_units */
extern void GuiWidget_SendMessage(O34D*, int, int, int, int);
#endif /* merge_units */
#define GuiWidget_SendMessage(a0, a1, a2, a3, a4) (GuiWidget_SendMessage((void *)(a0), (void *)(a1), (a2), (a3), (a4))) /* merge_units */

extern void GuiPersonnelScreen_SetupPreviewWidgets(O34D*, int, int);
extern void GuiCanvas_SetFocus(int, int);
extern int GuiPersonnelScreen_onMessage(O34D*, W34D*, int, int, int);
int GuiRatings_onMessage(O34D* o, W34D* w, int ev, int x, int y) {
    unsigned short e = ev;
    if (e == 0) {
        GuiWidget_SendMessage(o, Gui_Canvas(), 0x10, 0, 0);
        if (w->f10 != -1) {
            GuiPersonnelScreen_SetupPreviewWidgets(o, w->f10, ((E34D*)((char*)o->fd4 + w->f10 * 20))->fc);
            GuiWidget_SendMessage(o, (int)w, 6, (int)"onActivate", 0);
            return 1;
        }
    }
    if (e == 1 && w->f10 != -1) {
        GuiWidget_SendMessage(o, (int)w, 6, (int)"onDeactivate", 0);
        return 1;
    }
    if (e == 0x3000) {
        GuiCanvas_SetFocus(Gui_Canvas(), o->f6c[x]);
        o->f10 = x;
        return 1;
    }
    return GuiPersonnelScreen_onMessage(o, w, ev, x, y);
}
#undef Gui_Canvas /* merge_units */
#undef GuiWidget_SendMessage /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0034D600(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0034D600 */
