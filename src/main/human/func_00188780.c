#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"
/* Bullet_ApplyHit: resolve a bullet hit on this actor - which body region it struck (hit volumes,
   or the aimed part for a player's own target), friendly-fire/miss chance, kill stats, then the
   combat event; records the region and node code back into the hit record. */
struct V_188780 { float x, y, z, w; } __attribute__((aligned(16)));
struct Ray_188780 { char pad0[0x10]; V_188780 dir; char pad20[0x10]; V_188780 from; };
struct HV_188780 { char pad0[0x24]; float f24; char pad28[0x18]; signed char ids[8]; signed char count; char pad49[3]; float f4C; } __attribute__((aligned(16)));
struct Ctrl_188780 { VPAD16(a) VPAD2(b) VPAD1(c) virtual int IsHuman(); };
struct Wpn_188780 { char pad0[0xBC]; signed char type; };
struct Actor_188780;
struct Hit_188780 {
    Actor_188780* src;      /* 0x0 */
    Ray_188780* ray;        /* 0x4 */
    Actor_188780* tgt;      /* 0x8 */
    char padC;
    unsigned char b0D;      /* 0xD */
    char padE[2];
    int part;               /* 0x10 */
    char pad14[4];
    Wpn_188780* wpn;        /* 0x18 */
    char pad1C[4];
    unsigned char b20;      /* 0x20 */
    char pad21[3];
    int armor;              /* 0x24 */
    float f28;              /* 0x28 */
    unsigned char b2C;      /* 0x2C */
    char pad2D[3];
    int loc;                /* 0x30 */
    float f34;              /* 0x34 */
    Actor_188780* victim;   /* 0x38 */
    int node;               /* 0x3C */
    float dmg;              /* 0x40 */
};
struct Actor_188780 {
    VPAD32(a) VPAD16(b) VPAD8(c) VPAD4(d) VPAD2(e)
    virtual int HandleCombatEvent(float dmg, Actor_188780* src, int loc, int type, int* armor, int flag, V_188780* hitPos);
    VPAD1(f)
    virtual unsigned char Stance();
    char pad4[0x10];
    unsigned char alive;    /* 0x14 */
    char pad15[0x58 - 0x15];
    Ctrl_188780* ctrl;      /* 0x58 */
    char pad5C[0x33A0 - 0x5C];
    int armorHP;            /* 0x33A0 */
    unsigned char dead;     /* 0x33A4 */
};
extern "C" {
extern float D_0048A2B8[];
extern signed char ActorNodeCodeTable[];
extern char g_Game[];
int Random_Next(void);
Actor_188780* Controller_GetAimTarget(Ctrl_188780* c);
void* Agent_GetSelected(void* a, int b);
void Stats_Add(void* a, int b, int c);
int Actor_GetHitVolumes(Actor_188780* a, V_188780* from, V_188780* dir, int mode, HV_188780* out);
int Bullet_ApplyHit(Actor_188780* self, Hit_188780* h);
}

static inline bool IsHuman(Actor_188780* a) { bool r = 0; if (a->ctrl && a->ctrl->IsHuman()) r = 1; return r; }
static inline bool Dying(Actor_188780* a) { bool r; unsigned char s = a->Stance(); r = 1; if ((unsigned int)(s - 2) > 1) r = 0; return r; }
static inline int IsNullNV(int x) { return (x != 0) ^ 1; }
static inline void SetNode(Hit_188780* h, int id) { int j; for (j = 0; j < 21; j++) { if (ActorNodeCodeTable[j] == id) { h->node = j; break; } } }
/* damage types that count toward the shooter's hit stats: 0, 1, 7, 9, 10, 13 */
static inline bool Counts(unsigned char t)
{
    bool r = 0;
    if ((unsigned int)t < 14 && ((1 << t) & 0x2683))
        r = 1;
    return r;
}

int Bullet_ApplyHit(Actor_188780* self, Hit_188780* h)
{
    HV_188780 hv;
    bool miss;
    int part;
    bool a;
    /* loc/type/mode are int (tested as unsigned char) - the retail code assigns them with li and
       passes them to the int parameters below without re-masking */
    /* declaration order chosen for the retail register assignment */
    int type;
    int flags;
    unsigned char own;
    bool both;
    Ray_188780* ray;
    unsigned char aimed;
    int loc;
    Actor_188780* src;
    int mode;
    Ctrl_188780* sc;
    int dmg;
    int ne;
    ne = self != h->tgt;
    own = IsNullNV(ne);
    if (own)
        part = h->part;
    else
        part = -1;
    if (h->wpn)
        type = h->wpn->type;
    else
        type = 8;
    dmg = (int)h->dmg;
    ray = h->ray;
    sc = h->src ? h->src->ctrl : 0;
    mode = (unsigned char)ne;
    both = 0;
    a = 0;
    if (IsHuman(self) && sc)
        a = 1;
    if (a && sc->IsHuman())
        both = 1;
    if (!(unsigned short)dmg || self->dead || both || (unsigned char)type == 7)
        mode = 0;
    else if (self->armorHP <= 0)
        mode = 2;
    /* an NPC shooting at something other than its aim target misses by chance (HitInnocentNpcChance) */
    miss = 0;
    if (sc && !sc->IsHuman() && Controller_GetAimTarget(sc) != self) {
        if ((float)Random_Next() / 2147483648.0f > D_0048A2B8[0])
            miss = 1;
    }
    hv.f4C = h->f28;
    if (miss)
        flags = 0;
    else
        flags = Actor_GetHitVolumes(self, &ray->from, &ray->dir, mode, &hv);
    loc = 0;
    if (flags & 0x40)
        loc = 2;
    else if (flags & 0x20)
        loc = 4;
    else if (flags & 0x80)
        loc = 3;
    else if (flags)
        loc = 1;
    aimed = sc && Controller_GetAimTarget(sc) == self && own;
    if (aimed) {
        int k = part & 3;
        if (k == 0)
            loc = 2;
        else if (k == 3)
            loc = 3;
        else
            loc = 1;
    }
    src = h->src;
    if ((unsigned char)loc && src && src->alive && !h->b20) {
        if (IsHuman(self)) {
            if (both) {
                dmg = 0;
                if ((unsigned char)type == 7)
                    type = 0;
            }
            if (!aimed)
                loc = 3;
        }
        {
            int t = (unsigned char)type;
            bool cnt = Counts(t);
            if (!Dying(self) && cnt) {
                if (IsHuman(src) && src->alive && !both && h->b2C) {
                    Stats_Add(Agent_GetSelected(g_Game, -1), 10, 1);
                    if (h->b0D)
                        Stats_Add(Agent_GetSelected(g_Game, -1), 12, 1);
                    if (t == 7 && (unsigned char)loc != 2)
                        Stats_Add(Agent_GetSelected(g_Game, -1), 6, 1);
                }
            }
        }
        self->HandleCombatEvent((float)dmg, src, loc, type, &h->armor, 0, 0);
    }
    if (flags && h->armor <= 0) {
        int i;
        h->node = -1;
        h->f34 = hv.f24;
        h->loc = (unsigned char)loc;
        h->victim = self;
        for (i = hv.count - 1; i >= 0; i--) {
            if (hv.ids[i] >= 0) {
                SetNode(h, hv.ids[i]);
                break;
            }
        }
    }
    return loc;
}
