#pragma cplusplus on
#include "types.h"
struct Ent171260 {
    char pad0[0x2C];
    unsigned char f2C;
    unsigned char f2D;
    unsigned char f2E;
    char pad2F[0x90 - 0x2F];
    int type;
    char pad94[8];
    int prio;
    bool Usable() { return f2D && f2C && !f2E; }
};
struct N171260 { int m0; N171260* next; Ent171260* data; };
struct Own171260 { char pad[0x320C]; int state; };
struct Hb171260 { char pad[0x20]; Own171260* owner; float f24; char list[4]; };
extern "C" {
void func_0013B180(int* out, void* list);
void func_00170CE0(N171260** out, int* in);
void func_00170D20(int* out, void* list);
void func_00170D10(N171260** out, int* in);
}

extern "C" Ent171260* Hotbox_SelectInteraction(Hb171260* h, int mode)
{
    Ent171260* best = 0;
    if (h->f24 <= 0.0f) {
        N171260* e1;
        N171260* e2;
        N171260* it;
        int t0;
        int t1;
        int t2;
        int bp;
        N171260* n;
        func_0013B180(&t0, h->list);
        func_00170CE0(&it, &t0);
        n = it;
        bp = -1;
        if (mode) {
            while (func_00170D20(&t1, h->list), func_00170D10(&e1, &t1), n != e1) {
                Ent171260* o = n->data;
                n = n->next;
                if (o->Usable() && o->type == 0x12 && bp < o->prio) {
                    bp = o->prio;
                    best = o;
                }
            }
        } else {
            while (func_00170D20(&t2, h->list), func_00170D10(&e2, &t2), n != e2) {
                Ent171260* o = n->data;
                n = n->next;
                if (o->Usable() && o->type == 0xC) {
                    int s = h->owner->state;
                    if (!(s != 8 && s != 7 && s != 0xA))
                        return 0;
                }
                if (o->Usable()) {
                    int ty = o->type;
                    if ((ty == 8 || ty == 0x12 || ty == 0xC) && bp < o->prio) {
                        bp = o->prio;
                        best = o;
                    }
                }
            }
        }
    }
    return best;
}


