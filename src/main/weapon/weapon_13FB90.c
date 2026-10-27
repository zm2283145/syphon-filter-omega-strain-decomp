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
int cWeapon_StealAmmoFromInactiveWeapons(PS0_0013FD20* arg0, int arg1, int arg2); /* gsynth: defined below */
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
Db_FB90* cWeaponDB_GetEntry(int db, int id);
#if 0 /* merge_units */
int cWeapon_StealAmmoFromInactiveWeapons(W_FB90* w, int n, int kind);
#endif /* merge_units */
#define cWeapon_StealAmmoFromInactiveWeapons(a0, a1, a2) (cWeapon_StealAmmoFromInactiveWeapons((void *)(a0), (a1), (a2))) /* merge_units */

void cSndFx_ctor_int_charP_cGOBJP_int(Req_FB90* r, int a, void* preset, int b, int c);
void cPlaySoundMsg_ctor_cSndFxR(Snd_FB90* e, Req_FB90* r, void* owner);
void QueueMessage_cMessageR_cSystemP_int(void* msg, void* target, int immediate);
void cMessage_dtor(void* msg, int flags);
void cFileMan_dtor(Str_FB90* s, int flag);

void cWeapon_Reload(W_FB90* self)
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
    db = cWeaponDB_GetEntry(g_WeaponDatabase, e->id);
    need = db->clipSize - e->clip;
    extra = 0;
    if (e->reserve < need) {
        extra = cWeapon_StealAmmoFromInactiveWeapons(self, need - e->reserve, db->f10C);
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
        cSndFx_ctor_int_charP_cGOBJP_int(&req, 1, db->snd, 0, 0);
        cPlaySoundMsg_ctor_cSndFxR(&snd, &req, self->owner);
        snd.flag = 1;
        QueueMessage_cMessageR_cSystemP_int(&snd, g_Game, 0);
        snd.vt = D_004DAE30;
        cFileMan_dtor(&snd.s114, -1);
        cFileMan_dtor(&snd.s78, -1);
        cMessage_dtor(&snd, 0);
        cFileMan_dtor(&req.sE4, -1);
        cFileMan_dtor(&req.s48, -1);
    }
}
#undef cWeapon_StealAmmoFromInactiveWeapons /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0013FB90(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0013FB90 */

/* merge_units: begin func_0013FD20 */
#pragma push /* merge_units */
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
int cHud_Message(int, char *);
int nGlobalization_GetString_charP(char *);
#if 0 /* merge_units */
char *cWeaponDB_GetEntry(int, int);
#endif /* merge_units */
#define cWeaponDB_GetEntry(a0, a1) ((char *)cWeaponDB_GetEntry((a0), (a1))) /* merge_units */

extern int g_Hud;


int cWeapon_StealAmmoFromInactiveWeapons(PS0_0013FD20 *arg0, int arg1, int arg2) {
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
        w = cWeaponDB_GetEntry(g_WeaponDatabase, s->id);
        if (F_(w, 0x10C, int) != arg2) continue;
        if (F_(w, 0xF0, unsigned char) != 0) continue;
        if (s->ammo <= 0) continue;
        if (arg0->f88 != NULL && F_(arg0->f88, 0x14, unsigned char) != 0) {
            int t = nGlobalization_GetString_charP(w + 0x80);
            sprintf(buf, "%s %s", t, nGlobalization_GetString_charP("TransferAmmo"));
            cHud_Message(g_Hud, buf);
        }
        { int a = s->ammo; if (arg1 < a) { total += arg1; s->ammo = a - arg1; break; } s->ammo = 0; arg1 -= a; total += a; }
    }
    return total;
}
#undef cWeaponDB_GetEntry /* merge_units */
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
void* cGameSystem_GetAgentData(void* list, int idx);
void cAgentData_AddScore(void* agent, int stat, int n);
}
extern "C" void cWeapon_AddShotStat(S_FE80* self, int hit)
{
    Own_FE80* o = self->own;
    if (o->recv) {
        unsigned char local = 0;
        R_FE80* r = o->recv;
        if (r && r->IsLocal())
            local = 1;
        if (local && self->own->f14) {
            cAgentData_AddScore(cGameSystem_GetAgentData(g_Game, -1), 9, 1);
            if (hit)
                cAgentData_AddScore(cGameSystem_GetAgentData(g_Game, -1), 0xB, 1);
        }
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0013FE80(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0013FE80 */
