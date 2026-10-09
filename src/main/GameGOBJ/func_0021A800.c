/*
 * Matched functions from GameGOBJ.cc (byte-identical with the retail executable).
 */

#include "gobj_types.h"

extern char D_004D9DE0[];

Rec0C* func_0021A800(Rec0C* r) {
    *(int*)&r->unk4 = -2;
    r->unk0 = 0;
    return r;
}

Rec0C* func_0021A820(Rec0C* r, int a1, int a2, int a3) {
    r->unk8 = D_004D9DE0;
    r->unk4 = a2;
    r->unk0 = a1;
    r->unk5 = a3;
    return r;
}
