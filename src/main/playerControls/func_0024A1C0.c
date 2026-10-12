#pragma cplusplus on
#include "types.h"
typedef struct { void* vtable; char pad4[0x1C]; unsigned char x20; char pad21[3]; int kind; unsigned char b; char pad29[3]; } Msg_24A1C0;
typedef struct { Msg_24A1C0 base; unsigned char x2C; char pad2D[3]; } Msg2_24A1C0;
struct Sub_24A1C0 { char pad[0xDC]; unsigned char busy; };
class Pl_24A1C0 {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
    virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
    virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47(); virtual void v48(); virtual void v49();
    virtual void v50(); virtual void v51(); virtual void v52(); virtual void v53(); virtual void v54(); virtual void v55(); virtual void v56(); virtual void v57(); virtual void v58(); virtual void v59();
    virtual void v60(); virtual void v61(); virtual void v62(); virtual void v63();
    virtual unsigned char Kind();
    char pad4[0x3208];
    int mode;
    char pad3210[0x100];
    Sub_24A1C0* sub;
};
struct H_24A1C0 { int v; H_24A1C0() : v(-1) {} };
struct St_24A1C0 {
    char pad0[0x40];
    int x40;
    int bits[1];
    char pad48[0x65];
    unsigned char xAD; char padAE[0xE]; unsigned char xBC; unsigned char xBD; char padBE[0xA];
    int xC8; H_24A1C0 xCC; char padD0[0x5C]; unsigned char x12C; char pad12D[0xB]; unsigned char x138;
    bool Test(int i) { return (bits[i / 32] >> (i & 31)) & 1 ? true : false; }
};
extern "C" {
extern char D_0055D480[];
extern char D_004E0840[];
extern char D_004D9320[];
extern unsigned char D_0048AEC8;
extern int D_004FFBD0;
void Event_Construct(Msg_24A1C0* m, void* type);
void Event_Send(Msg_24A1C0* m, void* target, int immediate);
void cMessage_dtor(Msg_24A1C0* m, int flags);
int Actor_TryObjectInteraction(int a, Pl_24A1C0* p, int b, int c);
int PlayerInput_ZoneEnteredThisFrame(St_24A1C0* s);
int PlayerInput_CrouchToggle(St_24A1C0* s, Pl_24A1C0* p);
}
static inline bool Busy_(Pl_24A1C0* pl) {
    bool b = 0;
    if (pl->sub && pl->sub->busy) b = 1;
    return b;
}
static inline bool IsKind23(Pl_24A1C0* h) { unsigned char k = h->Kind(); return k == 2 || k == 3; }
#pragma push
#pragma opt_propagation off
extern "C" void PlayerInput_HandleTriangle(St_24A1C0* s, Pl_24A1C0* p, float v)
{
    bool pressed = v > 0.0f;
    bool edge = !s->xAD && pressed;
    s->xAD = pressed;
    if (!pressed) {
        s->xBD = 0;
    } else if (s->xBD) {
        pressed = 0;
        edge = 0;
    }
    if (edge) {
        int k = s->x138 ? 0x2D : 0x2C;
        Msg_24A1C0 m;
        Event_Construct(&m, D_0055D480);
        m.x20 = 1;
        m.kind = (signed char)k;
        m.b = 0;
        m.vtable = D_004E0840;
        Event_Send(&m, p, 1);
        m.vtable = D_004E0840;
        cMessage_dtor(&m, 0);
        if (p->mode == 0x14) {
            Msg2_24A1C0 m2x;
            Event_Construct(&m2x.base, D_0055D480);
            m2x.base.kind = 0x28;
            m2x.base.b = 1;
            m2x.base.vtable = D_004D9320;
            m2x.base.x20 = 1;
            m2x.x2C = D_0048AEC8;
            Event_Send(&m2x.base, p, 1);
            m2x.base.vtable = D_004E0840;
            pressed = 0;
            edge = 0;
            cMessage_dtor(&m2x.base, 0);
        }
    }
    if (edge && !Busy_(p) && !IsKind23(p)) {
        int mode = p->mode;
        if ((mode == 0 || mode == 0x11 || mode == 0x12) && Actor_TryObjectInteraction(D_004FFBD0, p, 1, 0)) {
            int i;
            s->x12C = 1;
            s->xC8 = 0;
            pressed = 0;
            edge = 0;
            { H_24A1C0 t; H_24A1C0* hp = &t; s->xCC = *hp; }
            s->xBC = 1;
            s->bits[0] &= ~0x20;
            for (i = 0xB; i >= 0 && !s->Test(i); i--) {}
            if (!s->Test(i))
                s->x40 = -1;
            else
                s->x40 = i;
        }
    }
    if ((edge || (PlayerInput_ZoneEnteredThisFrame(s) && pressed)) && PlayerInput_CrouchToggle(s, p))
        pressed = 0;
    if (pressed) {
        {
            Msg_24A1C0 m3;
            Event_Construct(&m3, D_0055D480);
            m3.x20 = 1;
            m3.vtable = D_004E0840;
            m3.kind = 0xF;
            m3.b = 0;
            Event_Send(&m3, p, 1);
            m3.vtable = D_004E0840;
            cMessage_dtor(&m3, 0);
        }
        {
            Msg_24A1C0 m4;
            Event_Construct(&m4, D_0055D480);
            m4.vtable = D_004E0840;
            m4.kind = 0x1B;
            m4.x20 = 1;
            m4.b = 0;
            Event_Send(&m4, p, 1);
            m4.vtable = D_004E0840;
            cMessage_dtor(&m4, 0);
        }
    }
}
#pragma pop

