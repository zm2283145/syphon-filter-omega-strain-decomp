#ifndef GUIAGENTMODIFY_TYPES_H
#define GUIAGENTMODIFY_TYPES_H

/* Types used by GuiAgentModify.cc. Offsets come from the matched code. */

#include "types.h"

/* 0x1D0-byte record stored by value in a vector. */
typedef struct AgentCreateEntry {
    char pad[0x1D0];
} AgentCreateEntry;

typedef struct AgentCreateEntryVec {
    int unk0;
    int count;
    AgentCreateEntry* data;
} AgentCreateEntryVec;

/* 12-byte record stored by value in a vector. */
typedef struct Rec12 {
    char pad[0xC];
} Rec12;

typedef struct Rec12Vec {
    int unk0;
    int count;
    Rec12* data;
} Rec12Vec;

/* Gui manager singleton (returned by func_004147A0). */
typedef struct GuiManagerState {
    char pad00[0x68];
    unsigned int flags;             /* 0x68 */
} GuiManagerState;

#endif
