/*
 * SFOGame/Source/playerControls: 6 files, 0024A850-0024B580
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0024A850 */
#pragma push /* merge_units */
#include "types.h"
#include "prio_bitset.h"
PB_DEFINE(PS_24A850, 1)
typedef struct { char pad[0x30]; int x30; int x34; int x38; int x3C; PS_24A850 ps; } O_24A850;
typedef struct { char pad[0x2E00]; unsigned char state; } X_24A850;
extern int cSplinedMotion_cQuaternion_IsTransitionInProgress(void* y);
extern void cPlayerControls_NetDisableManualAim(O_24A850* o, X_24A850* x);
extern unsigned char g_IsMultiplayer;
#pragma opt_rotateloops off
void cPlayerControls_HandleManualAimButtonPress(O_24A850* o, X_24A850* x, void* y, float val)
{
    int i;
    if (o->x38 == 8 && !cSplinedMotion_cQuaternion_IsTransitionInProgress(y)) x->state = 2;
    if (val &&  !((o->x3C >> 11) & 1)) {
        PS_24A850_Set(&o->ps, 8);
        PB_FIND_TOP(PS_24A850, (&o->ps), i, 12)
    } else {
        PS_24A850_Clr(&o->ps, 8);
        PB_FIND_TOP(PS_24A850, (&o->ps), i, 12)
    }
    {
        int c = o->x30 == 8 && !(o->x38 == 8);
        if (c) {
            x->state = 0;
            if (g_IsMultiplayer) cPlayerControls_NetDisableManualAim(o, x);
        }
    }
}
#pragma opt_rotateloops reset
static inline void merge_flush_func_0024A850(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0024A850 */

/* merge_units: begin func_0024AA70 */
#pragma push /* merge_units */
typedef struct Msg {
    void* vtable;
    char base[0x20];
    int value;              /* 0x24 */
    unsigned char flag;     /* 0x28 */
    char pad[7];
} Msg;
typedef struct { char pad[0x3524]; void* owner; } Player;
extern char g_ActorActionMsgClass[];
extern char D_004E0840[];
extern int cWeapon_CanReload(void* owner);
extern void cMessage_ctor_cMessageNameR(Msg* msg, void* name);
extern void QueueMessage_cMessageR_cSystemP_int(Msg* msg, void* target, int flags);
extern void cMessage_dtor(Msg* msg, int flags);
/* When enabled and the owner is valid, sends the player a timed message (60). */
void cPlayerControls_HandleReloadButtonPress(void* self, int enable, Player* p)
{
    Msg msg;
    if (enable && cWeapon_CanReload(p->owner)) {
        cMessage_ctor_cMessageNameR(&msg, g_ActorActionMsgClass);
        msg.vtable = D_004E0840;
        msg.value = 0x3C;
        msg.flag = 0;
        QueueMessage_cMessageR_cSystemP_int(&msg, p, 0);
        msg.vtable = D_004E0840;
        cMessage_dtor(&msg, 0);
    }
}
static inline void merge_flush_func_0024AA70(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0024AA70 */

/* merge_units: begin func_0024AAF0 */
#pragma push /* merge_units */
/* library prototypes shared by the blocks below (C linkage) */
int sprintf(void *, const void *, ...);

typedef struct DbgCamSelf {
    char pad0[0xC];
    unsigned char enabled;      /* 0x0C */
    char padD[0x50 - 0xD];
    int mode;                   /* 0x50 */
    char pad54[0x139 - 0x54];
    unsigned char page;         /* 0x139 */
} DbgCamSelf;

typedef struct DbgCam {
    char pad0[0x60];
    float fov;                  /* 0x60 */
    char pad64[0x930 - 0x64];
    float side[2];              /* 0x930 */
    char pad938[0xB08 - 0x938];
    float height;               /* 0xB08 */
} DbgCam;

long long SoftFloat_FloatToDouble(float f);
typedef struct { float v[3]; } DbgPos3;
typedef struct { float v[5]; } DbgPos5;
extern DbgPos3 D_0048AEA0;
extern DbgPos5 D_0048AEB0;
extern void* GetTextSystem(void);
extern int cTextSystem_Print_charP_tRGBAR_float_float(void* font, char* text, float* color, float x, float y);

void cPlayerControls_PrintDebugInfoToScreen(DbgCamSelf* self, DbgCam* cam)
{
    float color[4];
    char buf[1008];

    if (self->enabled) {
        color[2] = 0.0f;
        color[0] = 1.0f;
        color[1] = 1.0f;
        color[3] = 1.0f;
        switch (self->page) {
        case 0: {
            DbgPos3 p = D_0048AEA0;
            float y = 210.0f;
            float x1, x2;
            if (self->mode == 1) {
                sprintf(buf, "CAMERA Movement (2nd controller):");
            } else {
                sprintf(buf, "CHARACTER Movement (2nd controller):");
            }
            cTextSystem_Print_charP_tRGBAR_float_float(GetTextSystem(), buf, color, p.v[0], y);
            y -= 20.0f;
            sprintf(buf, "SELECT");
            x1 = p.v[1];
            cTextSystem_Print_charP_tRGBAR_float_float(GetTextSystem(), buf, color, p.v[1], y);
            sprintf(buf, ": Character/camera");
            x2 = p.v[2];
            cTextSystem_Print_charP_tRGBAR_float_float(GetTextSystem(), buf, color, p.v[2], y);
            y -= 20.0f;
            if (self->mode == 1) {
                sprintf(buf, "DPAD");
                cTextSystem_Print_charP_tRGBAR_float_float(GetTextSystem(), buf, color, p.v[1], y);
                sprintf(buf, ": Horizonal movement");
                cTextSystem_Print_charP_tRGBAR_float_float(GetTextSystem(), buf, color, p.v[2], y);
            } else {
                sprintf(buf, "DPAD/LT-STICK");
                cTextSystem_Print_charP_tRGBAR_float_float(GetTextSystem(), buf, color, p.v[1], y);
                sprintf(buf, ": Horizonal movement");
                cTextSystem_Print_charP_tRGBAR_float_float(GetTextSystem(), buf, color, p.v[2], y);
            }
            y -= 20.0f;
            sprintf(buf, "R1/R2");
            cTextSystem_Print_charP_tRGBAR_float_float(GetTextSystem(), buf, color, p.v[1], y);
            sprintf(buf, ": Vertical movement");
            cTextSystem_Print_charP_tRGBAR_float_float(GetTextSystem(), buf, color, p.v[2], y);
            y -= 20.0f;
            sprintf(buf, "RIGHT-STICK");
            cTextSystem_Print_charP_tRGBAR_float_float(GetTextSystem(), buf, color, p.v[1], y);
            sprintf(buf, ": Rotation");
            cTextSystem_Print_charP_tRGBAR_float_float(GetTextSystem(), buf, color, p.v[2], y);
            if (self->mode == 1) {
                y -= 20.0f;
                sprintf(buf, "LEFT-STICK");
                cTextSystem_Print_charP_tRGBAR_float_float(GetTextSystem(), buf, color, p.v[1], y);
                sprintf(buf, ": In/out/left/right");
                cTextSystem_Print_charP_tRGBAR_float_float(GetTextSystem(), buf, color, p.v[2], y);
            }
            y -= 20.0f;
            sprintf(buf, "X\0\0\0");
            cTextSystem_Print_charP_tRGBAR_float_float(GetTextSystem(), buf, color, p.v[1], y);
            sprintf(buf, ": Teleport");
            cTextSystem_Print_charP_tRGBAR_float_float(GetTextSystem(), buf, color, p.v[2], y);
            break;
        }
        case 1: {
            DbgPos5 p = D_0048AEB0;
            float y = 200.0f;
            float x1, x2, x3, x4;
            sprintf(buf, "Camera Settings (2nd controller)");
            cTextSystem_Print_charP_tRGBAR_float_float(GetTextSystem(), buf, color, p.v[0], y);
            y -= 20.0f;
            sprintf(buf, "FOV\0");
            x1 = p.v[1];
            cTextSystem_Print_charP_tRGBAR_float_float(GetTextSystem(), buf, color, x1, y);
            sprintf(buf, ": % .2f", SoftFloat_FloatToDouble(57.295776f * (2.0f * cam->fov)));
            x2 = p.v[2];
            cTextSystem_Print_charP_tRGBAR_float_float(GetTextSystem(), buf, color, x2, y);
            sprintf(buf, "degrees");
            x3 = p.v[3];
            cTextSystem_Print_charP_tRGBAR_float_float(GetTextSystem(), buf, color, x3, y);
            sprintf(buf, "(tri/o)");
            x4 = p.v[4];
            cTextSystem_Print_charP_tRGBAR_float_float(GetTextSystem(), buf, color, x4, y);
            y -= 20.0f;
            sprintf(buf, "Height");
            cTextSystem_Print_charP_tRGBAR_float_float(GetTextSystem(), buf, color, x1, y);
            sprintf(buf, ": % .2f", SoftFloat_FloatToDouble(cam->height));
            cTextSystem_Print_charP_tRGBAR_float_float(GetTextSystem(), buf, color, x2, y);
            sprintf(buf, "feet");
            cTextSystem_Print_charP_tRGBAR_float_float(GetTextSystem(), buf, color, x3, y);
            sprintf(buf, "(dpad)");
            cTextSystem_Print_charP_tRGBAR_float_float(GetTextSystem(), buf, color, x4, y);
            y -= 20.0f;
            sprintf(buf, "Side shift");
            cTextSystem_Print_charP_tRGBAR_float_float(GetTextSystem(), buf, color, x1, y);
            { float* s = cam->side; sprintf(buf, ": % .2f", SoftFloat_FloatToDouble(*s));
            cTextSystem_Print_charP_tRGBAR_float_float(GetTextSystem(), buf, color, x2, y);
            sprintf(buf, "feet");
            cTextSystem_Print_charP_tRGBAR_float_float(GetTextSystem(), buf, color, x3, y);
            sprintf(buf, "(dpad)");
            cTextSystem_Print_charP_tRGBAR_float_float(GetTextSystem(), buf, color, x4, y);
            y -= 20.0f;
            sprintf(buf, "Distance");
            cTextSystem_Print_charP_tRGBAR_float_float(GetTextSystem(), buf, color, x1, y);
            sprintf(buf, ": % .2f", SoftFloat_FloatToDouble(-s[1])); }
            cTextSystem_Print_charP_tRGBAR_float_float(GetTextSystem(), buf, color, x2, y);
            sprintf(buf, "feet");
            cTextSystem_Print_charP_tRGBAR_float_float(GetTextSystem(), buf, color, x3, y);
            sprintf(buf, "(sqr/x)");
            cTextSystem_Print_charP_tRGBAR_float_float(GetTextSystem(), buf, color, x4, y);
            y -= 20.0f;
            sprintf(buf, "Pitch");
            cTextSystem_Print_charP_tRGBAR_float_float(GetTextSystem(), buf, color, x1, y);
            sprintf(buf, ": ? ");
            cTextSystem_Print_charP_tRGBAR_float_float(GetTextSystem(), buf, color, x2, y);
            sprintf(buf, "degrees");
            cTextSystem_Print_charP_tRGBAR_float_float(GetTextSystem(), buf, color, x3, y);
            sprintf(buf, "(right stick)");
            cTextSystem_Print_charP_tRGBAR_float_float(GetTextSystem(), buf, color, x4, y);
            y -= 20.0f;
            y -= 20.0f;
            sprintf(buf, "START to exit");
            cTextSystem_Print_charP_tRGBAR_float_float(GetTextSystem(), buf, color, p.v[0], y);
            break;
        }
        }
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0024AAF0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0024AAF0 */

/* merge_units: begin func_0024B410 */
#pragma push /* merge_units */
#pragma cplusplus on
typedef struct { char pad[0x40]; int cur; int bits[54]; int x11C; int x120; } F6Bits;
static inline bool F6Test(F6Bits* s, int i) { return ((s->bits[i / 32] >> (i & 31)) & 1) ? true : false; }
extern "C" void cPlayerControls_HandleRespawn(F6Bits* s)
{
    int i;
    s->bits[0] &= ~0x800;
    for (i = 11; i >= 0 && !F6Test(s, i); i--) {
    }
    if (!F6Test(s, i)) {
        s->cur = -1;
    } else {
        s->cur = i;
    }
    s->x11C = 0;
    s->x120 = 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0024B410(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0024B410 */

/* merge_units: begin func_0024B4D0 */
#pragma push /* merge_units */
#pragma cplusplus on

extern "C" void cPlayerControls_HandleDeath(F6Bits* s)
{
    int i;
    s->bits[0] |= 0x800;
    for (i = 11; i >= 0 && !F6Test(s, i); i--) {
    }
    if (!F6Test(s, i)) {
        s->cur = -1;
    } else {
        s->cur = i;
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0024B4D0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0024B4D0 */

/* merge_units: begin func_0024B580 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Player input-state helpers and small value types used by the input code.
 */

#include "playerControls_types.h"

extern int cPlayerControls_ExitCrawl_cGOBJP(InputState* self, int a1);
extern int cPlayerControls_StayInCrawl(InputState* self, int a1);

void cPlayerControls_HandleExitJumpBox(InputState* self) {
    self->unk26 = 0;
}

void cPlayerControls_HandleEnterJumpBox(InputState* self, int unk27, int* unk28) {
    self->unk26 = 1;
    self->unk27 = unk27;
    self->unk28 = *unk28;
}

/* Leaving a code-9 (crouch) zone. */
int cPlayerControls_HandleExitCrawlBox(InputState* self, int a1) {
    self->crouchZone = 0;
    return cPlayerControls_ExitCrawl_cGOBJP(self, a1);
}

/* Entering a code-9 (crouch) zone. */
int cPlayerControls_HandleEnterCrawlBox(InputState* self, int a1) {
    self->crouchZone = 1;
    return cPlayerControls_StayInCrawl(self, a1);
}
static inline void merge_flush_func_0024B580(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0024B580 */
