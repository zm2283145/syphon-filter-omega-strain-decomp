#ifndef LOOSE03_TYPES_H
#define LOOSE03_TYPES_H

/*
 * Provisional types for loose functions in src/main/ (0x0032xxxx-0x003Cxxxx)
 * that are not yet assigned to a translation unit. Offsets come from matched
 * code; unkXX names are placeholders.
 */

#include "types.h"

/* Header pointed to by TexEntry.info; halfwords read by size accessors. */
typedef struct TexInfo {
    char pad00[0x4];
    unsigned short unk04;           /* 0x04 */
    unsigned short unk06;           /* 0x06 */
    char pad08[0x2];
    unsigned short unk0A;           /* 0x0A */
} TexInfo;

/* Texture entry held by the texture registry (D_00539248). */
typedef struct TexEntry {
    char pad00[0x44];
    TexInfo* info;                  /* 0x44 */
    unsigned int flags;             /* 0x48 bit 0x1000 set when info is assigned */
    char pad4C[0x4];
    char body[0x10];                /* 0x50 embedded sub-object, returned by address */
    unsigned char unk60;            /* 0x60 */
    unsigned char unk61;            /* 0x61 */
} TexEntry;

/* Texture registry: array of TexEntry pointers at +8. */
typedef struct TexRegistry {
    int unk00;
    int unk04;
    TexEntry** entries;             /* 0x08 */
} TexRegistry;

/* Generic 4-word record built by func_00379760. */
typedef struct Words4 {
    int a, b, c, d;
} Words4;

/* 2-word pair (func_0032EEC0). */
typedef struct Pair {
    int first;
    int second;
} Pair;

/* Vector of 8-byte elements (func_0032EEA0). */
typedef struct PairVec {
    int unk00;
    int count;                      /* 0x04 */
    Pair* data;                     /* 0x08 */
} PairVec;

/* Vector of 24-byte elements (func_0032E3C0). */
typedef struct Elem24 {
    char pad[0x18];
} Elem24;

typedef struct Vec24 {
    int unk00;
    int count;                      /* 0x04 */
    Elem24* data;                   /* 0x08 */
} Vec24;

/* 3x4 float matrix rows (func_00370000 copies a 3x4 into +0x10). */
typedef struct Mtx34 {
    float m[3][4];
} Mtx34;

/* Six-float record copied by func_00366950 / func_00345C80. */
typedef struct Float6 {
    float v[6];
} Float6;

/* 20-byte slot built by func_003BB340 (array of 6 inside Manager37F9D0). */
typedef struct Slot20 {
    int unk00;                      /* 0x00 = -1 */
    int unk04;                      /* 0x04 = -1 */
    int unk08;                      /* 0x08 */
    int unk0C;                      /* 0x0C */
    unsigned char unk10;            /* 0x10 */
} Slot20;

/* Object constructed by func_0037F9D0 (8 x 272-byte sub-objects at +0x1F0). */
typedef struct Manager37F9D0 {
    int unk00;                      /* 0x00 = -1 */
    char pad004[0x1EC];
    char items[8][272];             /* 0x1F0 each built by func_003755C0 */
    int current;                    /* 0xA70 index into items */
    char pad0A74[0x5E4];
    int unk1058;                    /* 0x1058 (4184) */
    int unk105C;                    /* 0x105C */
    char pad1060[0x8];
    Slot20 slots[6];                /* 0x1068 */
    char pad10E0[0x28];
    List unk1108;                   /* 0x1108 list header, initialized by func_0037FE80 */
} Manager37F9D0;

/* GUI widget base built by GuiWidget_ctor (0x48 bytes; layout copied minimally). */
typedef struct L3GuiWidget {
    void* vtable;                   /* 0x00 */
    char pad04[0x10];
    short flags;                    /* 0x14 */
    char pad16[0x32];
} L3GuiWidget;

