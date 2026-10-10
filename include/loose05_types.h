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

/* Widget built by func_0043BEF0 (vtable D_004E0F40). */
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

/* Widget built by func_0043CB20 (vtable D_004E0FC0); owns a registry handle. */
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

/* Widget built by func_0043E5D0 (vtable D_004E1040; its methods sit in guiMLTextWidget.cc). */
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

/* Widget built by func_0043F910 (vtable D_004E10C0). */
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

/* Widget built by func_00456D90 (vtable D_004E1430, base built by GuiObjectives_ctor). */
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

/* Game screen sub-widget used by func_00464B30/func_00464B70. */
typedef struct GuiWidget464B30 {
    GuiWidget base;                 /* 0x00 */
    int child;                      /* 0x48 child found by func_0041DB80 */
    int unk4C;                      /* 0x4C copied from (*D_004FFC2C)->unk6A0 */
} GuiWidget464B30;

/* Global object reached through D_004FFC2C (only the field read here). */
typedef struct Global4FFC2C {
    char pad000[0x6A0];
    int unk6A0;                     /* 0x6A0 */
} Global4FFC2C;

/* Widget with a mode byte at +0x4C (func_0045F340). */
typedef struct GuiWidget45F340 {
    GuiWidget base;                 /* 0x00 */
    char pad48[0x4];
    char unk4C;                     /* 0x4C */
} GuiWidget45F340;

/* 0x1C-byte lobby record cleared by func_0044FA00; func_00453A50 sets one up per
 * kind with func_0044F880(rec, count, grow, elemSize), so probably a pool header. */
typedef struct LobbyRecord1C {
    int unk00;                      /* 0x00 */
    int unk04;                      /* 0x04 */
    int unk08;                      /* 0x08 */
    int unk0C;                      /* 0x0C */
    int unk10;                      /* 0x10 */
    int unk14;                      /* 0x14 */
    char unk18;                     /* 0x18 */
    char unk19;                     /* 0x19 */
    char unk1A;                     /* 0x1A */
} LobbyRecord1C;

