/* cHuman_ShootWeapon: act on a fire request: throw a grenade or star, start a
 * melee attack, or discharge the held weapon at the requested target. */
#pragma cplusplus on
#pragma inline_depth(10)
#include "types.h"
#include "vslot_pad.h"
/* lq/sq: 128-bit quadword moves have no C equivalent (asm). */
struct V {
    float x, y, z, w;
    V() {}
    V(const V& o) { V* d = this; const V* s = &o; __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(d), "r"(s) : "memory"); }
} __attribute__((aligned(16)));
struct Req { int id; int f4; unsigned char b8; char p9[7]; V pos; float f20; };
struct Sec { char p0[0x310]; unsigned char a, b; };
struct SecState { char p0[0x4C]; unsigned char ok; char p4D[3]; };
struct Act {
    VPAD32(a) VPAD32(b) virtual unsigned char Life();
    char p04[0x3210 - 4]; int f3210; char p3214[0x3248 - 0x3214]; int f3248;
    char p324C[0x3314 - 0x324C]; Sec* sec; char p3318[0x33E4 - 0x3318];
    unsigned char b33E4; char p33E5[3]; unsigned char b33E8; char p33E9[0x3524 - 0x33E9]; void* inv;
};
extern "C" {
extern int g_NoneWord;
extern char g_Game[];
extern SecState SecondaryStateTable[];
void* nGobjManager_LookupGOBJ_cObjectIdR(Req* r);
int cWeapon_GetEquipmentType(void* inv);
void cWeapon_ReloadIfOutOfAmmo(void* inv);
int cWeapon_Ready(void* inv);
void cHuman_ThrowGrenade(Act* a, Req* r, V* p, float f);
void cHuman_ThrowStar(Act* a, Req* r, V* p);
void* cGameSystem_GetAgentData(void* list, int idx);
int cAgentData_HasSpecialBonus(void* a, int k);
void* cWeapon_GetStabTarget(void* inv, unsigned char* out);
void Melee_StartAttack(Act* a, void* t, unsigned char f);
void cWeapon_FireIfReady(void* inv, void* t, int a, unsigned char b, int c);
void cHuman_ShootWeapon(Act* self, Req* req);
}
typedef unsigned char u8;
static inline u8 Bit2(Act* a) { return ((a->f3210 >> 2) & 1) != 0; }
static inline u8 Bit4(Act* a) { return ((a->f3210 >> 4) & 1) != 0; }
static inline u8 Bit5(Act* a) { return ((a->f3210 >> 5) & 1) != 0; }
static inline u8 Bit7(Act* a) { return ((a->f3210 >> 7) & 1) != 0; }
static inline u8 Bit8(Act* a) { return ((a->f3210 >> 8) & 1) != 0; }
static inline u8 Bit20(Act* a) { return ((a->f3210 >> 20) & 1) != 0; }
static inline u8 BBit3(Act* a) { return ((a->f3248 >> 3) & 1) != 0; }
static inline u8 NBBit3(Act* a) { return !BBit3(a); }
static inline u8 D0(Act* a) { u8 r = 0; if (Bit2(a)) { if (NBBit3(a)) r = 1; } return r; }
static inline u8 C0(Act* a) { u8 r = 1; if (!Bit4(a)) { if (!Bit5(a)) r = 0; } return r; }
static inline u8 C1(Act* a) { u8 r = 1; if (!C0(a)) { if (!Bit7(a)) r = 0; } return r; }
static inline u8 C2(Act* a) { u8 r = 1; if (!C1(a)) { if (!Bit8(a)) r = 0; } return r; }
static inline u8 C3(Act* a) { u8 r = 1; if (!C2(a)) { if (!Bit20(a)) r = 0; } return r; }
static inline u8 C4(Act* a) { u8 r = 1; if (!C3(a)) { if (!D0(a)) r = 0; } return r; }
static inline u8 IsHand(unsigned char c) { unsigned char b = 0; if ((unsigned int)(c - 3) < 8 && ((1 << (c - 3)) & 0x83)) b = 1; return b; }
static inline bool IsNone(Req* r) { return r->id == g_NoneWord; }
static inline SecState* St(int i) { return &SecondaryStateTable[i]; }
static inline int Ready(Sec* s) { unsigned char r = 0; if (St(s->a)->ok && St(s->b)->ok) r = 1; return r; }

void cHuman_ShootWeapon(Act* self, Req* req)
{
    bool dead; unsigned char life = self->Life();
    dead = true;
    if (life != 3 && life != 2) dead = false;
    if (dead) return;
    void* tgt = IsNone(req) ? 0 : nGobjManager_LookupGOBJ_cObjectIdR(req);
    int cls = cWeapon_GetEquipmentType(self->inv);
    u8 melee = (unsigned char)cls == 11;
    u8 hand = IsHand(cls);
    cWeapon_ReloadIfOutOfAmmo(self->inv);
    if (!melee && !cWeapon_Ready(self->inv)) return;
    u8 busy = C4(self);
    if ((unsigned char)cls == 1) {
        if (!busy && !self->b33E4) {
            V p = req->pos;
            cHuman_ThrowGrenade(self, req, &p, req->f20);
        }
    } else if ((unsigned char)cls == 7) {
        if (!busy && !self->b33E4) {
            V p = req->pos;
            cHuman_ThrowStar(self, req, &p);
        }
    } else if (hand || melee) {
        if (!busy) {
            if (melee && !cAgentData_HasSpecialBonus(cGameSystem_GetAgentData(g_Game, -1), 0)) return;
            if (!self->b33E8) {
                u8 f;
                void* t = cWeapon_GetStabTarget(self->inv, &f);
                Melee_StartAttack(self, t, f);
            }
        }
    } else {
        if (!self->sec) return;
        if (!Ready(self->sec)) return;
        { unsigned char b8 = req->b8; cWeapon_FireIfReady(self->inv, tgt, req->f4, b8, 0); }
    }
}
