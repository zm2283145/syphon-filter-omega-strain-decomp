/*
 * Matched functions from GameGOBJ.cc (byte-identical with the retail executable).
 */

#include "gobj_types.h"

extern int cPathedGOBJ_CreatePathedGobjInfo(Mover* obj);

int cPathedGOBJ_InitNetwork(Mover* obj) {
    return cPathedGOBJ_CreatePathedGobjInfo(obj);
}
