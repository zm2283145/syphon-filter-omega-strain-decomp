#ifndef GUITEXTLISTWIDGET_TYPES_H
#define GUITEXTLISTWIDGET_TYPES_H

/* Types used by guiTextListWidget.cc. Offsets come from the matched code. */

#include "types.h"

/* One text list entry (0x14 bytes); the first 0xC bytes are a string object
 * copied by func_0013D680. */
typedef struct TextListEntry {
    char text[0xC];         /* +0x00 */
    int unk0C;              /* +0x0C */
    signed char unk10;      /* +0x10 */
    char pad11[3];
} TextListEntry;

typedef struct TextListEntryVec {
    int unk0;
    int count;
    TextListEntry* data;
} TextListEntryVec;

#endif
