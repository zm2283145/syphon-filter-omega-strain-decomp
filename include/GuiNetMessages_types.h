#ifndef GUINETMESSAGES_TYPES_H
#define GUINETMESSAGES_TYPES_H

/* Types used by GuiNetMessages.cc. Offsets come from the matched code. */

#include "types.h"

/* Net message screen (derives from the GuiLobbyScreen-unit widget built by GuiScreen_ctor). */
typedef struct GuiNetMessages {
    void* vtable;                   /* 0x00 */
    char pad04[0x80];
    int unk84;                      /* 0x84 initialized to 9 */
    int unk88;                      /* 0x88 */
    char pad8C[0x10];
    int unk9C;                      /* 0x9C initialized to -1 */
} GuiNetMessages;

#endif