/* GuiPersonnelScreen (vtable D_004DF0B0; class-name getter GuiPersonnelScreen_GetClassName), ctor GuiPersonnelScreen_ctor. */
typedef struct GuiPersonnelScreen {
    L3GuiWidget base;               /* 0x00 */
    int unk48;                      /* 0x48 */
    int unk4C;                      /* 0x4C */
    int unk50;                      /* 0x50 */
    int unk54;                      /* 0x54 */
    int unk58;                      /* 0x58 */
    int unk5C;                      /* 0x5C */
    int unk60;                      /* 0x60 */
    int unk64;                      /* 0x64 set per subclass (GuiRanks 6, GuiOmegaStrain 8) */
    int unk68;                      /* 0x68 = 1 */
} GuiPersonnelScreen;

/* Member at +0x70 of GuiMissionStatistics (built by func_0034FE40). */
typedef struct Member34FE40 {
    char pad00[0xC];
    unsigned char unk0C;            /* 0x0C */
    char pad0D[0x3];
} Member34FE40;

/*
 * GuiMissionStatistics (vtable D_004DEE70, class-name getter GuiMissionStatistics_GetClassName), ctor
 * GuiMissionStatistics_ctor; derives from GuiPersonnelScreen.
 * Vtable slot 13 (message handler) is func_0034FA40, overriding func_00356B30.
 */
typedef struct GuiMissionStatistics {
    GuiPersonnelScreen base;              /* 0x00 */
    int unk6C;                      /* 0x6C */
    Member34FE40 unk70;             /* 0x70 */
    int unk80;                      /* 0x80 set by message 0x3000 */
} GuiMissionStatistics;

/* GuiObjectives (vtable D_004DF5C0, class-name getter GuiObjectives_GetClassName), ctor GuiObjectives_ctor. */
typedef struct GuiObjectives {
    L3GuiWidget base;               /* 0x00 */
    char pad48[0x10];
    int unk58;                      /* 0x58 */
    int unk5C;                      /* 0x5C = -1 */
    char pad60[0x18];
    int unk78;                      /* 0x78 */
    int unk7C;                      /* 0x7C */
    char pad80[0x4];
    int unk84;                      /* 0x84 */
    unsigned char unk88;            /* 0x88 */
    unsigned char unk89;            /* 0x89 */
} GuiObjectives;

/* GuiMissionStatList: guiTextArrayWidget subclass (vtable D_004DEEE0, class-name getter GuiMissionStatList_GetClassName), ctor GuiMissionStatList_ctor. */
typedef struct GuiMissionStatList {
    L3GuiWidget base;               /* 0x00 (guiTextArrayWidget continues to 0xC0) */
    char pad48[0x10];
    unsigned char unk58;            /* 0x58 */
    char pad59[0x67];
    int unkC0;                      /* 0xC0 */
    int unkC4;                      /* 0xC4 */
    int unkC8;                      /* 0xC8 */
    int unkCC;                      /* 0xCC */
    int unkD0;                      /* 0xD0 */
    int unkD4;                      /* 0xD4 */
    int unkD8;                      /* 0xD8 */
    int unkDC;                      /* 0xDC */
    int unkE0;                      /* 0xE0 */
    int unkE4;                      /* 0xE4 */
    int unkE8;                      /* 0xE8 */
    int unkEC;                      /* 0xEC */
} GuiMissionStatList;

/* Opaque vector elements, sized from push_back index scaling. */
typedef struct Elem28 { char pad[28]; } Elem28;
typedef struct Elem36 { char pad[36]; } Elem36;
typedef struct Elem112 { char pad[112]; } Elem112;

/* Vector headers {unk00, count, data} with typed element storage. */
typedef struct Vec28 { int unk00; int count; Elem28* data; } Vec28;
typedef struct Vec36 { int unk00; int count; Elem36* data; } Vec36;
typedef struct Vec112 { int unk00; int count; Elem112* data; } Vec112;

/*
 * GUI screen base built by GuiScreen_ctor (GuiLobbyScreen.cc unit). Subclasses
 * set screenId (GuiNetMessages uses 9, GuiAgentInfo uses 8).
 */
typedef struct GuiScreenBase {
    void* vtable;                   /* 0x00 */
    char pad04[0x80];
    int screenId;                   /* 0x84 */
} GuiScreenBase;

/* 28-byte member constructed by func_0044FA00. */
typedef struct Member44FA00 {
    char pad[0x1C];
} Member44FA00;

