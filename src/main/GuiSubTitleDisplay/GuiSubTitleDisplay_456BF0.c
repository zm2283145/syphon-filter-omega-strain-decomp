/*
 * main/GuiSubTitleDisplay: 6 files, 00456BF0-00456F40
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00456BF0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#include "gui_widget_vslots.h"

struct LNode { LNode* prev; LNode* next; int* obj; };
struct O456 {
    char pad[0x8C]; void* f8C; void* arr[7]; char* acc; int fB0;
};

extern "C" {
extern char* D_00497960;
extern char* D_00497978;
extern char D_004A7520[];
extern char D_004C1A38[];
extern char D_004C1C60[];
extern char D_004C1C70[];
char* nGlobalization_GetString_charP(char*);
void std_list_deleter_voidPtr_begin_void(void*, void*);
void cLListIterator_GuiWidgetPtr_ctor_listR(void*, void*);
void std_list_GuiWidgetPtr_end(void*, void*);
void std_list_GuiWidgetPtr_generic_iterator_ctor(void*, void*);
void GuiObjectives_onAdd(void*);
void GuiTextWidget_SetText(void*, char*, int);
int sprintf(char*, const char*, ...);
void GuiStartMenu_onAdd(O456* o);
}

void GuiStartMenu_onAdd(O456* o)
{
    LNode* end;
    LNode* it;
    int a;
    int t;
    char buf[16];
    GuiWidgetV* w;

    o->acc = (char*)GuiWidget_FindChild_charP(o, D_00497960);
    if (o->acc) {
        int i = 0;
        LNode* n;
        std_list_deleter_voidPtr_begin_void(&a, o->acc + 0x28);
        std_list_GuiWidgetPtr_generic_iterator_ctor(&it, &a);
        n = it;
        while ((std_list_GuiWidgetPtr_end(&t, o->acc + 0x28), cLListIterator_GuiWidgetPtr_ctor_listR(&end, &t), n != end) && i < 7) {
            n->obj[4] = i;
            o->arr[i] = n->obj;
            i++;
            n = n->next;
        }
    }
    o->f8C = GuiWidget_FindChild_charP(o, D_00497978);
    GuiObjectives_onAdd(o);
    o->fB0 = 0;
    w = GuiFindAs(o, D_004C1C60, D_004A7520);
    if (w) {
        char* s;
        sprintf(buf, D_004C1C70, 0);
        s = nGlobalization_GetString_charP(buf);
        if (s) GuiTextWidget_SetText(w, s, 0);
        else GuiTextWidget_SetText(w, D_004C1A38, 0);
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_00456BF0 */

/* merge_units: begin func_00456D90 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Address lies before GuiSubTitleDisplay.cc (starts 0x00457AA0); gui widget code.
 */

#include "loose05_types.h"

/* vtable */
extern void GuiObjectives_onAdvanceTime();
extern void GuiWidget_FindPrevFocus();
extern void GuiWidget_FindNextFocus();
extern void GuiWidget_FindLastFocus();
extern void GuiWidget_onAction();
extern void GuiWidget_onLoseFocus();
extern void GuiWidget_onGainFocus();
extern void GuiWidget_onRender();
extern void GuiWidget_onDeactivate();
extern void GuiWidget_onActivate();
extern void GuiWidget_onRemove();
extern void GuiWidget_Load();
extern void GuiStartMenu_onInput();
extern void GuiStartMenu_onMessage();
extern void GuiStartMenu_onSleep();
extern void GuiStartMenu_FindFirstFocus();
extern void GuiStartMenu_onWake();
extern void GuiStartMenu_onAdd();
extern void GuiStartMenu_dtor();
extern void GuiStartMenu_GetClassName();
extern void GuiStartMenu_IsClass();
void * const D_004E1430[24] = { (void*)0x0, (void*)0x0, (void*)GuiStartMenu_dtor, (void*)GuiStartMenu_onAdd, (void*)GuiWidget_onRemove, (void*)GuiWidget_onActivate, (void*)GuiWidget_onDeactivate, (void*)GuiStartMenu_onWake, (void*)GuiStartMenu_onSleep, (void*)GuiWidget_onGainFocus, (void*)GuiWidget_onLoseFocus, (void*)GuiStartMenu_onInput, (void*)GuiWidget_onRender, (void*)GuiWidget_onAction, (void*)GuiObjectives_onAdvanceTime, (void*)GuiStartMenu_onMessage, (void*)GuiWidget_Load, (void*)GuiStartMenu_FindFirstFocus, (void*)GuiWidget_FindLastFocus, (void*)GuiWidget_FindNextFocus, (void*)GuiWidget_FindPrevFocus, (void*)GuiStartMenu_GetClassName, (void*)GuiStartMenu_IsClass, (void*)0x0 };
extern int GuiObjectives_ctor(void* self, int a1, int a2);

