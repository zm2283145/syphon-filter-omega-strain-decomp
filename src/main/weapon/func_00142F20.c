#pragma opt_dead_assignments off
#include "types.h"
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
extern int D_004FFD30;
extern unsigned char D_004EA140;
extern float D_00489CA8;
extern float D_00489CB0;
extern char D_004F2170[];
extern char D_004FFB50[];
extern char D_004DAE30[];
extern char D_004DADF0[];
Db_2F20* WeaponDb_Get(int db, int id);
int WeaponInv_GetHeldClass(void);
float func_00143370(float v, float def);
void SoundEvent_CtorFromPreset(Snd_2F20* e, void* preset, void* owner);
void func_0020EBA0(Snd2_2F20* e, void* preset, void* owner);
void Event_Send(void* msg, void* target, int immediate);
void cMessage_dtor(void* msg, int flags);
void func_0036E220(Str_2F20* s, int flag);

static inline float Clamp_2F20(float x, float lo, float hi) { float r; asm { max.s r, x, lo; min.s r, r, hi } return r; }
static inline float Abs_2F20(float x) { float r; asm { abs.s r, x } return r; }

float Weapon_GetFieldOfView(W_2F20* self, unsigned char zoom, int dir, float cur, float dt)
{
    float fov = 65.0f;
    unsigned char play = 0;
    unsigned char canZoom = 0;
    if ((unsigned char)WeaponInv_GetHeldClass() == 1)
        zoom = 0;
    if (zoom != self->fED) {
        self->fED = zoom;
        self->fEE = 1;
    }
    if (self->cur != 6) {
        int id = self->ent[self->cur].id;
        if (id != -1) {
            Db_2F20* db = WeaponDb_Get(D_004FFD30, id);
            float wide = func_00143370(db->f110, 65.0f);
            float narrow = func_00143370(db->f114, 65.0f);
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
            SoundEvent_CtorFromPreset(&snd, D_004F2170, self->owner);
            snd.flag = 1;
            Event_Send(&snd, D_004FFB50, 0);
            self->fF0 = 1;
            snd.vt = D_004DAE30;
            func_0036E220(&snd.s114, -1);
            func_0036E220(&snd.s78, -1);
            cMessage_dtor(&snd, 0);
        }
    } else if (self->fF0) {
        Snd2_2F20 snd;
        func_0020EBA0(&snd, D_004F2170, self->owner);
        snd.flag = 1;
        Event_Send(&snd, D_004FFB50, 0);
        self->fF0 = 0;
        snd.vt = D_004DADF0;
        func_0036E220(&snd.s114, -1);
        func_0036E220(&snd.s78, -1);
        cMessage_dtor(&snd, 0);
    }
    return cur;
}












