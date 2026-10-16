#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"
struct N_415310 {
    VPAD8(p) VPAD1(q)
    virtual unsigned char Handle(void* arg);
    char pad[0x18];
    N_415310* next;
    N_415310* child;
};
struct H_415310 { char pad[8]; N_415310* root; };
struct O_415310 {
    VPAD8(p) VPAD1(q)
    virtual unsigned char Handle(void* arg);
    char pad[0x24];
    int on;
    H_415310* h;
};
#pragma bool off
static inline int IsZero_415310(void* c) { return ((int)c != 0) ^ 1; }
#pragma opt_rotateloops off
extern "C" void GuiCanvas_DispatchInput(O_415310* o, void* arg)
{
    unsigned char r = 0;
    if (o->on) {
        N_415310* p = o->h->root;
        N_415310* n = p->child ? p->child : p;
        r = n->Handle(arg);
        if (!r) {
            for (n = n->next; !IsZero_415310(n) && !r; n = n->next)
                r = n->Handle(arg);
        }
    }
    if (!r) o->Handle(arg);
}
#pragma opt_rotateloops reset
#pragma bool reset