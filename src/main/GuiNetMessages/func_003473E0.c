#include "types.h"
#pragma cplusplus on
class V_3473E0 {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8();
    virtual int Activate();
};
struct P_3473E0 { char pad[0x44]; V_3473E0* obj; };
struct S_3473E0 { char pad[0x88]; P_3473E0* p88; };
struct Ev_3473E0 { unsigned short type; unsigned short b2; char pad4[2]; unsigned short b6; unsigned short btn; };
extern "C" {
extern int D_00532FD0;
int func_0033C320(S_3473E0* o, int v);
int func_0033CEF0(S_3473E0* o);
int func_003473E0(S_3473E0* o, Ev_3473E0* ev);
}
static inline unsigned char Down_3473E0(Ev_3473E0* e) { unsigned char r = 0; if (e->type == 1 && e->b2 == 0) r = 1; return r; }
static inline unsigned char Btn_3473E0(Ev_3473E0* e, int b) { unsigned char r = 0; if (Down_3473E0(e) && e->btn == b) r = 1; return r; }
static inline unsigned char Plain_3473E0(Ev_3473E0* e, int b) { unsigned char r = 0; if (Btn_3473E0(e, b) && e->b6 == 0) r = 1; return r; }
static inline bool Down2_3473E0(Ev_3473E0* e) { return e->type == 1 && e->b2 == 0; }
static inline bool Btn2_3473E0(Ev_3473E0* e, int b) { return Down2_3473E0(e) && e->btn == b; }
static inline bool Plain2_3473E0(Ev_3473E0* e, int b) { return Btn2_3473E0(e, b) && e->b6 == 0; }

int func_003473E0(S_3473E0* o, Ev_3473E0* ev)
{
    if (Plain_3473E0(ev, 0x10)) {
        if (!func_0033C320(o, D_00532FD0)) func_0033C320(o, 1);
        return 1;
    }
    if (Plain2_3473E0(ev, 0x1000) && o->p88) return o->p88->obj->Activate();
    if (Plain2_3473E0(ev, 0x4000) && o->p88) return o->p88->obj->Activate();
    if (Plain2_3473E0(ev, 0x2000)) ev->btn = 0x1000;
    else if (Plain2_3473E0(ev, 0x8000)) ev->btn = 0x4000;
    return (ev->type == 1 && ev->b2 == 0 && ev->btn == 0x800 && ev->b6 == 0) ? 1 : func_0033CEF0(o);
}