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
void func_002A89A0(LIt_414F00* out, List_414F00* list);
void func_0028C0A0(LIt_414F00* out, List_414F00* list);
void func_0028C090(LIt_414F00* out, LIt_414F00* in);
void func_00415160(LIt_414F00* out, LIt_414F00* in);
LIt_414F00* func_0015AF40(LIt_414F00* out, LIt_414F00* in);
void List_InsertBefore(LIt_414F00* out, List_414F00* list, LIt_414F00* pos, W_414F00** v);
int GuiWidget_SendEvent(W_414F00* a, W_414F00* b, int msg, int c, int d);
void GuiWidget_ClearAwake(W_414F00* w);
void Pad_ResetHeldMask(void* p);
extern char D_0055A300[];
}

extern "C" void GuiCanvas_PushScreen(W_414F00* o, W_414F00* w, int pri)
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
    func_002A89A0(&beginTmp, &o->children);
    func_0028C090(&first, &beginTmp);
    it = first;
    func_0028C0A0(&endTmp, &o->children);
    func_0028C090(&last, &endTmp);
    while (it.node != last.node) {
        if (pri < it.Get()->pri) break;
        it.Next();
        func_0028C0A0(&endTmp, &o->children);
        func_0028C090(&last, &endTmp);
    }
    if ((w->flags & 2) && GuiWidget_SendEvent(o, w, 0x10, 2, 0) == 0)
        GuiWidget_SendEvent(w, o, 0x10, 2, 0);
    w->parent = o;
    w->pri = pri;
    pos.node = it.node;
    func_00415160(&pos2, &pos);
    List_InsertBefore(&res, &o->children, func_0015AF40(&pos3, &pos2), &w);
    GuiWidget_ClearAwake(w);
    w->comp->Show();
    GuiWidget_SendEvent(o, w, 0x18, 0, 0);
    if (o->children.size > 0 && o->children.first->value == w) {
        Pad_ResetHeldMask(D_0055A300);
        if (o->focus) o->focus->comp->Unfocus();
        o->focus = w->focus;
        if (o->focus == 0) o->focus = w->DefaultFocus();
        if (o->focus) o->focus->comp->Focus();
    }
}
