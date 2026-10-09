/*
 * Matched functions (byte-identical with the retail executable).
 * Script type key accessors for Message (just before message.cc).
 */

#include "loose03_types.h"

extern int D_00543610;          /* Message script type key */

void func_003C8C40(void) {
}

int* Message_GetScriptTypeKeyPtr(void) {
    return &D_00543610;
}

int Message_GetScriptTypeKey(void) {
    return D_00543610;
}
