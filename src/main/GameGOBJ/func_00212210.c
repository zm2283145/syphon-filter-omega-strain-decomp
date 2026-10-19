/*
 * Matched functions from GameGOBJ.cc (byte-identical with the retail executable).
 */

#include "gobj_types.h"

extern int PathObj_CreateInfoObject(Mover* obj);

int cPathedGOBJ_v3D(Mover* obj) {
    return PathObj_CreateInfoObject(obj);
}
