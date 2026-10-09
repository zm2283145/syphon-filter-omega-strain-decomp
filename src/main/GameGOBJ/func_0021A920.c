/*
 * Matched functions from GameGOBJ.cc (byte-identical with the retail executable).
 */

#include "gobj_types.h"

extern void Actor_BaseLogicUpdate(void* self);
extern int func_003CEA10(void* self, int a1);

void func_0021A920(void* self) {
    Actor_BaseLogicUpdate(self);
}

int func_0021A930(void* self, int a1) {
    return func_003CEA10(self, a1);
}
