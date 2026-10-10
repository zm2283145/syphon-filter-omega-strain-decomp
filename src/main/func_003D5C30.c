/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose04_types.h"

/* Array constructor helper: (array, ctor, dtor, element size, count). */
extern void* __construct_array(void* array, void* ctor, void* dtor, int size, int count);
extern L4Elem30* func_003D5AA0(L4Elem30*, int);
L4Elem30* func_003D5CD0(L4Elem30* self);

Unk3D5C30* func_003D5C30(Unk3D5C30* self) {
    self->unk00 = 0;
    self->unk04 = 0;
    self->unk0C = -1;
    return self;
}

Unk3D5C50* func_003D5C50(Unk3D5C50* self) {
    self->unk00 = 0;
    self->unk64 = 0;
    self->unk70[0] = 0.0f;
    self->unk70[1] = 0.0f;
    self->unk70[2] = 0.0f;
    self->unk70[3] = 1.0f;
    return self;
}

Unk3D5C80* func_003D5C80(Unk3D5C80* self) {
    self->unk00 = 0;
    self->unk04 = 0;
    __construct_array(self->elems, func_003D5CD0, func_003D5AA0, sizeof(L4Elem30), 6);
    return self;
}

L4Elem30* func_003D5CD0(L4Elem30* self) {
    self->unk00 = 0;
    self->unk04 = 0;
    self->unk10[0] = 0.0f;
    self->unk10[1] = 0.0f;
    self->unk10[2] = 0.0f;
    self->unk10[3] = 1.0f;
    self->unk20[0] = 0.0f;
    self->unk20[1] = 0.0f;
    self->unk20[2] = 0.0f;
    self->unk20[3] = 0.0f;
    return self;
}
