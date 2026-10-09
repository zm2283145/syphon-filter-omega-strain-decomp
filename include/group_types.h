#ifndef GROUP_TYPES_H
#define GROUP_TYPES_H

/*
 * cGroup: script-visible list of game objects. Layout matches PtrVec
 * (count at 0x04, element array at 0x08); see the cGroup natives.
 */

#include "types.h"

/* One script-native argument slot (4 bytes). */
typedef union GroupScriptArg {
    int i;
    float f;
    void* p;
} GroupScriptArg;

typedef struct cGroup {
    int unk0;
    int count;                  /* 0x04 number of members */
    int* members;               /* 0x08 member object pointers */
} cGroup;

#endif
