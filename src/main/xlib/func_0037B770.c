#include "types.h"

typedef struct Sub10CC {
    int unk0;
    int unk4;
    int unk8;
} Sub10CC;

typedef struct Obj10CC {
    char pad[0x10CC];
    Sub10CC sub;
} Obj10CC;

typedef struct Rgba {
    int r, g, b, a;
} Rgba;

extern void XLib_FrameBuffToUserEnv(Obj10CC*, int);
extern int cUserFrameEnv_GetVramAddr(Sub10CC*);
extern int cUserFrameEnv_GetWidth(Sub10CC*);
extern int cUserFrameEnv_GetHeight(Sub10CC*);
extern void XLib_FullScreenSprite(Obj10CC*, Rgba*, int, int, int, int, int);

/* Redraws with a neutral grey (0x80) color using the sub-object's geometry. */
void XLib_ScreenBlur(Obj10CC* o) {
    Rgba color;
    Sub10CC* sub;
    int a;
    int extra;
    int b;
    sub = &o->sub;
    XLib_FrameBuffToUserEnv(o, 0);
    extra = sub->unk8;
    color.r = 0x80;
    color.g = 0x80;
    color.b = 0x80;
    color.a = 0x80;
    a = cUserFrameEnv_GetVramAddr(sub);
    b = cUserFrameEnv_GetWidth(sub);
    XLib_FullScreenSprite(o, &color, a, b, cUserFrameEnv_GetHeight(sub), extra, 0);
}
