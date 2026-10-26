/*
 * main/playerControls: range (3 files, 0024AAF0-0024B4D0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* library prototypes shared by the blocks below (C linkage) */
int sprintf(void *, const void *, ...);

/* merge_units: begin func_0024AAF0 */
#pragma push /* merge_units */
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
extern void* TextManager_Get(void);
extern int cTextSystem_Print_charP_tRGBAR_float_float(void* font, char* text, float* color, float x, float y);

void PlayerInput_DrawDebugCamera(DbgCamSelf* self, DbgCam* cam)
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
            cTextSystem_Print_charP_tRGBAR_float_float(TextManager_Get(), buf, color, p.v[0], y);
            y -= 20.0f;
            sprintf(buf, "SELECT");
            x1 = p.v[1];
            cTextSystem_Print_charP_tRGBAR_float_float(TextManager_Get(), buf, color, p.v[1], y);
            sprintf(buf, ": Character/camera");
            x2 = p.v[2];
            cTextSystem_Print_charP_tRGBAR_float_float(TextManager_Get(), buf, color, p.v[2], y);
            y -= 20.0f;
            if (self->mode == 1) {
                sprintf(buf, "DPAD");
                cTextSystem_Print_charP_tRGBAR_float_float(TextManager_Get(), buf, color, p.v[1], y);
                sprintf(buf, ": Horizonal movement");
                cTextSystem_Print_charP_tRGBAR_float_float(TextManager_Get(), buf, color, p.v[2], y);
            } else {
                sprintf(buf, "DPAD/LT-STICK");
                cTextSystem_Print_charP_tRGBAR_float_float(TextManager_Get(), buf, color, p.v[1], y);
                sprintf(buf, ": Horizonal movement");
                cTextSystem_Print_charP_tRGBAR_float_float(TextManager_Get(), buf, color, p.v[2], y);
            }
            y -= 20.0f;
            sprintf(buf, "R1/R2");
            cTextSystem_Print_charP_tRGBAR_float_float(TextManager_Get(), buf, color, p.v[1], y);
            sprintf(buf, ": Vertical movement");
            cTextSystem_Print_charP_tRGBAR_float_float(TextManager_Get(), buf, color, p.v[2], y);
            y -= 20.0f;
            sprintf(buf, "RIGHT-STICK");
            cTextSystem_Print_charP_tRGBAR_float_float(TextManager_Get(), buf, color, p.v[1], y);
            sprintf(buf, ": Rotation");
            cTextSystem_Print_charP_tRGBAR_float_float(TextManager_Get(), buf, color, p.v[2], y);
            if (self->mode == 1) {
                y -= 20.0f;
                sprintf(buf, "LEFT-STICK");
                cTextSystem_Print_charP_tRGBAR_float_float(TextManager_Get(), buf, color, p.v[1], y);
                sprintf(buf, ": In/out/left/right");
                cTextSystem_Print_charP_tRGBAR_float_float(TextManager_Get(), buf, color, p.v[2], y);
            }
            y -= 20.0f;
            sprintf(buf, "X\0\0\0");
            cTextSystem_Print_charP_tRGBAR_float_float(TextManager_Get(), buf, color, p.v[1], y);
            sprintf(buf, ": Teleport");
            cTextSystem_Print_charP_tRGBAR_float_float(TextManager_Get(), buf, color, p.v[2], y);
            break;
        }
        case 1: {
            DbgPos5 p = D_0048AEB0;
            float y = 200.0f;
            float x1, x2, x3, x4;
            sprintf(buf, "Camera Settings (2nd controller)");
            cTextSystem_Print_charP_tRGBAR_float_float(TextManager_Get(), buf, color, p.v[0], y);
            y -= 20.0f;
            sprintf(buf, "FOV\0");
            x1 = p.v[1];
            cTextSystem_Print_charP_tRGBAR_float_float(TextManager_Get(), buf, color, x1, y);
            sprintf(buf, ": % .2f", SoftFloat_FloatToDouble(57.295776f * (2.0f * cam->fov)));
            x2 = p.v[2];
            cTextSystem_Print_charP_tRGBAR_float_float(TextManager_Get(), buf, color, x2, y);
            sprintf(buf, "degrees");
            x3 = p.v[3];
            cTextSystem_Print_charP_tRGBAR_float_float(TextManager_Get(), buf, color, x3, y);
            sprintf(buf, "(tri/o)");
            x4 = p.v[4];
            cTextSystem_Print_charP_tRGBAR_float_float(TextManager_Get(), buf, color, x4, y);
            y -= 20.0f;
            sprintf(buf, "Height");
            cTextSystem_Print_charP_tRGBAR_float_float(TextManager_Get(), buf, color, x1, y);
            sprintf(buf, ": % .2f", SoftFloat_FloatToDouble(cam->height));
            cTextSystem_Print_charP_tRGBAR_float_float(TextManager_Get(), buf, color, x2, y);
            sprintf(buf, "feet");
            cTextSystem_Print_charP_tRGBAR_float_float(TextManager_Get(), buf, color, x3, y);
            sprintf(buf, "(dpad)");
            cTextSystem_Print_charP_tRGBAR_float_float(TextManager_Get(), buf, color, x4, y);
            y -= 20.0f;
            sprintf(buf, "Side shift");
            cTextSystem_Print_charP_tRGBAR_float_float(TextManager_Get(), buf, color, x1, y);
            { float* s = cam->side; sprintf(buf, ": % .2f", SoftFloat_FloatToDouble(*s));
            cTextSystem_Print_charP_tRGBAR_float_float(TextManager_Get(), buf, color, x2, y);
            sprintf(buf, "feet");
            cTextSystem_Print_charP_tRGBAR_float_float(TextManager_Get(), buf, color, x3, y);
            sprintf(buf, "(dpad)");
            cTextSystem_Print_charP_tRGBAR_float_float(TextManager_Get(), buf, color, x4, y);
            y -= 20.0f;
            sprintf(buf, "Distance");
            cTextSystem_Print_charP_tRGBAR_float_float(TextManager_Get(), buf, color, x1, y);
            sprintf(buf, ": % .2f", SoftFloat_FloatToDouble(-s[1])); }
            cTextSystem_Print_charP_tRGBAR_float_float(TextManager_Get(), buf, color, x2, y);
            sprintf(buf, "feet");
            cTextSystem_Print_charP_tRGBAR_float_float(TextManager_Get(), buf, color, x3, y);
            sprintf(buf, "(sqr/x)");
            cTextSystem_Print_charP_tRGBAR_float_float(TextManager_Get(), buf, color, x4, y);
            y -= 20.0f;
            sprintf(buf, "Pitch");
            cTextSystem_Print_charP_tRGBAR_float_float(TextManager_Get(), buf, color, x1, y);
            sprintf(buf, ": ? ");
            cTextSystem_Print_charP_tRGBAR_float_float(TextManager_Get(), buf, color, x2, y);
            sprintf(buf, "degrees");
            cTextSystem_Print_charP_tRGBAR_float_float(TextManager_Get(), buf, color, x3, y);
            sprintf(buf, "(right stick)");
            cTextSystem_Print_charP_tRGBAR_float_float(TextManager_Get(), buf, color, x4, y);
            y -= 20.0f;
            y -= 20.0f;
            sprintf(buf, "START to exit");
            cTextSystem_Print_charP_tRGBAR_float_float(TextManager_Get(), buf, color, p.v[0], y);
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
extern "C" void PlayerInput_ClearPendingBit11(F6Bits* s)
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
