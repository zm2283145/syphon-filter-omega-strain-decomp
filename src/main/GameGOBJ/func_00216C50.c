/*
 * Matched functions from GameGOBJ.cc (byte-identical with the retail executable).
 */

#include "gobj_types.h"

/* Sets the word at +0x6C. */
void cGameGOBJ_v42(char* self, int value) {
    *(int*)(self + 0x6C) = value;
}