/* Menu screen built by GuiMenuScreen_ctor (vtable D_004DE8A0); GuiMenuScreen in loose02_types.h. */
typedef struct L3GuiMenuScreen {
    GuiScreenBase base;             /* 0x00 */
    int unk88;                      /* 0x88 */
    int unk8C;                      /* 0x8C */
    char pad90[0x4];
    unsigned char unk94;            /* 0x94 */
    char pad95[0x3];
    int unk98;                      /* 0x98 */
    int unk9C;                      /* 0x9C */
    int unkA0;                      /* 0xA0 */
    int unkA4;                      /* 0xA4 */
    int unkA8;                      /* 0xA8 */
    Member44FA00 unkAC;             /* 0xAC */
    Member44FA00 unkC8;             /* 0xC8 */
    Member44FA00 unkE4;             /* 0xE4 */
    int unk100;                     /* 0x100 */
    int unk104;                     /* 0x104 */
    int unk108;                     /* 0x108 */
    int unk10C;                     /* 0x10C */
} L3GuiMenuScreen;

/* Object reached through GuiAgentInfo.unk120. */
typedef struct GuiAgentInfoTarget {
    char pad000[0x4E0];
    int unk4E0;                     /* 0x4E0 */
} GuiAgentInfoTarget;

/* Embedded member at +0x88 of GuiAgentInfo (two func_00298690 sub-objects). */
typedef struct GuiAgentInfoMember88 {
    char pad00[0x30];
    char unk30[0xC];                /* 0x30 */
    char unk3C[0xC];                /* 0x3C */
} GuiAgentInfoMember88;

/* GuiAgentInfo screen (vtable D_004DF350, class-name getter GuiAgentInfo_GetClassName), ctor GuiAgentInfo_ctor. */
typedef struct GuiAgentInfo {
    GuiScreenBase base;             /* 0x00 */
    GuiAgentInfoMember88 unk88;             /* 0x88 */
    char padD0[0x2C];
    int unkFC;                      /* 0xFC */
    char pad100[0x20];
    GuiAgentInfoTarget* unk120;        /* 0x120 */
} GuiAgentInfo;

/* Object returned by func_004147A0 (GUI manager?); unk2C->unk08 is compared to a screen. */
typedef struct Obj4147A0Inner {
    char pad00[0x8];
    GuiAgentInfo* unk08;               /* 0x08 */
} Obj4147A0Inner;

typedef struct Obj4147A0 {
    char pad00[0x2C];
    Obj4147A0Inner* unk2C;          /* 0x2C */
} Obj4147A0;

/* Object built by func_0036D630 (sub-object at +0x80 from func_00369870, FileHalPS2.cc). */
typedef struct Obj36D630 {
    char pad000[0x80];
    char unk80[0xC8];               /* 0x80 */
    int unk148;                     /* 0x148 */
    unsigned char unk14C;           /* 0x14C */
    char pad14D[0xB];
    int unk158;                     /* 0x158 */
    int unk15C;                     /* 0x15C */
    int* unk160;                    /* 0x160 word table (func_0036D520) */
    int unk164;                     /* 0x164 */
    unsigned char unk168;           /* 0x168 */
} Obj36D630;

/* Named entry built by func_0036E4B0 / func_0036E540 (follows fileman.cc). */
typedef struct NamedEntry36E4B0 {
    unsigned int flags;             /* 0x00 bit0/bit1 = kind, bit2 = optional flag */
    char name[128];                 /* 0x04 */
    char pad84[0x4];
    char unk88[0x10];               /* 0x88 built by func_003EBEF0 */
    int unk98;                      /* 0x98 */
} NamedEntry36E4B0;

/* Record cleared by func_00377C30 (11 words + flag byte). */
typedef struct Rec377C30 {
    int unk[11];                    /* 0x00..0x28 */
    unsigned char unk2C;            /* 0x2C = 1 */
} Rec377C30;

/* Object (vtable D_004DF6A0) holding a 3x4 matrix at +0x10: slot 8 (func_0036FFB0)
 * returns its address, slot 12 (func_00370000) sets it. */
