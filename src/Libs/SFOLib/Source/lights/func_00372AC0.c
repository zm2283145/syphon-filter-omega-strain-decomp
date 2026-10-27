/*
 * Matched functions (byte-identical with the retail executable).
 * Field accessors of Obj372AC0.
 */

#include "loose03_types.h"

float cSceneLight_GetFalloffAngleCos(Obj372AC0* self) {
    return self->unk50;
}

void* cSceneLight_GetDirection(Obj372AC0* self) {
    return self->unk40;
}

float func_00372AE0(Obj372AC0* self) {
    return self->unk54;
}

float func_00372AF0(Obj372AC0* self) {
    return self->unk14;
}

float func_00372B00(Obj372AC0* self) {
    return self->unk10;
}

void* cLightSrc_GetPosition(Obj372AC0* self) {
    return self->unk30;
}

void* cParallelLight_GetDirection(Obj372AC0* self) {
    return self->unk40;
}

signed char func_00372B30(Obj372AC0* self) {
    return self->unk1E;
}
