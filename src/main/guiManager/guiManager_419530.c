/*
 * main/guiManager: 2 files, 00419530-00419590
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00419530 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#define VC_(p) ((int (*)())(p))
#pragma mpwc_relax on


struct VC00419530 { virtual int v0(); virtual int v1(...); };
extern "C" {
int func_002CCE50(...);                      
}
extern "C" void GuiManager_AddWidget(int arg0, char * arg1) {
    void **temp_a0;

    if (!(F_(arg1, 0x14, unsigned short) & 1)) {
        func_002CCE50(arg0 + 0x14, &arg1);
        temp_a0 = (void **)(F_(arg1, 0x44, int));
        ((VC00419530 *)(temp_a0))->v1();
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_00419530 */

/* merge_units: begin func_00419590 */
#pragma push /* merge_units */
typedef struct { char p[8]; void* item; } Node419590;
typedef struct { int size; int pad; Node419590* first; } List419590;
typedef struct { char p[0x14]; List419590 a; List419590 b; char s[0x10]; } Obj419590;
extern void func_00418E00(Obj419590* o, void* item, int f);
extern void String_Dtor(void* p, int f);
extern void func_002CCD80(void* p, int f);
extern void func_00419660(Obj419590* p, int f);
extern void operator_delete(void* p);
Obj419590* func_00419590(Obj419590* self, short del)
{
    if (self) {
        while (self->a.size) func_00418E00(self, self->a.first->item, 1);
        if (self->s) String_Dtor(self->s, 0);
        if (&self->b) func_002CCD80(&self->b, 0);
        if (&self->a) func_002CCD80(&self->a, 0);
        if (self) func_00419660(self, -1);
        if (del > 0) operator_delete(self);
    }
    return self;
}
#pragma pop /* merge_units */
/* merge_units: end func_00419590 */
