#ifndef GUI_TEXT_WIDGET_TYPES_H
#define GUI_TEXT_WIDGET_TYPES_H

typedef struct GuiStreamString {
    unsigned int word;
    int longLength;
    char* longData;
} GuiStreamString;

typedef struct GuiWidgetStreamRecord {
    void* vtable;                   /* 0x00 */
    GuiStreamString name;           /* 0x04 */
    int id;                         /* 0x10 */
    unsigned short flags;           /* 0x14 */
    char pad16[0x1E];
    float first;                    /* 0x34 */
    float second;                   /* 0x38 */
    float third;                    /* 0x3C */
    float fourth;                   /* 0x40 */
} GuiWidgetStreamRecord;

typedef struct GuiTextStreamRecord {
    GuiWidgetStreamRecord base;
    char pad44[0x10];
    int resource;                   /* 0x54 */
    char pad58[8];
    float first;                    /* 0x60 */
    float second;                   /* 0x64 */
    float third;                    /* 0x68 */
    float scale;                    /* 0x6C */
    int value;                      /* 0x70 */
} GuiTextStreamRecord;

typedef struct GuiTextChild58 {
    char pad00[0x58];
    unsigned char state;
} GuiTextChild58;

typedef struct GuiTextChild5B {
    char pad00[0x5B];
    unsigned char state;
} GuiTextChild5B;

typedef struct GuiTextStateOwnerD0 {
    char pad00[0x76];
    unsigned char state;
    char pad77;
    GuiTextChild5B* child;
} GuiTextStateOwnerD0;

typedef struct GuiTextStateOwnerF0 {
    char pad00[0x75];
    unsigned char state;
    char pad76[2];
    GuiTextChild58* child;
} GuiTextStateOwnerF0;

#endif
