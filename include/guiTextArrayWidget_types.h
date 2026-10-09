#ifndef GUITEXTARRAYWIDGET_TYPES_H
#define GUITEXTARRAYWIDGET_TYPES_H

/*
 * Types used by guiTextArrayWidget.cc. Offsets come from the matched code;
 * unkXX fields are not understood yet.
 */

#include "types.h"

/* One cell/entry of the text array (returned by func_00426590). */
typedef struct TextArrayCell {
    char pad00[0xC];
    unsigned int flags;             /* 0x0C bit0/bit2 cleared by setters, bit1 = has text */
    char pad10[0x4];
    int text;                       /* 0x14 string handle from the gui string table */
} TextArrayCell;

/* Vector-like member at +0xB0 (zeroed by func_00427000) plus a flag byte. */
typedef struct TextArrayStore {
    int unk00;
    int unk04;
    int unk08;
    unsigned char unk0C;            /* +0x0C */
} TextArrayStore;

/* guiTextArrayWidget (derives from the widget built by func_00424C50). */
typedef struct guiTextArrayWidget {
    void* vtable;                   /* 0x00 */
    char pad04[0x8C];
    int unk90;                      /* 0x90 */
    int count;                      /* 0x94 */
    unsigned char unk98;            /* 0x98 */
    char pad99[0x7];
    float color[4];                 /* 0xA0 RGBA, defaults to 1.0 */
    TextArrayStore store;           /* 0xB0 */
} guiTextArrayWidget;

#endif
