#pragma cplusplus on
#include "types.h"
struct Obj285590 { char p[0xC]; int id; };
struct Sub285590 { char p[0x54]; unsigned char b54; char p55[7]; Obj285590* tgt; int tid; };
struct Tank285590 { char p[0x6C]; Sub285590* sub; unsigned char b70; };
struct Msg285590 { void* vtable; char base[0x18]; int f1C; unsigned char b20; char p21[3]; unsigned char b24; char p25[3]; Obj285590* f28; int f2C; };
extern "C" {
extern unsigned char D_005721C8;
extern unsigned char D_005721C0;
extern char D_00506260[];
extern char D_004DCF50[];
extern char D_004DCF10[];
void Event_Construct(void* m, void* type);
void Event_Send(void* m, void* target, int immediate);
void cMessage_dtor(void* m, int flags);
}
static inline int IsAuth285590(void) { return D_005721C8 ? D_005721C0 : 1; }
static inline void SetT285590(Sub285590* s, Obj285590* t) { int none; s->tgt = t; s->tid = *(t ? &t->id : (none = -1, &none)); }
extern "C" void func_00285590(Tank285590* self, Obj285590* t) {
    if (self->sub) {
        self->sub->b54 = 0;
        SetT285590(self->sub, t);
    }
    self->b70 = 0;
    if (D_005721C8 && IsAuth285590()) {
        Msg285590 m;
        Event_Construct(&m, D_00506260);
        m.vtable = D_004DCF50;
        m.f28 = t;
m.b20 = 4;
m.b24 = 0;
m.f1C = 0x40;
m.f2C = 0;
        Event_Send(&m, self, 0);
        m.vtable = D_004DCF10;
        cMessage_dtor(&m, 0);
    }
}
