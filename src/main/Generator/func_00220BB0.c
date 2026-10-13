#pragma cplusplus on
#pragma opt_propagation off
#include "types.h"
#define V5(a) virtual void a##0(); virtual void a##1(); virtual void a##2(); virtual void a##3(); virtual void a##4();
struct Tgt {
    V5(a) V5(b) V5(c) V5(d) virtual void e0(); virtual void e1();
    virtual void Deactivate(int);
    int pad4[2]; int id;
};
struct Hnd { Tgt* p; int id; };
struct LNode { LNode* prev; LNode* next; Hnd h; };
struct Gen;
struct Ev {
    char* vt; char p4[0x1C]; signed char f20; char p21[3]; Tgt* f24;
};
extern "C" {
LNode* func_0021E000(void* l);
LNode** func_0021DFE0(LNode** it, LNode* n);
LNode** func_0021DFF0(LNode** it, LNode* n);
int Event_Construct(void*, char*);
int Event_Send(void*, void*, int);
int cMessage_dtor(void*, int);
void Object_Deactivate(Gen*, int);
extern char D_004A4A88[];
extern char D_004DB620[];
extern char D_004DB660[];
}
struct Gen {
    char pad[0x90]; int list90;
};
static inline Tgt* HGet(Hnd* h) {
    unsigned char valid = 1;
    Tgt* p = h->p;
    int n = (p != 0) ^ 1;
    if (!n && p->id != h->id)
        valid = 0;
    return valid ? p : 0;
}
extern "C" void Generator_DeactivateSpawned(Gen* self)
{
    Tgt* t;
    LNode* it;
    LNode* end;
    LNode* n;
    func_0021DFF0(&it, func_0021E000(&self->list90)->next);
    for (n = it; func_0021DFE0(&end, func_0021E000(&self->list90)), n != end; n = n->next) {
        Hnd* h = &n->h;
        t = HGet(h);
        t->Deactivate(1);
        Ev ev;
        Event_Construct(&ev, D_004A4A88);
        ev.f24 = t;
        ev.vt = D_004DB620;
        ev.f20 = 2;
        Event_Send(&ev, self, 0);
        ev.vt = D_004DB660;
        cMessage_dtor(&ev, 0);
    }
    Object_Deactivate(self, 1);
}