/* SFOLobby main object (partial; fields reached from the lobby reset and update helpers). */
typedef struct SFOLobby {
    char pad0000[0x70];
    LobbyRecord1C pool70;           /* 0x70 elem 276 bytes */
    char pad008C[0xC4 - 0x8C];
    LobbyRecord1C poolC4;           /* 0xC4 elem 80 bytes */
    LobbyRecord1C poolE0;           /* 0xE0 elem 80 bytes */
    LobbyRecord1C poolFC;           /* 0xFC elem 320 bytes */
    LobbyRecord1C pool118;          /* 0x118 elem 44 bytes */
    LobbyRecord1C pool134;          /* 0x134 elem 80 bytes */
    LobbyRecord1C pool150;          /* 0x150 elem 80 bytes */
    char sessionBlock[1];           /* 0x16C start of the 0x950-byte block cleared by the reset */
    char pad016D[0x174 - 0x16D];
    int rangeStart;                 /* 0x174 nonnegative lower bound */
    int rangeEnd;                   /* 0x178 at least rangeStart */
    char pad017C[0x180 - 0x17C];
    int unk180;                     /* 0x180 handle, -1 = none */
    int unk184;                     /* 0x184 */
    char pad0188[0x18C - 0x188];
    int unk18C;                     /* 0x18C */
    char pad0190[0x194 - 0x190];
    int unk194;                     /* 0x194 */
    int unk198;                     /* 0x198 */
    int unk19C;                     /* 0x19C */
    int unk1A0;                     /* 0x1A0 */
    int unk1A4;                     /* 0x1A4 */
    int unk1A8;                     /* 0x1A8 */
    int unk1AC;                     /* 0x1AC */
    int unk1B0;                     /* 0x1B0 */
    int unk1B4;                     /* 0x1B4 */
    int unk1B8;                     /* 0x1B8 */
    int unk1BC;                     /* 0x1BC */
    int unk1C0;                     /* 0x1C0 */
    int unk1C4;                     /* 0x1C4 */
    int unk1C8;                     /* 0x1C8 */
    char pad01CC[0x1D0 - 0x1CC];
    int unk1D0;                     /* 0x1D0 */
    char pad01D4[0x1F8 - 0x1D4];
    int unk1F8;                     /* 0x1F8 */
    int unk1FC;                     /* 0x1FC */
    int unk200;                     /* 0x200 */
    int unk204;                     /* 0x204 */
    int unk208;                     /* 0x208 */
    char pad020C[0x210 - 0x20C];
    int unk210;                     /* 0x210 */
    char pad0214[0x21C - 0x214];
    int unk21C;                     /* 0x21C */
    char pad0220[0x230 - 0x220];
    int unk230;                     /* 0x230 */
    char pad0234[0x26C - 0x234];
    int unk26C;                     /* 0x26C -1 = none */
    char pad0270[0x330 - 0x270];
    int unk330;                     /* 0x330 -1 = none */
    char pad0334[0xA80 - 0x334];
    int unkA80;                     /* 0xA80 -1 = none */
    char pad0A84[0xBEC - 0xA84];
    int unkBEC;                     /* 0xBEC -1 = none */
    char pad0BF0[0xC44 - 0xBF0];
    int unkC44;                     /* 0xC44 -1 = none */
    char pad0C48[0xD14 - 0xC48];
    int unkD14;                     /* 0xD14 -1 = none */
    char pad0D18[0xD3C - 0xD18];
    int unkD3C;                     /* 0xD3C -1 = none */
    char pad0D40[0xE84 - 0xD40];
    int unkE84;                     /* 0xE84 -1 = none */
    char pad0E88[0xEAC - 0xE88];
    int unkEAC;                     /* 0xEAC -1 = none */
    char pad0EB0[0x126C - 0xEB0];
    int unk126C;                    /* 0x126C -1 = none */
    char pad1270[0x13B0 - 0x1270];
    int unk13B0;                    /* 0x13B0 -1 = none */
    int unk13B4;                    /* 0x13B4 -1 = none */
    char pad13B8[0x14F8 - 0x13B8];
    int unk14F8;                    /* 0x14F8 -1 = none */
    char pad14FC[0x1E98 - 0x14FC];
    int unk1E98;                    /* 0x1E98 */
    int unk1E9C;                    /* 0x1E9C */
    char pad1EA0[0x2188 - 0x1EA0];
    int unk2188;                    /* 0x2188 */
    char unk218C;                   /* 0x218C */
    char pad218D[0x238C - 0x218D];
    short unk238C;                  /* 0x238C */
    char pad238E[0x23D5 - 0x238E];
    unsigned char unk23D5;          /* 0x23D5 */
    char pad23D6[0x2408 - 0x23D6];
    char unk2408;                   /* 0x2408 */
    unsigned char unk2409;          /* 0x2409 */
    char pad240A[0x243D - 0x240A];
    char unk243D;                   /* 0x243D */
    char pad243E[0x2480 - 0x243E];
    int unk2480;                    /* 0x2480 -1 = none */
    int unk2484;                    /* 0x2484 -1 = none */
    char pad2488[0x255C - 0x2488];
    int unk255C;                    /* 0x255C mode; 4 enables the per-frame update in func_00442700 */
    char pad2560[0x2578 - 0x2560];
    int unk2578;                    /* 0x2578 */
    char pad257C[0x2660 - 0x257C];
    int unk2660;                    /* 0x2660 */
} SFOLobby;


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

/* Character object (only the fields touched by func_00475BB0). */
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

/* Object with a float at +0x40 (func_0045BBE0). */
typedef struct Float40 {
    char pad00[0x40];
    float unk40;                    /* 0x40 */
} Float40;

/* Object whose second word is a count/flag (cleared by several small helpers). */
typedef struct Word4 {
    int unk00;
    int unk04;                      /* 0x04 */
} Word4;

#endif
