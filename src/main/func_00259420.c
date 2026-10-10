#include "types.h"

typedef struct Obj68 {
    void* vtable;
    char pad[0x2B];
    unsigned char unk2F;
    char pad2[8];
    int unk38;
    char pad3[0x24];
    int unk60;
    unsigned char unk64;
} Obj68;

extern int D_004DC4A0;
extern void IdMgr_Allocate(int*, int);
extern void cGOBJ_ctor(Obj68*, int*, int, int*);

/* Constructor: base init with resource 0xF5, then sets the vtable and defaults. */
Obj68* func_00259420(Obj68* o) {
    int extra = 0;
    int res;
    IdMgr_Allocate(&res, 0xF5);
    cGOBJ_ctor(o, &res, 3, &extra);
    o->vtable = &D_004DC4A0;
    o->unk60 = 0;
    o->unk64 = 7;
    o->unk2F = 1;
    o->unk38 = 2;
    return o;
}
