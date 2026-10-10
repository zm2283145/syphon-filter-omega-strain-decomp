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

extern void func_0037BD40(Obj10CC*, int);
extern int func_003BAF20(Sub10CC*);
extern int func_003BAF90(Sub10CC*);
extern int func_003BAF60(Sub10CC*);
extern void func_0037B810(Obj10CC*, Rgba*, int, int, int, int, int);

/* Redraws with a neutral grey (0x80) color using the sub-object's geometry. */
void func_0037B770(Obj10CC* o) {
    Rgba color;
    Sub10CC* sub;
    int a;
    int extra;
    int b;
    sub = &o->sub;
    func_0037BD40(o, 0);
    extra = sub->unk8;
    color.r = 0x80;
    color.g = 0x80;
    color.b = 0x80;
    color.a = 0x80;
    a = func_003BAF20(sub);
    b = func_003BAF90(sub);
    func_0037B810(o, &color, a, b, func_003BAF60(sub), extra, 0);
}