typedef struct Obj370000 {
    char pad00[0x10];
    Mtx34 mtx;                      /* 0x10 */
} Obj370000;

/* Word buffer described by capacity/count/data (func_003979B0 source). */
typedef struct WordBuf {
    int capacity;                   /* 0x00 */
    int unk04;                      /* 0x04 */
    int count;                      /* 0x08 */
    int* data;                      /* 0x0C */
} WordBuf;

/* Cursor set over a WordBuf (func_003979B0). */
typedef struct WordCursor {
    int* end;                       /* 0x00 data + count */
    int* begin;                     /* 0x04 */
    int* cur;                       /* 0x08 begin + count */
    int* limit;                     /* 0x0C begin + capacity */
    char pad10[0x4];
} WordCursor;

/* Skeleton node set (SkelNodes_Construct); only the flag byte is known. */
typedef struct SkelNodes {
    char pad00[0x14];
    unsigned char unk14;            /* 0x14 */
} SkelNodes;

/* Object used by func_0037A1C0 (forwards fields 0x1C/0x20). */
typedef struct Obj37A1C0 {
    char pad00[0x1C];
    int unk1C;                      /* 0x1C */
    int unk20;                      /* 0x20 */
} Obj37A1C0;

/* 12-byte member copied by func_003527A0. */
typedef struct Member3527A0 {
    int unk00;
    int unk04;
    int unk08;
} Member3527A0;

/* Member at +4 of Rec352320. */
typedef struct Member352320 {
    Member3527A0 unk00;             /* 0x00 copied by func_003527A0 */
    unsigned char unk0C;            /* 0x0C */
} Member352320;

/* Record copied by func_00352320. */
typedef struct Rec352320 {
    int unk00;                      /* 0x00 */
    Member352320 unk04;             /* 0x04 */
} Rec352320;

/* Object with a two-entry float table indexed by unk88 (func_003751C0). */
typedef struct Obj3751A0 {
    char pad00[0x34];
    float unk34;                    /* 0x34 */
    float unk38;                    /* 0x38 */
    char pad3C[0x2C];
    float unk68[4];                 /* 0x68 */
    float unk78[4];                 /* 0x78 */
    int unk88;                      /* 0x88 index into unk68/unk78 */
} Obj3751A0;

/* Object read by the func_00372AC0 accessor group. */
typedef struct Obj372AC0 {
    char pad00[0x10];
    float unk10;                    /* 0x10 */
    float unk14;                    /* 0x14 */
    char pad18[0x6];
    signed char unk1E;              /* 0x1E */
    char pad1F[0x11];
    char unk30[0x10];               /* 0x30 returned by address */
    char unk40[0x10];               /* 0x40 returned by address */
    float unk50;                    /* 0x50 */
    float unk54;                    /* 0x54 */
} Obj372AC0;

/* GuiAchievementScreen (vtable D_004DEF90), derives from GuiPersonnelScreen. */
typedef struct GuiAchievementScreen {
    GuiPersonnelScreen base;        /* 0x00 */
    char unk6C[0x10];               /* 0x6C */
    signed char unk7C;              /* 0x7C */
} GuiAchievementScreen;

/* AnimChannel (vtable D_004DA840, see GuiAgentInfo_types.h): curve channel + wrap byte. */
typedef struct L3AnimChannel {
    void* vtable;                   /* 0x00 */
    char pad04[0x34];
    unsigned char wrap;             /* 0x38 */
} L3AnimChannel;

/* Object with a counter at +4 (func_003C01D0). */
typedef struct Counted {
    int unk00;
    int count;                      /* 0x04 */
} Counted;

/* Byte + two words, cleared by func_0034F920. */
typedef struct Rec34F920 {
    unsigned char unk00;            /* 0x00 */
    int unk04;                      /* 0x04 */
    int unk08;                      /* 0x08 */
} Rec34F920;

/* Rel (three words) followed by a flag byte set to 1 by its constructors. */
typedef struct FlaggedRel {
    Rel rel;                        /* 0x00 */
    unsigned char unk0C;            /* 0x0C */
} FlaggedRel;

#endif
