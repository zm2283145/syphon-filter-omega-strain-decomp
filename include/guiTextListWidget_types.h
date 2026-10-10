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
    unsigned char state;           /* 0x10 */
    unsigned char pad11;
    unsigned char enabled;         /* 0x12 */
    unsigned char pad13;
    char text[0xC];                 /* 0x14 */
    char pad20[0x38];
    unsigned char active;          /* 0x58 */
    char pad59[2];
    unsigned char mode;            /* 0x5B */
    char pad5C[4];
} TextRenderChild;

typedef struct TextRenderWidget {
    void* vtable;
    char pad04[0x38];
    float width;                   /* 0x3C */
    float height;                  /* 0x40 */
    char pad44[0x10];
    unsigned int selected;         /* 0x54 */
    char pad58[8];
    char baseState[0x30];           /* 0x60 */
    TextListEntryVec entries;       /* 0x90 */
    char pad9C[4];
    TextRenderChild* child;         /* 0xA0 */
    unsigned char state;           /* 0xA4 */
    char padA5[3];
    void* resource;                /* 0xA8 */
    char padAC[4];
    TextRenderStyle styles[3];      /* 0xB0 */
    TextRenderStyle highlight;      /* 0xE0 */
    unsigned char highlighted;     /* 0xF0 */
    unsigned char mode;            /* 0xF1 */
} TextRenderWidget;

#endif
