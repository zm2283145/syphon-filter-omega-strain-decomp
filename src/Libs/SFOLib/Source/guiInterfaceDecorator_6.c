/*
 * main/guiManager: 2 files, 00417AE0-00417BC0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00417AE0 */
#pragma push /* merge_units */
#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
/*fc*/
int String_Dtor();                         
int cInterfaceManager_RemoveInterface();                          
int GuiDecorator_dtor();                         
int std_vector_deleter_GuiAnimationTrack_dtor();                         
int operator_delete();                          
extern void GuiInterfaceDecorator_onActivate();
extern void GuiInterfaceDecorator_onDeactivate();
extern void GuiInterfaceDecorator_onGainFocus();
extern void GuiInterfaceDecorator_onLoseFocus();
extern void GuiInterfaceDecorator_onSleep();
extern void GuiInterfaceDecorator_onWake();
extern void GuiInterfaceDecorator_Load();
extern void GuiInterfaceDecorator_onRender();
extern void GuiInterfaceDecorator_onMessage();
extern void GuiInterfaceDecorator_onAdvanceTime();
extern void GuiInterfaceDecorator_onRemove();
extern void GuiInterfaceDecorator_onAdd();
extern void GuiDecorator_onInput();
extern void GuiDecorator_onAction();
extern void * const D_004E09F0[];
extern char D_00571DC0;

char * GuiInterfaceDecorator_dtor(char * arg0, long long arg1) {
    int temp_a1;
    char * temp_a0;
    char * temp_a0_2;
    char * temp_a0_3;

    if (arg0 != NULL) {
        F_(arg0, 0x0, int) = (int)(&(*(char*)D_004E09F0));
        temp_a1 = F_(arg0, 0x20, int);
        if (temp_a1 != -1) {
            cInterfaceManager_RemoveInterface(&D_00571DC0, temp_a1);
        }
        temp_a0 = arg0 + 0x70;
        if ((temp_a0 != NULL) && (temp_a0 != NULL) && (temp_a0 != NULL)) {
            std_vector_deleter_GuiAnimationTrack_dtor(temp_a0, 0);
        }
        temp_a0_2 = arg0 + 0x14;
        if (temp_a0_2 != NULL) {
            String_Dtor(temp_a0_2, 0);
        }
        temp_a0_3 = arg0 + 8;
        if (temp_a0_3 != NULL) {
            String_Dtor(temp_a0_3, 0);
        }
        GuiDecorator_dtor(arg0, 0);
        if (((long long) (arg1 << 0x30) >> 0x30) > 0) {
            operator_delete(arg0);
        }
    }
    return arg0;
}
void * const D_004E09F0[20] = { (void*)0x0, (void*)0x0, (void*)GuiInterfaceDecorator_dtor, (void*)GuiInterfaceDecorator_onAdd, (void*)GuiInterfaceDecorator_onRemove, (void*)GuiInterfaceDecorator_onActivate, (void*)GuiInterfaceDecorator_onDeactivate, (void*)GuiInterfaceDecorator_onWake, (void*)GuiInterfaceDecorator_onSleep, (void*)GuiInterfaceDecorator_onGainFocus, (void*)GuiInterfaceDecorator_onLoseFocus, (void*)GuiDecorator_onInput, (void*)GuiInterfaceDecorator_onRender, (void*)GuiDecorator_onAction, (void*)GuiInterfaceDecorator_onAdvanceTime, (void*)GuiInterfaceDecorator_onMessage, (void*)GuiInterfaceDecorator_Load, (void*)0x0, (void*)0x0, (void*)0x0 };
#pragma pop /* merge_units */
/* merge_units: end func_00417AE0 */

/* merge_units: begin func_00417BC0 */
#pragma push /* merge_units */
typedef struct { char pad[0xC]; unsigned char enabled; char pad2[3]; } SubState;
typedef struct {
    void* vtable;
    int unk4;
    int a, b, c, d, e, f;   /* 0x08..0x1C */
    int index;              /* 0x20 */
    int count;              /* 0x24 */
    unsigned char busy;     /* 0x28 */
    char pad29[0x47];
    SubState sub;           /* 0x70 */
    int last;               /* 0x80 */
} Widget;
#if 0 /* merge_units */
extern char D_004E09F0[];
#endif /* merge_units */
#define D_004E09F0 ((char*)&D_004E09F0) /* merge_units */

extern void GuiDecorator_ctor(Widget* w);
extern void std_vector_GuiAnimationTrack_ctor(SubState* s);
/* Constructor. */
Widget* GuiInterfaceDecorator_ctor(Widget* w)
{
    SubState* sub;
    GuiDecorator_ctor(w);
    sub = &w->sub;
    w->vtable = D_004E09F0;
    w->a = 0;
    w->b = 0;
    w->c = 0;
    w->d = 0;
    w->e = 0;
    w->f = 0;
    std_vector_GuiAnimationTrack_ctor(sub);
    sub->enabled = 1;
    w->count = 0;
    w->index = -1;
    w->busy = 0;
    w->last = 0;
    return w;
}
#undef D_004E09F0 /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00417BC0 */
