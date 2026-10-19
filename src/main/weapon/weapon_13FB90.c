/*
 * main/weapon: range (3 files, 0013FB90-0013FE80)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#include "vslot_pad.h"

/* library prototypes shared by the blocks below (C linkage) */
int sprintf(void *, const void *, ...);

/* merge_units: begin func_0013FB90 */
#pragma push /* merge_units */
typedef struct { int f0; int id; int f8; int ammo; } Slot13F;
typedef struct { int f0; Slot13F s[6]; char p64[0x20]; unsigned char f84; char p85[3]; char *f88; } PS0_0013FD20;
int Weapon_TransferSpareRounds(PS0_0013FD20* arg0, int arg1, int arg2); /* gsynth: defined below */
typedef struct { char d[0x9C]; } Str_FB90;
typedef struct {
    void* vt;
    char pad4[0x1C];
    unsigned char flag;
    char pad21[0x57];
    Str_FB90 s78;
    Str_FB90 s114;
    char pad1B0[0x10];
} __attribute__((aligned(16))) Snd_FB90;
typedef struct {
    char pad0[0x48];
    Str_FB90 s48;
    Str_FB90 sE4;
    char pad180[0x10];
} __attribute__((aligned(16))) Req_FB90;
typedef struct { int f0; int id; int clip; int reserve; } Ent_FB90;
typedef struct {
    char pad0[4];
    Ent_FB90 ent[7];
    char pad74[0x10];
    unsigned char cur;
    char pad85[3];
    void* owner;
    char pad8C[0xD];
    unsigned char f99;
} W_FB90;
typedef struct { char pad0[0x20]; char snd[0x50]; int clipSize; char pad74[0x98]; int f10C; } Db_FB90;
extern int g_WeaponDatabase;
extern char g_Game[];
extern char D_004DAE30[];
Db_FB90* WeaponDb_Get(int db, int id);
#if 0 /* merge_units */
int Weapon_TransferSpareRounds(W_FB90* w, int n, int kind);
#endif /* merge_units */
#define Weapon_TransferSpareRounds(a0, a1, a2) (Weapon_TransferSpareRounds((void *)(a0), (a1), (a2))) /* merge_units */

void SoundRequest_Ctor(Req_FB90* r, int a, void* preset, int b, int c);
void SoundEvent_CtorFromPreset(Snd_FB90* e, Req_FB90* r, void* owner);
void Event_Send(void* msg, void* target, int immediate);
void cMessage_dtor(void* msg, int flags);
void FileMan_Release(Str_FB90* s, int flag);

void Weapon_StartReload(W_FB90* self)
{
    Ent_FB90* e;
    Db_FB90* db;
    int need;
    int extra;
    if (self->cur == 6)
        return;
    e = &self->ent[self->cur];
    if (e->id == -1)
        return;
    db = WeaponDb_Get(g_WeaponDatabase, e->id);
    need = db->clipSize - e->clip;
    extra = 0;
    if (e->reserve < need) {
        extra = Weapon_TransferSpareRounds(self, need - e->reserve, db->f10C);
        need = e->reserve;
    }
    e->clip += need + extra;
    if (!self->f99)
        e->reserve -= need;
    if (self->cur == 0) { unsigned char v = self->ent[1].id == -1; if (v ^ 1) {
        self->ent[1].clip = e->clip;
        self->ent[1].reserve = e->reserve;
    }}
    {
        Req_FB90 req;
        Snd_FB90 snd;
        SoundRequest_Ctor(&req, 1, db->snd, 0, 0);
        SoundEvent_CtorFromPreset(&snd, &req, self->owner);
        snd.flag = 1;
        Event_Send(&snd, g_Game, 0);
        snd.vt = D_004DAE30;
        FileMan_Release(&snd.s114, -1);
        FileMan_Release(&snd.s78, -1);
        cMessage_dtor(&snd, 0);
        FileMan_Release(&req.sE4, -1);
        FileMan_Release(&req.s48, -1);
    }
}
#undef Weapon_TransferSpareRounds /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0013FB90(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0013FB90 */

/* merge_units: begin func_0013FD20 */
#pragma push /* merge_units */
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
int Hud_PostNotification(int, char *);
int Loc_LookupText(char *);
#if 0 /* merge_units */
char *WeaponDb_Get(int, int);
#endif /* merge_units */
#define WeaponDb_Get(a0, a1) ((char *)WeaponDb_Get((a0), (a1))) /* merge_units */

extern int g_Hud;


int Weapon_TransferSpareRounds(PS0_0013FD20 *arg0, int arg1, int arg2) {
int total;
int i;
Slot13F *s;
char *w;
char buf[128];

    total = 0;
    for (i = 0; i < 6; i++) {
        if (i == arg0->f84) continue;
        s = &arg0->s[i];
        if (s->id == -1) continue;
        w = WeaponDb_Get(g_WeaponDatabase, s->id);
        if (F_(w, 0x10C, int) != arg2) continue;
        if (F_(w, 0xF0, unsigned char) != 0) continue;
        if (s->ammo <= 0) continue;
        if (arg0->f88 != NULL && F_(arg0->f88, 0x14, unsigned char) != 0) {
            int t = Loc_LookupText(w + 0x80);
            sprintf(buf, "%s %s", t, Loc_LookupText("TransferAmmo"));
            Hud_PostNotification(g_Hud, buf);
        }
        { int a = s->ammo; if (arg1 < a) { total += arg1; s->ammo = a - arg1; break; } s->ammo = 0; arg1 -= a; total += a; }
    }
    return total;
}
#undef WeaponDb_Get /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0013FD20(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0013FD20 */

/* merge_units: begin func_0013FE80 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma opt_common_subs off
class R_FE80 {
public:
    VPAD16(a) VPAD2(b) VPAD1(c)
    virtual int IsLocal();
};
struct Own_FE80 { char pad[0x14]; unsigned char f14; char pad15[0x43]; R_FE80* recv; };
struct S_FE80 { char pad[0x88]; Own_FE80* own; };
extern "C" {
void* Agent_GetSelected(void* list, int idx);
void Stats_Add(void* agent, int stat, int n);
}
extern "C" void Weapon_RecordShotStats(S_FE80* self, int hit)
{
    Own_FE80* o = self->own;
    if (o->recv) {
        unsigned char local = 0;
        R_FE80* r = o->recv;
        if (r && r->IsLocal())
            local = 1;
        if (local && self->own->f14) {
            Stats_Add(Agent_GetSelected(g_Game, -1), 9, 1);
            if (hit)
                Stats_Add(Agent_GetSelected(g_Game, -1), 0xB, 1);
        }
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0013FE80(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0013FE80 */
