#ifndef GUITEXTARRAYWIDGET_TYPES_H
#define GUITEXTARRAYWIDGET_TYPES_H

/*
 * Types used by guiTextArrayWidget.cc. Offsets come from the matched code;
 * unkXX fields are not understood yet.
 */

#include "types.h"

/* One cell/entry of the text array (returned by func_00426590). */
typedef struct TextArrayCell {
    char string[0xC];
    unsigned int flags;             /* 0x0C attribute/resource/color overrides */
    unsigned char attribute;       /* 0x10 valid when flags bit0 is set */
    char pad11[0x3];
    int text;                       /* 0x14 resource handle */
    char pad18[8];
    Vec4 color;                     /* 0x20 */
} TextArrayCell;

typedef struct TextArrayRow {
    int capacity;
    unsigned int count;
    TextArrayCell* data;
    unsigned char owned;
} TextArrayRow;

/* Vector-like member at +0xB0 (zeroed by func_00427000) plus a flag byte. */
typedef struct TextArrayStore {
    int unk00;
    int unk04;
    TextArrayRow** unk08;
    unsigned char unk0C;            /* +0x0C */
} TextArrayStore;

typedef struct TextArrayWidgetChild {
    char pad00[0x10];
    unsigned char state;
    unsigned char pad11;
    unsigned char enabled;
    unsigned char pad13;
    char string[0xC];
    int resource;                   /* 0x20 */
    char pad24[0x34];
    unsigned char active;          /* 0x58 */
    char pad59[7];
} TextArrayWidgetChild;

/* guiTextArrayWidget (derives from the widget built by func_00424C50). */
typedef struct guiTextArrayWidget {
    void* vtable;                   /* 0x00 */
    char pad04[0x44];
    unsigned int columns;          /* 0x48 */
    unsigned int rows;             /* 0x4C */
    char pad50[0x10];
    char baseState[0x30];           /* 0x60 */
    TextArrayWidgetChild* unk90;    /* 0x90 child widget */
    int count;                      /* 0x94 resource handle */
    unsigned char unk98;            /* 0x98 */
    char pad99[0x7];
    float color[4];                 /* 0xA0 RGBA, defaults to 1.0 */
    TextArrayStore store;           /* 0xB0 */
} guiTextArrayWidget;

#endif
