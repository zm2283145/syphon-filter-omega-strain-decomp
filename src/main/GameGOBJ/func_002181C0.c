/*
 * Matched functions from GameGOBJ.cc (byte-identical with the retail executable).
 */

#include "gobj_types.h"

Elem16* func_002181C0(Elem16Vec* v, int i) {
    return &v->data[i];
}

int func_002181D0(Elem16Vec* v) {
    return v->count;
}

int* func_002181E0(PtrVec* v, int i) {
    return v->data + i;
}

int func_002181F0(PtrVec* v) {
    return v->count;
}
