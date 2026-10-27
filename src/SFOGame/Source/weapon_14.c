/*
 * main/weapon: range (6 files, 00142E80-001434D0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#pragma push
#pragma cplusplus on
#include "message_two_member_dtor.h"
#pragma pop

/* merge_units: begin func_00142E80 */
#pragma push /* merge_units */
typedef struct { unsigned char flag; char p[3]; int id; int c; int ammo; } E_INV;
typedef struct { int pad; E_INV e[7]; char pad2[0x84 - 0x74]; unsigned char cur; } INV;
typedef struct { char pad[0x200]; int x[64]; } WDef;
extern void* g_WeaponDatabase;
typedef struct { char pad[0xF4]; int xF4; } WD_2E80;
extern WD_2E80* cWeaponDB_GetEntry(void* db, int id);
int cWeapon_GetMostVisible(INV* self)
{
    int best = 0;
    int i = 0;
    INV* p = self;
    do {
        if ((p->e[0].flag || i == self->cur) && p->e[0].id != -1) {
            int v = cWeaponDB_GetEntry(g_WeaponDatabase, p->e[0].id)->xF4;
            if (best < v)
                best = v;
        }
        i++;
        p = (INV*)((char*)p + 16);
    } while (i < 6);
    return best;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00142E80(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00142E80 */

/* merge_units: begin func_00142F20 */
#pragma push /* merge_units */
float GetMagnificationDegs(float arg0, float arg1); /* gsynth: defined below */
#pragma opt_dead_assignments off
typedef struct { char d[0x9C]; } Str_2F20;
typedef struct {
    void* vt;
    char pad4[0x1C];
    unsigned char flag;
    char pad21[0x57];
    Str_2F20 s78;
    Str_2F20 s114;
    char pad1B0[0x10];
} __attribute__((aligned(16))) Snd_2F20;
typedef struct {
    void* vt;
    char pad4[0x1C];
    unsigned char flag;
    char pad21[0x57];
    Str_2F20 s78;
    Str_2F20 s114;
    char pad1B0[0x20];
} __attribute__((aligned(16))) Snd2_2F20;
typedef struct { int f0; int id; int clip; int reserve; } Ent_2F20;
typedef struct {
    char pad0[4];
    Ent_2F20 ent[7];
    char pad74[0x10];
    unsigned char cur;
    char pad85[3];
    void* owner;
    char pad8C[0x5C];
    float fE8;
    unsigned char fEC;
    unsigned char fED;
    unsigned char fEE;
    char padEF;
    unsigned char fF0;
} W_2F20;
typedef struct { char pad0[0xAC]; float fAC; int fB0; int fB4; char padB8[0x58]; float f110; float f114; } Db_2F20;
#if 0 /* merge_units */
extern int g_WeaponDatabase;
#endif /* merge_units */
#define g_WeaponDatabase (*(int*)&g_WeaponDatabase) /* merge_units */

extern unsigned char D_004EA140;
extern float D_00489CA8;
extern float D_00489CB0;
extern char D_004F2170[];
extern char g_Game[];
extern char D_004DAE30[];
extern char D_004DADF0[];
#if 0 /* merge_units */
Db_2F20* cWeaponDB_GetEntry(int db, int id);
#endif /* merge_units */
#define cWeaponDB_GetEntry(a0, a1) ((Db_2F20 *)cWeaponDB_GetEntry((void *)(a0), (a1))) /* merge_units */

int cWeapon_GetEquipmentType(void);
#if 0 /* merge_units */
float GetMagnificationDegs(float v, float def);
#endif /* merge_units */
#define GetMagnificationDegs(a0, a1) (GetMagnificationDegs((a0), (a1))) /* merge_units */

void cPlaySoundMsg_ctor_cSndFxR(Snd_2F20* e, void* preset, void* owner);
void cStopSoundMsg_ctor_cSndFxR_cGOBJP(Snd2_2F20* e, void* preset, void* owner);
void QueueMessage_cMessageR_cSystemP_int(void* msg, void* target, int immediate);
#if 0 /* merge_units */
void cMessage_dtor(void* msg, int flags);
#endif /* merge_units */
#define cMessage_dtor(a0, a1) (cMessage_dtor((a0), (a1))) /* merge_units */

#if 0 /* merge_units */
void cFileMan_dtor(Str_2F20* s, int flag);
#endif /* merge_units */
#define cFileMan_dtor(a0, a1) (cFileMan_dtor((void *)(a0), (a1))) /* merge_units */


static inline float Clamp_2F20(float x, float lo, float hi) { float r; asm { max.s r, x, lo; min.s r, r, hi } return r; }
static inline float Abs_2F20(float x) { float r; asm { abs.s r, x } return r; }

float cWeapon_GetFOV(W_2F20* self, unsigned char zoom, int dir, float cur, float dt)
{
    float fov = 65.0f;
    unsigned char play = 0;
    unsigned char canZoom = 0;
    if ((unsigned char)cWeapon_GetEquipmentType() == 1)
        zoom = 0;
    if (zoom != self->fED) {
        self->fED = zoom;
        self->fEE = 1;
    }
    if (self->cur != 6) {
        int id = self->ent[self->cur].id;
        if (id != -1) {
            Db_2F20* db = cWeaponDB_GetEntry(g_WeaponDatabase, id);
            float wide = GetMagnificationDegs(db->f110, 65.0f);
            float narrow = GetMagnificationDegs(db->f114, 65.0f);
            if (zoom) {
                float d = (float)dir * dt;
                float step = 0.0f;
                float v;
                if (db->fB4) {
                    if (!self->fEC && d)
                        { float sg; float range; sg = d > 0.0f ? 1.0f : -1.0f; range = narrow - wide; step = range * sg / (float)db->fB4; }
                    self->fEC = d != 0.0f;
                } else {
                    step = d * (narrow - wide) / db->fAC;
                }
                v = self->fE8 + step;
                fov = Clamp_2F20(v, narrow, wide);
                self->fE8 = fov;
            } else if (!D_004EA140 && !self->fEE) {
                self->fE8 = wide;
            }
            canZoom = db->fB0 != 0 && narrow < wide;
        }
    }
    {
        float target = 0.017453292f * fov;
        if (canZoom || self->fEE) {
            float delta; float lim = D_00489CA8; float diff = target - cur; float lo = -lim; asm { max.s lo, diff, lo; min.s lo, lo, lim } delta = D_00489CB0 * (lo * dt);
            cur += delta;
            if (Abs_2F20(delta) < 0.01f)
                self->fEE = 0;
            if (!(Abs_2F20(delta) <= 0.001f) && canZoom && dir)
                play = 1;
        } else {
            cur = target;
        }
    }
    if (play) {
        if (!self->fF0) {
            Snd_2F20 snd;
            cPlaySoundMsg_ctor_cSndFxR(&snd, D_004F2170, self->owner);
            snd.flag = 1;
            QueueMessage_cMessageR_cSystemP_int(&snd, g_Game, 0);
            self->fF0 = 1;
            snd.vt = D_004DAE30;
            cFileMan_dtor(&snd.s114, -1);
            cFileMan_dtor(&snd.s78, -1);
            cMessage_dtor(&snd, 0);
        }
    } else if (self->fF0) {
        Snd2_2F20 snd;
        cStopSoundMsg_ctor_cSndFxR_cGOBJP(&snd, D_004F2170, self->owner);
        snd.flag = 1;
        QueueMessage_cMessageR_cSystemP_int(&snd, g_Game, 0);
        self->fF0 = 0;
        snd.vt = D_004DADF0;
        cFileMan_dtor(&snd.s114, -1);
        cFileMan_dtor(&snd.s78, -1);
        cMessage_dtor(&snd, 0);
    }
    return cur;
}
#undef g_WeaponDatabase /* merge_units */
#undef cWeaponDB_GetEntry /* merge_units */
#undef GetMagnificationDegs /* merge_units */
#undef cMessage_dtor /* merge_units */
#undef cFileMan_dtor /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00142F20(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00142F20 */

/* merge_units: begin func_001432E0 */
#pragma push /* merge_units */
#pragma cplusplus on

/* Message destructor: payload members, then cMessage base. */
DEFINE_MESSAGE_TWO_MEMBER_DTOR(cStopSoundMsg_dtor, D_004DADF0)
#pragma pop /* merge_units */
/* merge_units: end func_001432E0 */

/* merge_units: begin func_00143370 */
#pragma push /* merge_units */
float Libc_Tanf(float);
float Libc_Atanf(float);
float GetMagnificationDegs(float arg0, float arg1) {
    float r = Libc_Tanf((0.017453292f * arg1) / 2.0f);
    r = r / arg0;
    r = 2.0f * Libc_Atanf(r); return 57.295776f * r;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00143370(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00143370 */

/* merge_units: begin func_00143400 */
#pragma push /* merge_units */
typedef struct {
    unsigned char pad[0xA0]; unsigned char busy; unsigned char pa1[8]; unsigned char idx; unsigned char paa[2];
    float level[4]; int ptr[4]; float cc[4];
} Unit_b6;
extern int cWeapon_GetClipAmmo(Unit_b6*, int);
int cWeapon_ReadyToFire(Unit_b6* s, int b)
{
    return !s->busy && s->level[s->idx] <= 0.0f && cWeapon_GetClipAmmo(s, 6) > 0 && (b || !s->ptr[s->idx]) && !s->cc[s->idx];
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00143400(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00143400 */

/* merge_units: begin func_001434D0 */
#pragma push /* merge_units */
typedef struct { int unk0; int unk4; int id; int unkC; } D6InvSlot;
int cWeapon_HasAnyWeapons(D6InvSlot* s)
{
    int i;
    for (i = 0; i < 8; i++, s++) {
        if (s->id != -1) {
            return 1;
        }
    }
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001434D0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001434D0 */
