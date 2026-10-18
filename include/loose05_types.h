#ifndef LOOSE05_TYPES_H
#define LOOSE05_TYPES_H

/*
 * Types for loose functions in src/main/ between 0x0042B1F0 and 0x00476970
 * (lobby, gui widgets, game screen helpers). Offsets come from the matched code;
 * unkXX fields are not understood yet.
 */

#include "types.h"

/* Base gui widget built by GuiWidget_ctor (0x48 bytes). */
typedef struct GuiWidget {
    void* vtable;                   /* 0x00 */
    int unk04;                      /* 0x04 */
    int unk08;                      /* 0x08 */
    int unk0C;                      /* 0x0C */
    int unk10;                      /* 0x10 -1 = none */
    unsigned short flags;           /* 0x14 bit1 = visible/active, bit5, bit7 set by subclasses */
    short unk16;                    /* 0x16 */
    short unk18;                    /* 0x18 */
    char pad1A[0x2];
    int unk1C;                      /* 0x1C */
    int unk20;                      /* 0x20 */
    int unk24;                      /* 0x24 */
    List children;                  /* 0x28 collection header */
    int unk34;                      /* 0x34 */
    int unk38;                      /* 0x38 */
    int unk3C;                      /* 0x3C */
    int unk40;                      /* 0x40 */
    void* self;                     /* 0x44 points back to the widget */
} GuiWidget;

/* Widget built by GuiScrollBarWidget_ctor (vtable D_004E0F40). */
typedef struct GuiWidget43BEF0 {
    GuiWidget base;                 /* 0x00 */
    char unk48;                     /* 0x48 */
    char pad49[0x3];
    int unk4C;                      /* 0x4C */
    int unk50;                      /* 0x50 */
    char unk54;                     /* 0x54 */
    char pad55[0x3];
    int unk58;                      /* 0x58 */
    int unk5C;                      /* 0x5C */
    int unk60;                      /* 0x60 default 10 */
} GuiWidget43BEF0;

/* Widget built by GuiBitmapWidget_ctor (vtable D_004E0FC0); owns a registry handle. */
typedef struct GuiWidget43CB20 {
    GuiWidget base;                 /* 0x00 */
    int handle;                     /* 0x48 -1 = none, released through D_00539248 */
    int unk4C;                      /* 0x4C */
    int unk50;                      /* 0x50 */
    int unk54;                      /* 0x54 */
    int unk58;                      /* 0x58 */
    char pad5C[0x4];
    float color[4];                 /* 0x60 RGBA, defaults to 1.0 */
    float unk70;                    /* 0x70 defaults to 1.0 */
} GuiWidget43CB20;

/* Widget built by MLTextWidget_ctor (vtable D_004E1040; its methods sit in guiMLTextWidget.cc). */
typedef struct GuiWidget43E5D0 {
    GuiWidget base;                 /* 0x00 */
    int unk48;                      /* 0x48 */
    int unk4C;                      /* 0x4C */
    float color[4];                 /* 0x50 RGBA, copied from D_004C0100..D_004C010C */
    int unk60;                      /* 0x60 */
    int unk64;                      /* 0x64 */
    int unk68;                      /* 0x68 */
    int unk6C;                      /* 0x6C */
    List lines;                     /* 0x70 collection header */
} GuiWidget43E5D0;

/* Widget built by GuiSliderWidget_Create (vtable D_004E10C0). */
typedef struct GuiWidget43F910 {
    GuiWidget base;                 /* 0x00 */
    int unk48;                      /* 0x48 defaults to 1 */
    char unk4C;                     /* 0x4C */
    char unk4D;                     /* 0x4D */
    char pad4E[0x2];
    int unk50;                      /* 0x50 */
    int unk54;                      /* 0x54 */
    int unk58;                      /* 0x58 */
    char pad5C[0x4];
    char unk60;                     /* 0x60 */
    char pad61[0x3];
    int unk64;                      /* 0x64 */
    int unk68;                      /* 0x68 */
    int unk6C;                      /* 0x6C defaults to 100 */
    int unk70;                      /* 0x70 defaults to 10 */
} GuiWidget43F910;

