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
void func_0013B180(void*, void*);
void func_0028C090(void*, void*);
void func_0028C0A0(void*, void*);
void func_0028C0B0(void*, void*);
void func_003688C0(void*);
void func_0041BEB0(void*, char*, int);
int sprintf(char*, const char*, ...);
void func_00456BF0(O456* o);
}

void func_00456BF0(O456* o)
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
        func_0013B180(&a, o->acc + 0x28);
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
    func_003688C0(o);
    o->fB0 = 0;
    w = GuiFindAs(o, D_004C1C60, D_004A7520);
    if (w) {
        char* s;
        sprintf(buf, D_004C1C70, 0);
        s = Loc_LookupText(buf);
        if (s) func_0041BEB0(w, s, 0);
        else func_0041BEB0(w, D_004C1A38, 0);
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
extern void func_00368620();
extern void func_0041D400();
extern void func_0041D5C0();
extern void func_0041D780();
extern void func_0041E230();
extern void func_0041E2B0();
extern void func_0041E330();
extern void func_0041E470();
extern void func_0041F070();
extern void func_0041F080();
extern void func_0041F090();
extern void func_0041F210();
extern void func_004566D0();
extern void func_00456830();
extern void func_00456A30();
extern void func_00456A60();
extern void func_00456AB0();
extern void func_00456BF0();
extern void func_004573C0();
extern void func_00457430();
extern void func_00457440();
void * const D_004E1430[24] = { (void*)0x0, (void*)0x0, (void*)func_004573C0, (void*)func_00456BF0, (void*)func_0041F090, (void*)func_0041F080, (void*)func_0041F070, (void*)func_00456AB0, (void*)func_00456A30, (void*)func_0041E330, (void*)func_0041E2B0, (void*)func_004566D0, (void*)func_0041E470, (void*)func_0041E230, (void*)func_00368620, (void*)func_00456830, (void*)func_0041F210, (void*)func_00456A60, (void*)func_0041D780, (void*)func_0041D5C0, (void*)func_0041D400, (void*)func_00457430, (void*)func_00457440, (void*)0x0 };
extern int GuiObjectives_ctor(void* self, int a1, int a2);

/* Constructor: base built by GuiObjectives_ctor, fields cleared, flag bit 5 cleared. */
GuiWidget456D90* func_00456D90(GuiWidget456D90* self) {
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
DEFINE_VTABLE_BASE_DTOR(func_00456E00, D_004DF5C0, func_0041F370)
#pragma pop /* merge_units */
/* merge_units: end func_00456E00 */

/* merge_units: begin func_00456E60 */
#pragma push /* merge_units */
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
int Service_Lookup(int *, int *);                       
int func_001C96D0(int, int);                            
int func_003F9E30(int, int);                            
int func_0041EBF0(int);                               
extern int D_004F2CC0;
extern int D_004FFB50;
extern int D_004FFC2C;
extern unsigned char D_005721C8;

void func_00456E60(int arg0) {
    if (D_005721C8 == 0) {
        func_001C96D0(Service_Lookup(&D_004FFB50, &D_004F2CC0), 0);
    }
    func_003F9E30(D_004FFC2C + 0x100, 1);
    func_0041EBF0(arg0);
}
#pragma pop /* merge_units */
/* merge_units: end func_00456E60 */

/* merge_units: begin func_00456ED0 */
#pragma push /* merge_units */
                            
int func_0041EFA0(int);

void func_00456ED0(int arg0) {
    if (D_005721C8 == 0) {
        func_001C96D0(Service_Lookup(&D_004FFB50, &D_004F2CC0), 1);
    }
    func_003F9E30(D_004FFC2C + 0x100, 0);
    func_0041EFA0(arg0);
}
#pragma pop /* merge_units */
/* merge_units: end func_00456ED0 */

/* merge_units: begin func_00456F40 */
#pragma push /* merge_units */
extern int func_0041EF10(GuiWidget456D90* self, void* sender, int message);

/* Consume message 16 for values 2 and 3; defer other messages to the base. */
int func_00456F40(GuiWidget456D90* self, void* sender, int message, int value) {
    if ((message & 0xFFFF) == 16 && (value == 2 || value == 3)) {
        return 1;
    }
    return func_0041EF10(self, sender, message);
}
#pragma pop /* merge_units */
/* merge_units: end func_00456F40 */
