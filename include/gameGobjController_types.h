#ifndef GAMEGOBJCONTROLLER_TYPES_H
#define GAMEGOBJCONTROLLER_TYPES_H

/*
 * cGameGobjController / cTimerExpiredMsg types. Offsets come from the matched code.
 */

#include "types.h"

/* One script-native argument slot (4 bytes). */
typedef union GgcScriptArg {
    int i;
    float f;
    void* p;
} GgcScriptArg;

typedef struct cGameGobjController {
    char pad00[0x30];
    int gobj;                       /* 0x30 controlled game object */
} cGameGobjController;

/* Timer-expired message. */
typedef struct cTimerExpiredMsg {
    char pad00[0x24];
    int timerId;                    /* 0x24 nonzero when the timer is personal */
} cTimerExpiredMsg;

/* Base component (constructor Component_BaseInit). */
typedef struct Component {
    void* vtable;                   /* 0x00 */
    char pad04[0x34];
    float unk38;                    /* 0x38 initialised to 1.0 */
    int unk3C;                      /* 0x3C initialised to -1 */
    int unk40;                      /* 0x40 initialised to 0 */
} Component;

#endif
