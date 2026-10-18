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
char* Loc_LookupText(char*);
void List_Begin(void*, void*);
void func_0028C090(void*, void*);
void func_0028C0A0(void*, void*);
void func_0028C0B0(void*, void*);
void GuiObjectives_Init(void*);
void GuiTextWidget_SetText(void*, char*, int);
int sprintf(char*, const char*, ...);
void GuiStartMenu_Init(O456* o);
}

void GuiStartMenu_Init(O456* o)
{
    LNode* end;
    LNode* it;
    int a;
    int t;
    char buf[16];
    GuiWidgetV* w;

    o->acc = (char*)GuiWidget_FindChildByName(o, D_00497960);
    if (o->acc) {
        int i = 0;
        LNode* n;
        List_Begin(&a, o->acc + 0x28);
        func_0028C0B0(&it, &a);
        n = it;
        while ((func_0028C0A0(&t, o->acc + 0x28), func_0028C090(&end, &t), n != end) && i < 7) {
            n->obj[4] = i;
            o->arr[i] = n->obj;
            i++;
            n = n->next;
        }
    }
    o->f8C = GuiWidget_FindChildByName(o, D_00497978);
    GuiObjectives_Init(o);
    o->fB0 = 0;
    w = GuiFindAs(o, D_004C1C60, D_004A7520);
    if (w) {
        char* s;
        sprintf(buf, D_004C1C70, 0);
        s = Loc_LookupText(buf);
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
extern void GuiObjectives_Update();
extern void GuiWidget_FocusPrev();
extern void GuiWidget_FocusNext();
extern void GuiWidget_FocusLast();
extern void GuiWidget_BubbleActivate();
extern void GuiWidget_BubbleType1();
extern void GuiWidget_BubbleType0();
extern void GuiWidget_Draw();
extern void GuiWidget_ClearFlag4();
extern void GuiWidget_SetFlag4();
extern void GuiWidget_Deinit();
extern void func_0041F210();
extern void GuiStartMenu_OnInput();
extern void GuiStartMenu_OnEvent();
extern void GuiStartMenu_OnSleep();
extern void GuiStartMenu_First();
extern void GuiStartMenu_OnWake();
extern void GuiStartMenu_Init();
extern void func_004573C0();
extern void GuiStartMenu_GetClassName();
extern void func_00457440();
void * const D_004E1430[24] = { (void*)0x0, (void*)0x0, (void*)func_004573C0, (void*)GuiStartMenu_Init, (void*)GuiWidget_Deinit, (void*)GuiWidget_SetFlag4, (void*)GuiWidget_ClearFlag4, (void*)GuiStartMenu_OnWake, (void*)GuiStartMenu_OnSleep, (void*)GuiWidget_BubbleType0, (void*)GuiWidget_BubbleType1, (void*)GuiStartMenu_OnInput, (void*)GuiWidget_Draw, (void*)GuiWidget_BubbleActivate, (void*)GuiObjectives_Update, (void*)GuiStartMenu_OnEvent, (void*)func_0041F210, (void*)GuiStartMenu_First, (void*)GuiWidget_FocusLast, (void*)GuiWidget_FocusNext, (void*)GuiWidget_FocusPrev, (void*)GuiStartMenu_GetClassName, (void*)func_00457440, (void*)0x0 };
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
DEFINE_VTABLE_BASE_DTOR(func_00456E00, D_004DF5C0, GuiWidget_Destroy)
#pragma pop /* merge_units */
/* merge_units: end func_00456E00 */

/* merge_units: begin func_00456E60 */
#pragma push /* merge_units */
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
int Service_Lookup(int *, int *);                       
int SoundMgr_SetGroupsPaused(int, int);                            
int HudTicker_SetShown(int, int);                            
int GuiWidget_BaseSleep(int);                               
extern int D_004F2CC0;
extern int D_004FFB50;
extern int D_004FFC2C;
extern unsigned char D_005721C8;

void GuiStartMenuBackdrop_OnSleep(int arg0) {
    if (D_005721C8 == 0) {
        SoundMgr_SetGroupsPaused(Service_Lookup(&D_004FFB50, &D_004F2CC0), 0);
    }
    HudTicker_SetShown(D_004FFC2C + 0x100, 1);
    GuiWidget_BaseSleep(arg0);
}
#pragma pop /* merge_units */
/* merge_units: end func_00456E60 */

/* merge_units: begin func_00456ED0 */
#pragma push /* merge_units */
                            
int GuiWidget_BaseWake(int);

void GuiStartMenuBackdrop_OnWake(int arg0) {
    if (D_005721C8 == 0) {
        SoundMgr_SetGroupsPaused(Service_Lookup(&D_004FFB50, &D_004F2CC0), 1);
    }
    HudTicker_SetShown(D_004FFC2C + 0x100, 0);
    GuiWidget_BaseWake(arg0);
}
#pragma pop /* merge_units */
/* merge_units: end func_00456ED0 */

/* merge_units: begin func_00456F40 */
#pragma push /* merge_units */
extern int GuiWidget_OnEvent(GuiWidget456D90* self, void* sender, int message);

/* Consume message 16 for values 2 and 3; defer other messages to the base. */
int GuiStartMenuBackdrop_OnEvent(GuiWidget456D90* self, void* sender, int message, int value) {
    if ((message & 0xFFFF) == 16 && (value == 2 || value == 3)) {
        return 1;
    }
    return GuiWidget_OnEvent(self, sender, message);
}
#pragma pop /* merge_units */
/* merge_units: end func_00456F40 */
