#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"
#include "v4_asm_copy.h"
#pragma always_inline on
#pragma inline_depth(8)

/* cGameCamera_v10: per-frame camera update: refresh its node, face along the node's forward row,
 * run the base logic and, while armed, ping every visible player that is not in state 4
 * (event D_004EE930 to the listener at +0xCE8, then a 15-frame cooldown). */

struct V4 { float x, y, z, w; } __attribute__((aligned(16)));
struct M4 { V4 r0, r1, r2, r3; };

class XNode {
public:
    VPAD16(a) VPAD4(b)
    virtual void Update();
    char pad4[0x10 - 4];
    M4 m;
    unsigned char dirty;
};

class Ctl {
public:
    VPAD16(a) VPAD2(b) VPAD1(c)
    virtual int IsActive();
    VPAD8(d) VPAD4(e)
    virtual unsigned char State();
    char pad4[0x30 - 4];
    void* target;
};

struct Player { char pad0[0x58]; Ctl* ctl; };

struct Cam {
    char pad0[0x2C];
    unsigned char b2C;
    unsigned char b2D;
    bool b2E;
    char pad2F[0x50 - 0x2F];
    XNode* node;
    char pad54[0x64 - 0x54];
    float heading;
    char pad68[0xCE0 - 0x68];
    int cooldown;
    unsigned char armed;
    char padCE5[3];
    void* listener;
};

struct Msg { char* vt; char pad4[0x20]; void* target; unsigned char kind; char pad25[0x24 - 0x21 + 3]; };

extern "C" {
extern char D_004EE930[];
extern char D_004DCF10[];
extern char D_004DA310[];
extern unsigned char g_IsMultiplayer;
extern unsigned char D_005721C0;
float Math_Atan2f(float y, float x);
void Actor_BaseLogicUpdate(Cam* c, float dt);
Player* PlayerSlots_Get(int i);
int cGameCamera_CanSee(Cam* c, void* target);
void Event_Construct(void* e, char* type);
void Event_Send(void* e, void* to, int f);
void cMessage_dtor(void* e, int f);
void cGameCamera_v10(Cam* c, float dt);
}

static inline void Face(Cam* c)
{

    XNode* n = c->node;
    V4 f;
    if (n->dirty) n->Update();
    {
        M4* m = (M4*)((char*)n + 0x10);
        /* 128-bit lq/sq quadword copy; the volatile asm also keeps MW's materialised bools below */
        { V4* d = &f; const V4* s = &m->r1; __int128 t; asm volatile { lq t, 0(s); sq t, 0(d) } }
    }
    /* volatile read: retail loads f.y in the call delay slot */
    c->heading = Math_Atan2f(f.x, *(volatile float*)&f.y);
}
static inline M4* Xf(XNode* n) { if (n->dirty) n->Update(); return &n->m; }

static inline bool Standing(Cam* o) { bool r = false; if (o->b2D && o->b2C) r = true; return r; }
static inline bool Alive(Cam* o) { bool r = false; if (Standing(o) && ((o->b2E != 0) ^ 1)) r = true; return r; }
/* the bool temporary keeps retail's daddiu for the single-player 1 */
static inline int DeadOk(void) { int r; if (g_IsMultiplayer) r = D_005721C0; else { bool on = true; r = on; } return r; }

struct EvMsg {
    char* vt; char pad4[0x1C]; unsigned char kind; char pad21[3]; void* target; char pad28[8];
    EvMsg(void* t) { EvMsg* self = (EvMsg*)(int)this; Event_Construct(self, D_004EE930); self->vt = D_004DCF10; self->vt = D_004DA310; self->target = t; }
    /* explicit teardown at the end of the send block (retail inlines it; a C++ dtor also emits a weak out-of-line copy) */
    void Done() { vt = D_004DCF10; cMessage_dtor(this, 0); }
};

void cGameCamera_v10(Cam* c, float dt)
{
    Face(c);
    Actor_BaseLogicUpdate(c, dt);
    if (!Alive(c)) return;
    if (!c->armed) return;
    if (c->cooldown) {
        c->cooldown--;
        return;
    }
    {
        int i;
        for (i = 0; i < 4; i++) {
            Player* p = PlayerSlots_Get(i);
            if (p && p->ctl && p->ctl->IsActive() && p->ctl->State() != 4) {
                void* t = p->ctl->target;
                if (cGameCamera_CanSee(c, t)) {
                    EvMsg m(t);
                    m.kind = DeadOk() ? 1 : 2;
                    if (c->listener) Event_Send(&m, c->listener, 0);
                    c->cooldown = 15;
                    m.Done();
                }
            }
        }
    }
}
