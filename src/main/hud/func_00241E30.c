#include "types.h"

typedef struct Color4 {
    float r, g, b, a;
} Color4;

typedef struct Obj6E4 {
    char pad[0x6E4];
    Color4* color;
} Obj6E4;

extern Color4 D_004F7D60;
extern Color4 D_004F7D70;
extern float D_0055A280;
extern float D_0055A284;
extern float D_0055A288;
extern float D_0055A28C;
extern void func_00260EC0(int);

/* Selects one of two color presets and publishes it to the global color. */
void func_00241E30(Obj6E4* o, int alt) {
    Color4* c;
    func_00260EC0(alt);
    o->color = alt ? &D_004F7D70 : &D_004F7D60;
    c = o->color;
    D_0055A280 = c->r;
    D_0055A284 = c->g;
    D_0055A288 = c->b;
    D_0055A28C = c->a;
}
