/*
 * guiMLTextWidget.cc: multi-line, word-wrapped text widget with an optional
 * scroll bar child. Constructor: MLTextWidget_ctor (which still uses the
 * equivalent GuiWidget43E5D0 view from loose05_types.h); vtable D_004E1040.
 */
#ifndef GUIMLTEXTWIDGET_H
#define GUIMLTEXTWIDGET_H

struct GuiWidget43BEF0; /* scroll bar widget (loose05_types.h) */

/* First byte of a line may be a colour code: 0x10 + colour index (0..7). */
#define MLTEXT_COLOR_CODE_FIRST 0x10
#define MLTEXT_COLOR_CODE_END   0x18

typedef struct GuiColor {
    float r, g, b, a;
} GuiColor;

/* Node of the widget's list of wrapped lines (text is Mem_Alloc'ed). */
typedef struct MLTextLine {
    struct MLTextLine* prev;       /* 0x00 */
    struct MLTextLine* next;       /* 0x04 */
    char* text;                    /* 0x08 */
} MLTextLine;

/* List of lines; the sentinel node {prev, next} starts at +4. */
typedef struct MLTextLineList {
    int count;                     /* 0x00 */
    MLTextLine* last;              /* 0x04 sentinel.prev */
    MLTextLine* first;             /* 0x08 sentinel.next */
} MLTextLineList;

/* Text box owned by the widget (0x60 bytes, built by TextObj_Construct). */
typedef struct GuiTextBox {
    char pad00[0x10];
    unsigned char unk10;           /* 0x10 cleared by MLTextWidget_Setup */
    char pad11[3];
    char text[0xC];                /* 0x14 String (sso_string.h), dtor String_Dtor */
    void* font;                    /* 0x20 */
    char pad24[0x58 - 0x24];
    unsigned char unk58;           /* 0x58 set by MLTextWidget_Setup */
    char pad59[0x60 - 0x59];
} GuiTextBox;

typedef struct MLTextWidget {
    char base[0x3C];               /* 0x00 GuiWidget (vtable at 0x00) */
    float width;                   /* 0x3C */
    float height;                  /* 0x40 */
    char pad44[4];
    GuiTextBox* textBox;           /* 0x48 */
    void* font;                    /* 0x4C from GuiFont_Find(Gui_GetScreenList(), name) */
    GuiColor color;                /* 0x50 */
    int maxLines;                  /* 0x60 oldest lines are dropped beyond this (0 = no limit) */
    int visibleLines;              /* 0x64 height / line height */
    int scrollPos;                 /* 0x68 first visible line */
    int colorIndex;                /* 0x6C colour code in effect at the end of the text */
    MLTextLineList lines;          /* 0x70 */
    struct GuiWidget43BEF0* scrollBar; /* 0x7C optional child widget */
} MLTextWidget;

#endif /* GUIMLTEXTWIDGET_H */
