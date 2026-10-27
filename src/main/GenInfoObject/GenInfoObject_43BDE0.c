/*
 * main/GenInfoObject: 3 files, 0043BDE0-0043BEF0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0043BDE0 */
#pragma push /* merge_units */
#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#define VC_(p) ((int (*)())(p))
#pragma mpwc_relax on
int GuiWidget_SendChildrenMessage(char * , int, int, int);                 
int GuiWidget_onWake();                                  

void GuiScrollBarWidget_onWake(char * arg0) {
    float r;
    int temp_t1;
    int temp_t0;

    GuiWidget_onWake();
    if (F_(arg0, 0x48, unsigned char) != 0) {
        temp_t1 = F_(arg0, 0x5C, int);
        temp_t0 = F_(arg0, 0x4C, int);
        r = (float) (F_(arg0, 0x58, int) - temp_t1) / (float) (F_(arg0, 0x60, int) - temp_t1);
        GuiWidget_SendChildrenMessage(arg0, 0xA, temp_t0 + (int) (r * (float) (F_(arg0, 0x50, int) - temp_t0)), 0);
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_0043BDE0 */

/* merge_units: begin func_0043BE70 */
#pragma push /* merge_units */
typedef struct { char p[0x10]; int f10; int f14; } D43BE70;
typedef struct { char p[0x48]; unsigned char b48; char p49[3]; int f4C; int f50; } W43BE70;
extern void GuiWidget_onAdd(W43BE70* w);
extern int GuiWidget_SendMessage(W43BE70* w, W43BE70* src, int kind, int a, int out);
extern char D_004BFFA8[];
static int D_004976A0 = (int)D_004BFFA8;
void GuiScrollBarWidget_onAdd(W43BE70* w)
{
    D43BE70* d[1];
    GuiWidget_onAdd(w);
    d[0] = 0;
    if (GuiWidget_SendMessage(w, w, 4, D_004976A0, (int)d) && d[0]) {
        w->b48 = 1;
        w->f4C = d[0]->f10;
        w->f50 = d[0]->f14;
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_0043BE70 */

/* merge_units: begin func_0043BEF0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Address lies after GenInfoObject.cc (ends 0x0043BA00); gui widget code.
 */

#include "loose05_types.h"

extern char D_004E0F40[]; /* vtable */
extern void GuiWidget_ctor(void* self);

/* Constructor: base widget plus zeroed fields. */
GuiWidget43BEF0* GuiScrollBarWidget_ctor(GuiWidget43BEF0* self) {
    GuiWidget_ctor(self);
    self->base.vtable = D_004E0F40;
    self->unk54 = 0;
    self->unk58 = 0;
    self->unk5C = 0;
    self->unk60 = 10;
    self->unk48 = 0;
    self->unk4C = 0;
    self->unk50 = 0;
    return self;
}
#pragma pop /* merge_units */
/* merge_units: end func_0043BEF0 */
