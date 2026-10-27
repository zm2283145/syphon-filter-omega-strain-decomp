/*
 * SFOGame/Source/GuiStartMenu: 5 files, 00454120-00454440
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00454120 */
#pragma push /* merge_units */
#include "types.h"
extern int strcmp(void* obj);
/* True when strcmp returns 0 for the global object "GuiRadioLog". */
int GuiRadioLog_IsClass(void)
{
    return strcmp("GuiRadioLog") == 0;
}
static inline void merge_flush_func_00454120(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00454120 */

/* merge_units: begin func_00454150 */
#pragma push /* merge_units */
#pragma cplusplus on
struct M_454150 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(void* o);
};
typedef struct { unsigned short type; unsigned short b2; char pad4[2]; unsigned short b6; unsigned short btn; } Ev_454150;
typedef struct { char pad[0x48]; void* f48; } O_454150;
extern "C" {
extern void* g_Hud;
extern char g_Game[];
M_454150* Gui_Canvas(void);
void GuiStartMenu_ReturnToMenu(O_454150* o);
void cHud_DeactivateObjectiveMenu(void* p);
void cGameSystem_PauseGame(void* p, int v);
int GuiRadioLog_onInput(O_454150* o, Ev_454150* ev);
}
static inline unsigned char Down_454150(Ev_454150* e) { unsigned char r = 0; if (e->type == 1 && e->b2 == 0) r = 1; return r; }
static inline unsigned char Btn_454150(Ev_454150* e, int b) { unsigned char r = 0; if (Down_454150(e) && e->btn == b) r = 1; return r; }
static inline unsigned char Plain_454150(Ev_454150* e, int b) { unsigned char r = 0; if (Btn_454150(e, b) && e->b6 == 0) r = 1; return r; }
static inline bool Down2_454150(Ev_454150* e) { return e->type == 1 && e->b2 == 0; }
static inline bool Btn2_454150(Ev_454150* e, int b) { return Down2_454150(e) && e->btn == b; }
static inline bool Plain2_454150(Ev_454150* e, int b) { return Btn2_454150(e, b) && e->b6 == 0; }

