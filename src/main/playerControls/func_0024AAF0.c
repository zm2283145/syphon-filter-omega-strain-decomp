#include "types.h"

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
extern int sprintf(char* buf, const char* fmt, ...);
extern void* func_003D1020(void);
extern int func_003D0DD0(void* font, char* text, float* color, float x, float y);

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
            func_003D0DD0(func_003D1020(), buf, color, p.v[0], y);
            y -= 20.0f;
            sprintf(buf, "SELECT");
            x1 = p.v[1];
            func_003D0DD0(func_003D1020(), buf, color, p.v[1], y);
            sprintf(buf, ": Character/camera");
            x2 = p.v[2];
            func_003D0DD0(func_003D1020(), buf, color, p.v[2], y);
            y -= 20.0f;
            if (self->mode == 1) {
                sprintf(buf, "DPAD");
                func_003D0DD0(func_003D1020(), buf, color, p.v[1], y);
                sprintf(buf, ": Horizonal movement");
                func_003D0DD0(func_003D1020(), buf, color, p.v[2], y);
            } else {
                sprintf(buf, "DPAD/LT-STICK");
                func_003D0DD0(func_003D1020(), buf, color, p.v[1], y);
                sprintf(buf, ": Horizonal movement");
                func_003D0DD0(func_003D1020(), buf, color, p.v[2], y);
            }
            y -= 20.0f;
            sprintf(buf, "R1/R2");
            func_003D0DD0(func_003D1020(), buf, color, p.v[1], y);
            sprintf(buf, ": Vertical movement");
            func_003D0DD0(func_003D1020(), buf, color, p.v[2], y);
            y -= 20.0f;
            sprintf(buf, "RIGHT-STICK");
            func_003D0DD0(func_003D1020(), buf, color, p.v[1], y);
            sprintf(buf, ": Rotation");
            func_003D0DD0(func_003D1020(), buf, color, p.v[2], y);
            if (self->mode == 1) {
                y -= 20.0f;
                sprintf(buf, "LEFT-STICK");
                func_003D0DD0(func_003D1020(), buf, color, p.v[1], y);
                sprintf(buf, ": In/out/left/right");
                func_003D0DD0(func_003D1020(), buf, color, p.v[2], y);
            }
            y -= 20.0f;
            sprintf(buf, "X\0\0\0");
            func_003D0DD0(func_003D1020(), buf, color, p.v[1], y);
            sprintf(buf, ": Teleport");
            func_003D0DD0(func_003D1020(), buf, color, p.v[2], y);
            break;
        }
        case 1: {
            DbgPos5 p = D_0048AEB0;
            float y = 200.0f;
            float x1, x2, x3, x4;
            sprintf(buf, "Camera Settings (2nd controller)");
            func_003D0DD0(func_003D1020(), buf, color, p.v[0], y);
            y -= 20.0f;
            sprintf(buf, "FOV\0");
            x1 = p.v[1];
            func_003D0DD0(func_003D1020(), buf, color, x1, y);
            sprintf(buf, ": % .2f", SoftFloat_FloatToDouble(57.295776f * (2.0f * cam->fov)));
            x2 = p.v[2];
            func_003D0DD0(func_003D1020(), buf, color, x2, y);
            sprintf(buf, "degrees");
            x3 = p.v[3];
            func_003D0DD0(func_003D1020(), buf, color, x3, y);
            sprintf(buf, "(tri/o)");
            x4 = p.v[4];
            func_003D0DD0(func_003D1020(), buf, color, x4, y);
            y -= 20.0f;
            sprintf(buf, "Height");
            func_003D0DD0(func_003D1020(), buf, color, x1, y);
            sprintf(buf, ": % .2f", SoftFloat_FloatToDouble(cam->height));
            func_003D0DD0(func_003D1020(), buf, color, x2, y);
            sprintf(buf, "feet");
            func_003D0DD0(func_003D1020(), buf, color, x3, y);
            sprintf(buf, "(dpad)");
            func_003D0DD0(func_003D1020(), buf, color, x4, y);
            y -= 20.0f;
            sprintf(buf, "Side shift");
            func_003D0DD0(func_003D1020(), buf, color, x1, y);
            { float* s = cam->side; sprintf(buf, ": % .2f", SoftFloat_FloatToDouble(*s));
            func_003D0DD0(func_003D1020(), buf, color, x2, y);
            sprintf(buf, "feet");
            func_003D0DD0(func_003D1020(), buf, color, x3, y);
            sprintf(buf, "(dpad)");
            func_003D0DD0(func_003D1020(), buf, color, x4, y);
            y -= 20.0f;
            sprintf(buf, "Distance");
            func_003D0DD0(func_003D1020(), buf, color, x1, y);
            sprintf(buf, ": % .2f", SoftFloat_FloatToDouble(-s[1])); }
            func_003D0DD0(func_003D1020(), buf, color, x2, y);
            sprintf(buf, "feet");
            func_003D0DD0(func_003D1020(), buf, color, x3, y);
            sprintf(buf, "(sqr/x)");
            func_003D0DD0(func_003D1020(), buf, color, x4, y);
            y -= 20.0f;
            sprintf(buf, "Pitch");
            func_003D0DD0(func_003D1020(), buf, color, x1, y);
            sprintf(buf, ": ? ");
            func_003D0DD0(func_003D1020(), buf, color, x2, y);
            sprintf(buf, "degrees");
            func_003D0DD0(func_003D1020(), buf, color, x3, y);
            sprintf(buf, "(right stick)");
            func_003D0DD0(func_003D1020(), buf, color, x4, y);
            y -= 20.0f;
            y -= 20.0f;
            sprintf(buf, "START to exit");
            func_003D0DD0(func_003D1020(), buf, color, p.v[0], y);
            break;
        }
        }
    }
}