/* Widget built by GuiStartMenu_ctor (vtable D_004E1430, base built by GuiObjectives_ctor). */
typedef struct GuiWidget456D90 {
    void* vtable;                   /* 0x00 */
    char pad04[0x10];
    unsigned short flags;           /* 0x14 */
    char pad16[0x90 - 0x16];
    int unk90;                      /* 0x90 */
    int unk94;                      /* 0x94 */
    int unk98;                      /* 0x98 */
    int unk9C;                      /* 0x9C */
    int unkA0;                      /* 0xA0 */
    int unkA4;                      /* 0xA4 */
    int unkA8;                      /* 0xA8 */
} GuiWidget456D90;

/* Game screen sub-widget used by GuiMapScreen_Wake/GuiMapScreen_Init. */
typedef struct GuiWidget464B30 {
    GuiWidget base;                 /* 0x00 */
    int child;                      /* 0x48 child found by GuiWidget_FindChildByName */
    int unk4C;                      /* 0x4C copied from (*D_004FFC2C)->unk6A0 */
} GuiWidget464B30;

/* Global object reached through D_004FFC2C (only the field read here). */
typedef struct Global4FFC2C {
    char pad000[0x6A0];
    int unk6A0;                     /* 0x6A0 */
} Global4FFC2C;

/* Widget with a mode byte at +0x4C (GuiAutoSaver_Wake). */
typedef struct GuiWidget45F340 {
    GuiWidget base;                 /* 0x00 */
    char pad48[0x4];
    char unk4C;                     /* 0x4C */
} GuiWidget45F340;

/* The lobby array header and the SFOLobby object live in SFOLobby.h. */
#include "SFOLobby.h"
typedef LobbyArray LobbyRecord1C;


/* Object with a byte flag at +0x17C (func_0044FA40). */
typedef struct Lobby17C {
    char pad000[0x17C];
    unsigned char unk17C;           /* 0x17C */
} Lobby17C;

/* 44-byte entry of the table at *D_00587FF8; both words are text ids. */
typedef struct TextPairEntry {
    int textId0;                    /* 0x00 */
    int textId1;                    /* 0x04 */
    char pad08[0x24];
} TextPairEntry;

/* 12-byte element vector: data pointer at +8, count at +4. */
typedef struct Vec12 {
    int unk0;
    int count;                      /* 0x04 */
    char* data;                     /* 0x08 */
} Vec12;

/* Character object (only the fields touched by Ladder_ReleaseAlignment). */
typedef struct Char475BB0 {
    char pad0000[0x2ED0];
    char animChannel[1];            /* 0x2ED0 animation channel passed to AnimChannel_SetTarget */
    char pad2ED1[0x3248 - 0x2ED1];
    unsigned int flags;             /* 0x3248 */
} Char475BB0;

/* Script message object: argument word at +0x24. */
typedef struct ScriptMsg24 {
    char pad00[0x24];
    int value;                      /* 0x24 */
} ScriptMsg24;

/* cActivateBodyTossMsg (only the byte serialized by its v04 method). */
typedef struct BodyTossMsg {
    char pad00[0x24];
    unsigned char unk24;            /* 0x24 */
} BodyTossMsg;

/* Rel triple followed by an enabled flag (func_00460E90). */
typedef struct FlaggedRel {
    Rel rel;                        /* 0x00 */
    char enabled;                   /* 0x0C */
} FlaggedRel;

/* Object with a float at +0x40 (FlashGlare_GetCoronaSize). */
typedef struct Float40 {
    char pad00[0x40];
    float unk40;                    /* 0x40 */
} Float40;

/* Object whose second word is a count/flag (cleared by several small helpers). */
typedef struct Word4 {
    int unk00;
    int unk04;                      /* 0x04 */
} Word4;

/* MLTextWidget (multi-line text widget) lives in guiMLTextWidget.h. */

/* Lookup object with 256 byte-page pointers and separate inline storage. */
typedef struct Lookup43FDD0 {
    int count;                     /* 0x000 */
    char pad004[0x5C0 - 4];
    unsigned char* pages[256];      /* 0x5C0 */
} Lookup43FDD0;

#endif