int GuiRadioLog_onInput(O_454150* o, Ev_454150* ev)
{
    if (Plain_454150(ev, 0x10)) {
        GuiStartMenu_ReturnToMenu(o);
        return 1;
    }
    if (Plain2_454150(ev, 0x800)) {
        Gui_Canvas()->v24(o);
        cHud_DeactivateObjectiveMenu(g_Hud);
        cGameSystem_PauseGame(g_Game, 0);
        return 1;
    }
    return 0;
}
static inline void merge_flush_func_00454150(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00454150 */

/* merge_units: begin func_00454280 */
#pragma push /* merge_units */
#pragma opt_strength_reduction off
enum OnOff { ON0, ON1 };
typedef struct Item { unsigned char flag; char name[0x20]; } Item;
typedef struct List_00454280 { int pad0; int count; Item* items; } List_00454280;
typedef struct Box { char pad[0x94]; unsigned int size; } Box;
typedef struct Self { char pad[0x48]; Box* box; } Self;
#if 0 /* merge_units */
extern List_00454280* g_Hud;
#endif /* merge_units */
#define g_Hud (*(List_00454280 **)&g_Hud) /* merge_units */

extern void GuiArrayWidget_GetSelected(Box*, int*, unsigned int*);
extern void GuiTextListWidget_Clear(Box*);
extern void GuiTextListWidget_AddItem(Box*, char*, int, int);
extern void GuiArrayWidget_SetSelected(Box*, int, unsigned int);
extern char* nGlobalization_GetString_charP(char*);
void GuiRadioLog_UpdateRadioLogList(Self* self)
{
    int a;
    unsigned int b;
    List_00454280* l;
    int i;
    if (self->box == 0) return;
    GuiArrayWidget_GetSelected(self->box, &a, &b);
    l = g_Hud;
    if (l == 0) return;
    GuiTextListWidget_Clear(self->box);
    for (i = 0; i < l->count; i++) {
        char* t = nGlobalization_GetString_charP(l->items[i].name);
        GuiTextListWidget_AddItem(self->box, t ? t : l->items[i].name, 0, l->items[i].flag ? ON1 : ON0);
    }
    if (b < self->box->size) GuiArrayWidget_SetSelected(self->box, 0, b);
}
#undef g_Hud /* merge_units */
static inline void merge_flush_func_00454280(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00454280 */

/* merge_units: begin func_00454380 */
#pragma push /* merge_units */
typedef struct { char p[0x14]; unsigned short flags; } C454380;
typedef struct { char p[0x88]; C454380* c; char p8C[8]; int f94; } S454380;
typedef struct { char p[0x14]; unsigned short flags; char p16[0x32]; S454380* s; } W454380;
typedef struct { int p0; int f4; } G454380;
#if 0 /* merge_units */
extern G454380* g_Hud;
#endif /* merge_units */
#define g_Hud (*(G454380 **)&g_Hud) /* merge_units */

extern void GuiWidget_onAdvanceTime(W454380* w);
#if 0 /* merge_units */
extern void GuiRadioLog_UpdateRadioLogList(W454380* w);
#endif /* merge_units */
#define GuiRadioLog_UpdateRadioLogList(a0) (GuiRadioLog_UpdateRadioLogList((Self *)(a0))) /* merge_units */

void GuiRadioLog_onAdvanceTime(W454380* w)
{
    C454380* c;
    GuiWidget_onAdvanceTime(w);
    {
        G454380* g;
S454380* s;
        if ((g = g_Hud) && (s = w->s) && g->f4 != s->f94) GuiRadioLog_UpdateRadioLogList(w);
    }
    if (w->s && (c = w->s->c)) {
        int on = w->s->f94 != 0 && (w->flags & 4) != 0; if (on) c->flags |= 2; else c->flags &= ~2;
    }
}
#undef g_Hud /* merge_units */
#undef GuiRadioLog_UpdateRadioLogList /* merge_units */
static inline void merge_flush_func_00454380(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00454380 */

/* merge_units: begin func_00454440 */
#pragma push /* merge_units */
#include "sound_event.h"
typedef struct { unsigned char flag; char pad1[0x10]; char name[0x10]; } Item_454440;
typedef struct { int pad0; int count; Item_454440* items; } List_454440;
typedef struct { char pad[0x94]; int count; } Box_454440;
typedef struct { char pad[0x48]; Box_454440* box; void* f4C; char f50[4]; } S_454440;
#if 0 /* merge_units */
extern List_454440* g_Hud;
#endif /* merge_units */
#define g_Hud (*(List_454440 **)&g_Hud) /* merge_units */

extern char D_004DADF0[];
extern void Libc_Strcpy(char*, char*);
extern void GuiSubTitleDisplay_Clear(void*);
extern void GuiRadioLog_StartPlayback(S_454440*, char*);
extern void GuiTextListWidget_SetItemState(Box_454440*, int, int);
extern int GuiWidget_onMessage(S_454440*, void*, unsigned short, int, int);

#pragma push
#pragma opt_propagation off
int GuiRadioLog_HandleEvent(S_454440* self, void* ev, unsigned short code, int a3, int idx)
{
    char buf[0x10];
    SoundEvent msg;

    if (code == 0x14) {
        cStopSoundMsg_ctor_cSndFxR_bool(&msg, self->f50, 0);
        msg.kind = 1;
        QueueMessage_cMessageR_cSystemP_int(&msg, g_Game, 1);
        if (self->f4C)
            GuiSubTitleDisplay_Clear(self->f4C);
        msg.vtable = D_004DADF0;
        cFileMan_dtor(&msg.req.b, -1);
        cFileMan_dtor(&msg.req.a, -1);
        cMessage_dtor(&msg, 0);
        return 1;
    }
    if (code == 0x13) {
        List_454440* l = g_Hud;
        buf[0] = 0;
        if (l && idx < l->count) {
            Libc_Strcpy(buf, l->items[idx].name);
            l->items[idx].flag = 1;
        }
        GuiRadioLog_StartPlayback(self, buf);
        if (self->box && idx < self->box->count)
            GuiTextListWidget_SetItemState(self->box, idx, 1);
        return 1;
    }
    return GuiWidget_onMessage(self, ev, code, a3, idx);
}
#pragma pop
#undef g_Hud /* merge_units */
static inline void merge_flush_func_00454440(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00454440 */
