#ifndef SCRIPTBASE_TYPES_H
#define SCRIPTBASE_TYPES_H

/*
 * Types used by the script base containers (scriptBase).
 * Offsets come from the matched code. Fields named unkXX are not understood yet.
 */

#include "types.h"

/* PtrVec followed by a flag byte. */
typedef struct OwnedVec {
    int unk0;
    int count;
    int* data;
    char unk0C;                     /* 0x0C set to 1 after init */
} OwnedVec;

/* Registered script object type (ids start at 100 in the type table D_00554F28). */
typedef struct ScriptType {
    char pad00[0x40];
    int unk40;                      /* 0x40 set by ScriptType_SetParent (native type key) */
} ScriptType;

#endif
