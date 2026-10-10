#include "types.h"

typedef struct Scale4 {
    float x, y, z, w;
} Scale4;

typedef struct Obj36A {
    char pad[0x10];
    Scale4 scales[8];
    unsigned char enabled;
    char pad2[0xB];
    int unk9C;
    char pad3[0x8A74 - 0xA0];
    void* vtable;
} Obj36A;

extern char D_004DF630[]; /* vtable */

/* Constructor: sets the vtable, eight (0.5, 0.5, 0.5, 1) entries, enabled = 1. */
Obj36A* func_0036AFC0(Obj36A* self) {
    int i;
    self->vtable = D_004DF630;
    for (i = 0; i < 8; i++) {
        self->scales[i].x = 0.5f;
        self->scales[i].y = 0.5f;
        self->scales[i].z = 0.5f;
        self->scales[i].w = 1.0f;
    }
    self->enabled = 1;
    self->unk9C = 0;
    return self;
}
