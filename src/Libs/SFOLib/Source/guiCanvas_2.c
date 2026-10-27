/*
 * Libs/SFOLib/Source/guiCanvas: 1 file, 00414F00
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin GuiCanvas_414F00 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"

struct C_414F00 {
    VPAD4(p) VPAD1(q)
    virtual void Show();
    virtual void s6();
    virtual void Focus();
    virtual void Unfocus();
};
struct W_414F00;
struct LNode_414F00 { LNode_414F00* prev; LNode_414F00* next; W_414F00* value; };
union LIt_414F00 {
    LNode_414F00* node;
    W_414F00* Get() const { return node->value; }
    void Next() { node = node->next; }
    bool operator!=(const LIt_414F00& o) const { return node != o.node; }
};
struct List_414F00 { int size; LNode_414F00* first; LNode_414F00* head; };
struct W_414F00 {
    VPAD8(p) VPAD4(q) VPAD2(r) VPAD1(s)
    virtual W_414F00* DefaultFocus();
    char pad4[0x10];
    unsigned short flags;
    short pri;
    char pad18[4];
    W_414F00* parent;
    W_414F00* focus;
    char pad24[4];
    List_414F00 children;
    char pad34[0x10];
    C_414F00* comp;
};
extern "C" {
void std_list_GuiWidgetPtr_begin(LIt_414F00* out, List_414F00* list);
void std_list_GuiWidgetPtr_end(LIt_414F00* out, List_414F00* list);
void cLListIterator_GuiWidgetPtr_ctor_listR(LIt_414F00* out, LIt_414F00* in);
void std_list_GuiWidgetPtr_generic_iterator_opCast(LIt_414F00* out, LIt_414F00* in);
LIt_414F00* std_list_deleter_voidPtr_generic_iterator_ctor_listdeleterR(LIt_414F00* out, LIt_414F00* in);
void std_list_deleter_voidPtr_insert(LIt_414F00* out, List_414F00* list, LIt_414F00* pos, W_414F00** v);
int GuiWidget_SendMessage(W_414F00* a, W_414F00* b, int msg, int c, int d);
void GuiWidget_ClearSleepStatus(W_414F00* w);
void cJoystick_Debounce(void* p);
extern char D_0055A300[];
}

extern "C" void GuiCanvas_PushGui(W_414F00* o, W_414F00* w, int pri)
{
    LIt_414F00 it;
    LIt_414F00 first;
    LIt_414F00 last;
    LIt_414F00 pos;
    LIt_414F00 res;
    LIt_414F00 pos2;
    LIt_414F00 beginTmp;
    LIt_414F00 endTmp;
    LIt_414F00 pos3;

    if (w == 0 || (w->flags & 8)) return;
    std_list_GuiWidgetPtr_begin(&beginTmp, &o->children);
    cLListIterator_GuiWidgetPtr_ctor_listR(&first, &beginTmp);
    it = first;
    std_list_GuiWidgetPtr_end(&endTmp, &o->children);
    cLListIterator_GuiWidgetPtr_ctor_listR(&last, &endTmp);
    while (it.node != last.node) {
        if (pri < it.Get()->pri) break;
        it.Next();
        std_list_GuiWidgetPtr_end(&endTmp, &o->children);
        cLListIterator_GuiWidgetPtr_ctor_listR(&last, &endTmp);
    }
    if ((w->flags & 2) && GuiWidget_SendMessage(o, w, 0x10, 2, 0) == 0)
        GuiWidget_SendMessage(w, o, 0x10, 2, 0);
    w->parent = o;
    w->pri = pri;
    pos.node = it.node;
    std_list_GuiWidgetPtr_generic_iterator_opCast(&pos2, &pos);
    std_list_deleter_voidPtr_insert(&res, &o->children, std_list_deleter_voidPtr_generic_iterator_ctor_listdeleterR(&pos3, &pos2), &w);
    GuiWidget_ClearSleepStatus(w);
    w->comp->Show();
    GuiWidget_SendMessage(o, w, 0x18, 0, 0);
    if (o->children.size > 0 && o->children.first->value == w) {
        cJoystick_Debounce(D_0055A300);
        if (o->focus) o->focus->comp->Unfocus();
        o->focus = w->focus;
        if (o->focus == 0) o->focus = w->DefaultFocus();
        if (o->focus) o->focus->comp->Focus();
    }
}
static inline void merge_flush_GuiCanvas_414F00(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end GuiCanvas_414F00 */
