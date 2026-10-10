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

typedef struct TextListWidgetChild {
    char pad00[0x10];
    unsigned char state;
} TextListWidgetChild;

typedef struct TextListWidget {
    char pad00[0x90];
    TextListEntryVec entries;       /* 0x90 count at 0x94, data at 0x98 */
    char pad9C[4];
    TextListWidgetChild* child;     /* 0xA0 */
    unsigned char state;            /* 0xA4 */
} TextListWidget;

typedef struct TextRenderStyle {
    unsigned char data[16];
} TextRenderStyle;

typedef struct TextRenderRect {
    float x;
    float y;
    float width;
    float height;
} TextRenderRect;

typedef struct TextRenderChild {
    int x;
    int y;
    int width;
    int height;
} TextRenderChild;

typedef struct TextRenderWidget {
    char pad00[0x54];
    unsigned int selected;         /* 0x54 */
    char pad58[0x38];
    TextListEntryVec entries;       /* 0x90 */
    char pad9C[4];
    TextRenderChild* child;         /* 0xA0 */
    char padA4[0xC];
    TextRenderStyle styles[3];      /* 0xB0 */
    TextRenderStyle highlight;      /* 0xE0 */
    unsigned char highlighted;     /* 0xF0 */
} TextRenderWidget;

#endif
