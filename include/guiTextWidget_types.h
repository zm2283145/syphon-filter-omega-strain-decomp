#ifndef GUI_TEXT_WIDGET_TYPES_H
#define GUI_TEXT_WIDGET_TYPES_H

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
