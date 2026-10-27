/*
 * Matched functions from GameGOBJ.cc (byte-identical with the retail executable).
 */

#include "gobj_types.h"

extern void cGOBJ_NextFrame(void* self);
extern int cGOBJ_HandleMessage(void* self, int a1);

void cGameGOBJ_NextFrame(void* self) {
    cGOBJ_NextFrame(self);
}

int cGameGOBJ_HandleMessage(void* self, int a1) {
    return cGOBJ_HandleMessage(self, a1);
}