/* Constructor: base built by GuiObjectives_ctor, fields cleared, flag bit 5 cleared. */
GuiWidget456D90* GuiStartMenu_ctor(GuiWidget456D90* self) {
    GuiObjectives_ctor(self, 1, 1);
    self->vtable = ((char*)D_004E1430);
    self->unk90 = 0;
    self->unk94 = 0;
    self->unk98 = 0;
    self->unk9C = 0;
    self->unkA0 = 0;
    self->unkA4 = 0;
    self->unkA8 = 0;
    self->flags &= ~0x20;
    return self;
}
#pragma pop /* merge_units */
/* merge_units: end func_00456D90 */

/* merge_units: begin func_00456E00 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vtable_base_dtor.h"

/* Derived destructor: restore vtable, run base destructor, optionally delete. */
DEFINE_VTABLE_BASE_DTOR(GuiObjectives_dtor_2, D_004DF5C0, GuiWidget_dtor)
#pragma pop /* merge_units */
/* merge_units: end func_00456E00 */

/* merge_units: begin func_00456E60 */
#pragma push /* merge_units */
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
int cSystemContainer_GetSystem(int *, int *);                       
int SoundMgr_SetGroupsPaused(int, int);                            
int cInfoBar_SetVisible(int, int);                            
int GuiWidget_onSleep(int);                               
extern int D_004F2CC0;
extern int g_Game;
extern int g_Hud;
extern unsigned char g_IsMultiplayer;

void GuiStartMenuBackdrop_OnSleep(int arg0) {
    if (g_IsMultiplayer == 0) {
        SoundMgr_SetGroupsPaused(cSystemContainer_GetSystem(&g_Game, &D_004F2CC0), 0);
    }
    cInfoBar_SetVisible(g_Hud + 0x100, 1);
    GuiWidget_onSleep(arg0);
}
#pragma pop /* merge_units */
/* merge_units: end func_00456E60 */

/* merge_units: begin func_00456ED0 */
#pragma push /* merge_units */
                            
int GuiWidget_onWake(int);

void GuiStartMenuBackdrop_OnWake(int arg0) {
    if (g_IsMultiplayer == 0) {
        SoundMgr_SetGroupsPaused(cSystemContainer_GetSystem(&g_Game, &D_004F2CC0), 1);
    }
    cInfoBar_SetVisible(g_Hud + 0x100, 0);
    GuiWidget_onWake(arg0);
}
#pragma pop /* merge_units */
/* merge_units: end func_00456ED0 */

/* merge_units: begin func_00456F40 */
#pragma push /* merge_units */
extern int GuiWidget_onMessage(GuiWidget456D90* self, void* sender, int message);

/* Consume message 16 for values 2 and 3; defer other messages to the base. */
int GuiStartMenuBackdrop_OnEvent(GuiWidget456D90* self, void* sender, int message, int value) {
    if ((message & 0xFFFF) == 16 && (value == 2 || value == 3)) {
        return 1;
    }
    return GuiWidget_onMessage(self, sender, message);
}
#pragma pop /* merge_units */
/* merge_units: end func_00456F40 */
