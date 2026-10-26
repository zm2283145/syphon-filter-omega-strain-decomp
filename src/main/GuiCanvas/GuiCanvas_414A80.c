/*
 * main/GuiCanvas: 4 files, 00414A80-00414BE0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00414A80 */
#pragma push /* merge_units */
#include "types.h"

typedef struct { char pad[0x48]; int id; char pad2[4]; unsigned char pressed; } Widget414;

extern int GuiWidget_OnEvent(Widget414* self, int id, unsigned short event);

/* Marks the widget pressed on event 3 for its own id (returns 1); otherwise returns the base handler's result. */
int GuiCanvas_FinishDeferredPop(Widget414* self, int id, unsigned short event)
{
    if (event == 3 && id == self->id) {
        self->pressed = 1;
        return 1;
    }
    return GuiWidget_OnEvent(self, id, event);
}
#pragma pop /* merge_units */
/* merge_units: end func_00414A80 */

/* merge_units: begin func_00414AC0 */
#pragma push /* merge_units */
#pragma cplusplus on
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#define VC_(p) ((int (*)())(p))
#pragma mpwc_relax on

struct VC00414AC0 { virtual int v0(); virtual int v1(); virtual int v2(); virtual int v3(); virtual int v4(); virtual int v5(); virtual int v6(); virtual int v7(); virtual int v8(); virtual int v9(); virtual int v10(); virtual int v11(); virtual int v12(); virtual int v13(); virtual int v14(); virtual int v15(); virtual int v16(); virtual int v17(); virtual int v18(); virtual int v19(); virtual int v20(); virtual int v21(); virtual int v22(); virtual int v23(...); virtual int v24(...); };
extern "C" {

}
extern "C" void GuiStack_SwapScreens(void **arg0, int arg1, int arg2) {
    if (arg1 != 0) {
        ((VC00414AC0 *)(arg0))->v24();
    }
    if (arg2 != 0) {
        ((VC00414AC0 *)(arg0))->v23(arg2, 0);
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_00414AC0 */

/* merge_units: begin func_00414B30 */
#pragma push /* merge_units */
#pragma cplusplus on

struct VC00414B30 { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); };

struct Node414B30 {
    char pad0[0x1C];
    Node414B30* next;     /* 0x1C */
    Node414B30* focus;    /* 0x20 */
    char pad24[0x20];
    VC00414B30* obj;      /* 0x44 */
};

extern "C" void GuiScreen_SetFocus(Node414B30* self, Node414B30* w) {
    if (w != self->focus) {
        if (self->focus) {
            self->focus->obj->v8();
        }
        self->focus = w;
        if (self->focus) {
            self->focus->obj->v7();
            if (w == self->focus) {
                for (; w; w = w->next) {
                    if (w == self) break;
                    w->focus = self->focus;
                }
            }
        }
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_00414B30 */

/* merge_units: begin func_00414BE0 */
#pragma push /* merge_units */
#pragma cplusplus on
struct R_414BE0 { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); };
struct W_414BE0 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual W_414BE0* v15();
    char pad4[0x10]; unsigned short flags; char pad16[6]; int f1C; W_414BE0* f20; char pad24[0x20]; R_414BE0* f44;
};
struct N_414BE0 { int prev; int next; W_414BE0* obj; };
struct O_414BE0 { char pad[0x20]; W_414BE0* f20; char pad24[4]; int f28; N_414BE0* f2C; char pad30[0x24]; char l54[0xC]; unsigned char b60; };
extern "C" {
extern char D_0055A300[];
int List_Erase(...);
int std_list_deleter_voidPtr_generic_iterator_ctor_listdeleterR(...);
int opNe_cLListIteratorR_cLListIteratorR_6(...);
int cLList_GuiWidgetPtr_End(...);
int cLListIterator_GuiWidgetPtr_ctor_cLListIteratorR(...);
int cLListIterator_GuiWidgetPtr_opInc(...);
int* cLListIterator_GuiWidgetPtr_opMul(...);
int cLListIterator_GuiWidgetPtr_opAssign(...);
int cLList_GuiWidgetPtr_Begin(...);
int cLListIterator_GuiWidgetPtr_ctor_void(...);
int std_list_GuiWidgetPtr_end(...);
int cLListIterator_GuiWidgetPtr_ctor_listR(...);
void Pad_ResetHeldMask(void* p);
void GuiWidget_SendEvent(void* a, void* b, int kind, int v, int f);
void GuiCanvas_PopScreen(O_414BE0* o, W_414BE0* w);
}

void GuiCanvas_PopScreen(O_414BE0* o, W_414BE0* w)
{
    char* r1;
    char* r2;
    int e3a;
    int e3b;
    char* t1;
    char* t2;
    int y1;
    int x1;
    int y2;
    int x2;
    int it1;
    int tmp1;
    int end1;
    int e2a;
    int it2;
    int tmp2;
    int end2;
    int e2b;
    N_414BE0** hp;
    W_414BE0* c;
    if (w == 0) return;
    if (o->b60) {
        cLListIterator_GuiWidgetPtr_ctor_void(&it1);
        cLList_GuiWidgetPtr_Begin(&tmp1, o->l54);
        cLListIterator_GuiWidgetPtr_opAssign(&it1, &tmp1);
        cLList_GuiWidgetPtr_End(&end1, o->l54);
        if (opNe_cLListIteratorR_cLListIteratorR_6(&it1, &end1) != 0) {
loop_1:
            if ((void*)*cLListIterator_GuiWidgetPtr_opMul(&it1) != (void*)w) {
                cLListIterator_GuiWidgetPtr_opInc(&it1);
                cLList_GuiWidgetPtr_End(&end1, o->l54);
                if (opNe_cLListIteratorR_cLListIteratorR_6(&it1, &end1) != 0) goto loop_1;
            }
        }
        cLListIterator_GuiWidgetPtr_ctor_cLListIteratorR(&r1, &it1);
        std_list_GuiWidgetPtr_end(&e2a, o->l54);
        cLListIterator_GuiWidgetPtr_ctor_listR(&e3a, &e2a);
        if ((int)r1 != e3a) {
            t1 = r1;
            std_list_deleter_voidPtr_generic_iterator_ctor_listdeleterR(&x1, &t1);
            List_Erase(&y1, o->l54, &x1);
        }
    }
    cLListIterator_GuiWidgetPtr_ctor_void(&it2);
    cLList_GuiWidgetPtr_Begin(&tmp2, &o->f28);
    cLListIterator_GuiWidgetPtr_opAssign(&it2, &tmp2);
    cLList_GuiWidgetPtr_End(&end2, &o->f28);
    if (opNe_cLListIteratorR_cLListIteratorR_6(&it2, &end2) != 0) {
loop_2:
        if ((void*)*cLListIterator_GuiWidgetPtr_opMul(&it2) != (void*)w) {
            cLListIterator_GuiWidgetPtr_opInc(&it2);
            cLList_GuiWidgetPtr_End(&end2, &o->f28);
            if (opNe_cLListIteratorR_cLListIteratorR_6(&it2, &end2) != 0) goto loop_2;
        }
    }
    cLListIterator_GuiWidgetPtr_ctor_cLListIteratorR(&r2, &it2);
    std_list_GuiWidgetPtr_end(&e2b, &o->f28);
    cLListIterator_GuiWidgetPtr_ctor_listR(&e3b, &e2b);
    if ((int)r2 == e3b) return;
    w->f1C = 0;
    hp = &o->f2C;
    if (o->f2C->obj == w) Pad_ResetHeldMask(D_0055A300);
    c = ((N_414BE0*)r2)->obj;
    if (c) {
        if (c->flags & 8) c->f44->v6();
        t2 = r2;
        std_list_deleter_voidPtr_generic_iterator_ctor_listdeleterR(&x2, &t2);
        List_Erase(&y2, &o->f28, &x2);
    }
    GuiWidget_SendEvent(o, w, 0x19, 0, 0);
    if (o->f20 && w->f20 == o->f20) o->f20->f44->v8();
    w->f20 = 0;
    if (o->f28) {
        o->f20 = (*hp)->obj->f20;
        if (!o->f20) o->f20 = (*hp)->obj->v15();
    } else {
        o->f20 = 0;
    }
    if (o->f20) o->f20->f44->v7();
}
#pragma pop /* merge_units */
/* merge_units: end func_00414BE0 */
