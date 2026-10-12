/*
 * Matched functions from GameGOBJ.cc (byte-identical with the retail executable).
 */

#include "gobj_types.h"

extern void Actor_BaseLogicUpdate(void* self);
extern int Object_HandleMessage(void* self, int a1);

void func_0021A920(void* self) {
    Actor_BaseLogicUpdate(self);
}

int func_0021A930(void* self, int a1) {
    return Object_HandleMessage(self, a1);
}
