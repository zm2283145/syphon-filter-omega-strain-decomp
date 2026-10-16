#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"

struct Ev_415170 { unsigned short type; unsigned short dev; unsigned short b; unsigned short action; unsigned short key; };
struct C_415170 {
    VPAD4(p) VPAD2(q) VPAD1(r)
    virtual void Focus();
    virtual void Unfocus();
};
struct W_415170;
struct R_415170 {
    VPAD16(p) VPAD1(q)
    virtual W_415170* Prev(W_415170* cur, int wrap);
    virtual W_415170* Next(W_415170* cur, int wrap);
};
struct H_415170 { char pad[8]; R_415170* root; };
struct W_415170 {
    void* vt;
    char pad[0x18];
    W_415170* parent;
    W_415170* focus;
    int f24;
    int on;
    H_415170* h;
    char pad30[0x14];
    C_415170* comp;
};
extern "C" void GuiWidget_SendEventUp(W_415170* w, int msg, int a, int b);

static inline bool IsPress_415170(Ev_415170* e) { return e->type == 1 && e->dev == 0 && e->action == 0; }

extern "C" int GuiCanvas_Navigate(W_415170* o, Ev_415170* ev)
{
    if (IsPress_415170(ev)) {
        unsigned short k = ev->key;
        if (k == 0x1000 || k == 0x4000) {
            W_415170* n;
            if (o->on == 0 || o->focus == 0) return 0;
            if (k == 0x1000) n = o->h->root->Next(o->focus, 1);
            else n = o->h->root->Prev(o->focus, 1);
            if (n && n != o->focus) GuiWidget_SendEventUp(n, 0x10, 0, 0);
            if (n != o->focus) {
                if (o->focus) o->focus->comp->Unfocus();
                o->focus = n;
                if (o->focus) {
                    o->focus->comp->Focus();
                    if (n == o->focus && n) {
                        do {
                            if (n == o) break;
                            n->focus = o->focus;
                            n = n->parent;
                        } while (n);
                    }
                }
            }
            return 1;
        }
    }
    return 0;
}

