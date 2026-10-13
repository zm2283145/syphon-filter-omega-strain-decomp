#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"
struct Ctl_26D810 { VPAD16(a) VPAD2(b) VPAD1(c) virtual unsigned char IsPlayer(); };
struct M_26D810 { int id; };
struct Hum_26D810 { char pad[0xC]; unsigned int flags; char pad10[0x48]; Ctl_26D810* ctl; };
struct Node_26D810 { int f0; Node_26D810* next; M_26D810* id; };
struct Holder_26D810 { char pad[0x30]; Hum_26D810* x30; };
struct Self_26D810 { int* x0; };
extern "C" {
extern int D_004FFC2C;
extern Holder_26D810* D_004FFC0C;
Hum_26D810* Object_LookupById(M_26D810* id);
void func_0016E880(int* out, int* list);
void func_0026C390(Node_26D810** out, int b);
void func_0026C320(int* out, int* list);
void func_0026C350(Node_26D810** out, int* e);
void func_00242B40(int a, M_26D810* m, int n, int b, int c);
void func_0026D810(Self_26D810* self);
}
static inline Node_26D810* Begin_26D810(int* list) { Node_26D810* n; int b; func_0016E880(&b, list); func_0026C390(&n, b); return n; }
static inline void End_26D810(Node_26D810** out, int* list) { int e; func_0026C320(&e, list); func_0026C350(out, &e); }

void func_0026D810(Self_26D810* self)
{
    int* list = self->x0 + 3;
    unsigned char r;
    Hum_26D810* h;
    Node_26D810* end;
    Node_26D810* it;
    for (it = Begin_26D810(list); End_26D810(&end, list), it != end; it = it->next) {
        h = Object_LookupById(it->id);
        if (h) {
            r = 0;
            if (h->ctl && h->ctl->IsPlayer()) r = 1;
            if (r) func_00242B40(D_004FFC2C, it->id, 4, 1, 0);
        }
    }
    Holder_26D810* hd = D_004FFC0C;
    if (hd) {
        h = hd->x30;
        if (h)
            func_00242B40(D_004FFC2C, (M_26D810*)&h->flags, 4, 1, 0);
    }
}



