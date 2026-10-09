#ifndef GUIMISSIONLIST_TYPES_H
#define GUIMISSIONLIST_TYPES_H

/* Types used by GuiMissionList.cc. Offsets come from the matched code. */

#include "types.h"

typedef struct GuiMissionList {
    char pad00[0xC0];
    int unkC0;                      /* 0xC0 */
    int unkC4;                      /* 0xC4 */
    char padC8[0x4];
    int unkCC;                      /* 0xCC */
    char padD0[0x4C];
    int unk11C;                     /* 0x11C */
} GuiMissionList;

#endif
