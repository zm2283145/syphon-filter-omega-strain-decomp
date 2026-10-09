#ifndef LOOSE04_TYPES_H
#define LOOSE04_TYPES_H

/*
 * Provisional types for loose functions directly under src/main/ (batch loose_04).
 * Field names are placeholders (unkXX) unless a function name or the research
 * notes justify more. Offsets come from the matched code.
 */

#include "types.h"

/* 12-byte collection header initialized by ScalarCollection_Init. */
typedef struct L4ScalarCollection {
    int unk00;
    int unk04;
    int unk08;
} L4ScalarCollection;

/*
 * GUI widget base (constructor GuiWidget_ctor, >= 0x48 bytes). The constructor
 * bumps a global instance counter and points unk44 at the object itself.
 */
typedef struct GuiWidget {
    void* vtable;                  /* 0x00 */
    int unk04;                     /* 0x04 */
    int unk08;                     /* 0x08 */
    int unk0C;                     /* 0x0C */
    int unk10;                     /* 0x10: -1 after construction */
    unsigned short flags;          /* 0x14: 0x26 after construction */
    short unk16;                   /* 0x16 */
    short unk18;                   /* 0x18 */
    char pad1A[2];
    struct GuiWidget* parent;      /* 0x1C: set when added as a child (GuiWidget_AddChild) */
    int unk20;                     /* 0x20 */
    int unk24;                     /* 0x24 */
    L4ScalarCollection children;   /* 0x28: child widgets (GuiWidget_AddChild) */
    int unk34;                     /* 0x34 */
    int unk38;                     /* 0x38 */
    int unk3C;                     /* 0x3C */
    int unk40;                     /* 0x40 */
    struct GuiWidget* self;        /* 0x44 */
} GuiWidget;

/* Widget subclass built by func_004160A0 (>= 0x6C bytes). */
typedef struct GuiWidget4160A0 {
    GuiWidget base;                /* 0x00 */
    int unk48;                     /* 0x48 */
    int unk4C;                     /* 0x4C */
    char unk50;                    /* 0x50 */
    char unk51;                    /* 0x51 */
    char unk52;                    /* 0x52 */
    char pad53;
    L4ScalarCollection unk54;      /* 0x54 */
    char unk60;                    /* 0x60 */
    char pad61[3];
    int unk64;                     /* 0x64 */
    int unk68;                     /* 0x68: 0xF000 after construction */
} GuiWidget4160A0;

/* Vector header plus owns-storage flag; initialized by func_001C10A0 and func_003EBEF0. */
typedef struct L4OwnedVec {
    PtrVec vec;                    /* 0x00 */
    char owned;                    /* 0x0C */
    char pad0D[3];
} L4OwnedVec;

/* Widget subclass built by func_00424C50 (>= 0x90 bytes). */
typedef struct GuiWidget424C50 {
    GuiWidget base;                /* 0x00 */
    int unk48;                     /* 0x48 */
    int unk4C;                     /* 0x4C */
    int unk50;                     /* 0x50 */
    int unk54;                     /* 0x54 */
    char unk58;                    /* 0x58 */
    char pad59[3];
    int unk5C;                     /* 0x5C: 24 after construction */
    L4OwnedVec unk60;              /* 0x60 */
    int unk70;                     /* 0x70: copies of 0x48..0x54 */
    int unk74;                     /* 0x74 */
    int unk78;                     /* 0x78 */
    int unk7C;                     /* 0x7C */
    char unk80;                    /* 0x80 */
    char unk81;                    /* 0x81 */
    char unk82;                    /* 0x82 */
    char pad83;
    int unk84;                     /* 0x84 */
    int unk88;                     /* 0x88 */
    int unk8C;                     /* 0x8C */
} GuiWidget424C50;

/*
 * Object built by func_003F9380 (>= 0x237 bytes). Two sub-objects at 0x6C and
 * 0x190 are initialized by func_0036E5D0; the one at 0x190 is then filled from
 * the constructor's source record by func_0036DFB0.
 */
typedef struct Unk3F9380 {
    int unk00[20];                 /* 0x00 */
    char pad50[0x1C];
    char unk6C[0x11C];             /* 0x6C: func_0036E5D0 object */
    int unk188;                    /* 0x188 */
    int unk18C;                    /* 0x18C */
    char unk190[0x9C];             /* 0x190: func_0036E5D0 object */
    int unk22C;                    /* 0x22C */
    char unk230;                   /* 0x230 */
    char unk231;                   /* 0x231 */
    char unk232;                   /* 0x232 */
    char unk233;                   /* 0x233 */
    char unk234;                   /* 0x234 */
    char unk235;                   /* 0x235 */
    char unk236;                   /* 0x236 */
} Unk3F9380;

/* 0x110-byte entry of Unk3D3670 (set up by func_003D3620). */
typedef struct L4Entry110 {
    Vec4 unk00;                    /* 0x00 */
    char pad10[0xF5];
    char unk105;                   /* 0x105 */
    char unk106;                   /* 0x106: 1 = in use */
    char pad107[9];
} L4Entry110;

/* Owner of eight L4Entry110 records (used by func_003D3670/func_003D3690). */
typedef struct Unk3D3670 {
    char pad00[0xF4];
    int unkF4;                     /* 0xF4 */
    char padF8[0xF8];
    L4Entry110 entries[8];         /* 0x1F0 */
    int cur;                       /* 0xA70: index of the current entry */
    char padA74[0x520];
    float unkF94;                  /* 0xF94 */
} Unk3D3670;

/* Small record read by the func_003D36D0..func_003D36F0 accessors. */
typedef struct Unk3D36D0 {
    char pad00[8];
    int unk08;                     /* 0x08 */
    int unk0C;                     /* 0x0C */
    unsigned char unk10;           /* 0x10 */
} Unk3D36D0;

/* Small record built by func_003D5C30 (>= 0x0E bytes). */
typedef struct Unk3D5C30 {
    int unk00;                     /* 0x00 */
    int unk04;                     /* 0x04 */
    char pad08[4];
    short unk0C;                   /* 0x0C: -1 after construction */
} Unk3D5C30;

/* Record built by func_003D5C50 (>= 0x80 bytes); 0x70 holds an identity quaternion. */
typedef struct Unk3D5C50 {
    int unk00;                     /* 0x00 */
    char pad04[0x60];
    int unk64;                     /* 0x64 */
    char pad68[8];
    float unk70[4];                /* 0x70: (0, 0, 0, 1) after construction */
} Unk3D5C50;

/* 0x30-byte element built by func_003D5CD0 and destroyed by func_003D5AA0. */
typedef struct L4Elem30 {
    char unk00;                    /* 0x00 */
    char pad01[3];
    int unk04;                     /* 0x04 */
    char pad08[8];
    float unk10[4];                /* 0x10: (0, 0, 0, 1) after construction */
    float unk20[4];                /* 0x20: zero after construction */
} L4Elem30;

/* Record built by func_003D5C80: two words plus six L4Elem30 (0x130 bytes). */
typedef struct Unk3D5C80 {
    int unk00;                     /* 0x00 */
    int unk04;                     /* 0x04 */
    char pad08[8];
    L4Elem30 elems[6];             /* 0x10 */
} Unk3D5C80;

/* Damage message (fields read by the Script_cDamageMsg_* natives). */
typedef struct cDamageMsg {
    char pad00[0x24];
    float damage;                  /* 0x24 */
    int attacker;                  /* 0x28: object handle */
    unsigned char type;            /* 0x2C */
    unsigned char where;           /* 0x2D */
} cDamageMsg;

/* One script-native argument slot (4 bytes). */
typedef union L4ScriptArg {
    int i;
    float f;
    void* p;
    signed char c;
} L4ScriptArg;

/* Record built by func_00409750 (>= 0x35 bytes). */
typedef struct Unk409750 {
    int unk00;                     /* 0x00 */
    int unk04;                     /* 0x04 */
    int unk08;                     /* 0x08 */
    int unk0C;                     /* 0x0C: -1 after construction */
    int unk10;                     /* 0x10: -1 after construction */
    int unk14;                     /* 0x14 */
    int unk18;                     /* 0x18 */
    int unk1C;                     /* 0x1C */
    int unk20;                     /* 0x20 */
    int unk24;                     /* 0x24 */
    int unk28;                     /* 0x28 */
    int unk2C;                     /* 0x2C: -1 after construction */
    float unk30;                   /* 0x30: 0.2 after construction */
    char unk34;                    /* 0x34 */
} Unk409750;

/* Object with the getters/setters at func_00423540..func_004235B0. */
typedef struct Unk423540 {
    char pad00[0x70];
    int unk70;                     /* 0x70 */
    int unk74;                     /* 0x74 */
    int unk78;                     /* 0x78 */
    int unk7C;                     /* 0x7C */
    char pad80[4];
    int unk84;                     /* 0x84 */
} Unk423540;

/* Object used by func_003E96F0..func_003E97B0 (>= 0x85 bytes). */
typedef struct Unk3E96F0 {
    char pad00[0x60];
    int unk60;                     /* 0x60: handle passed to func_003F44E0/func_003F45A0 */
    char unk64;                    /* 0x64 */
    char pad65[3];
    int unk68;                     /* 0x68 */
    char pad6C[4];
    char unk70[0x10];              /* 0x70: sub-object updated by func_003E9A60 */
    int unk80;                     /* 0x80 */
    char unk84;                    /* 0x84 */
} Unk3E96F0;

/* Node of the ordered containers handled by List_InsertBefore: +4 links to the next node, +8 is the value. */
typedef struct L4Node {
    struct L4Node* unk00;          /* 0x00 */
    struct L4Node* next;           /* 0x04 */
    int value;                     /* 0x08 */
} L4Node;

/* Iterator holding one node pointer. */
typedef struct L4Iter {
    L4Node* node;
} L4Iter;

/* Message built by func_003E43D0 / func_003E4940 (vtable D_004E0840, >= 0x29 bytes). */
typedef struct Msg3E43D0 {
    void* vtable;                  /* 0x00 */
    char pad04[0x20];
    int unk24;                     /* 0x24 */
    char unk28;                    /* 0x28 */
} Msg3E43D0;

/* Source record for func_003E43D0. */
typedef struct Msg3E43D0Src {
    char pad00[8];
    unsigned char unk08;           /* 0x08 */
    unsigned char unk09;           /* 0x09 */
} Msg3E43D0Src;

/* Widget-like object built by func_0041ADC0 on top of func_0041C7D0 (>= 0x90 bytes). */
typedef struct Unk41ADC0 {
    void* vtable;                  /* 0x00 */
    char pad04[0x10];
    unsigned short flags;          /* 0x14 */
    char pad16[0x6A];
    char unk80;                    /* 0x80 */
    char pad81[3];
    int unk84;                     /* 0x84: 100 after construction */
    char unk88;                    /* 0x88 */
    char pad89[3];
    int unk8C;                     /* 0x8C */
} Unk41ADC0;

/* Root of the GUI object hierarchy: vtable plus one word (func_00416A90). */
typedef struct GuiObject {
    void* vtable;                  /* 0x00 */
    int unk04;                     /* 0x04 */
} GuiObject;

/* 16-byte record filled by func_00400140. */
typedef struct Unk400140 {
    int unk00;                     /* 0x00 */
    short unk04;                   /* 0x04 */
    char unk06;                    /* 0x06 */
    char unk07;                    /* 0x07 */
    int unk08;                     /* 0x08 */
    int unk0C;                     /* 0x0C */
} Unk400140;

/* Small flag record initialized by func_003E7CD0. */
typedef struct Unk3E7CD0 {
    char unk00;                    /* 0x00 */
    char unk01;                    /* 0x01 */
    char unk02;                    /* 0x02 */
    char pad03;
    int unk04;                     /* 0x04: -7 after initialization */
} Unk3E7CD0;

/* Two words and a flag byte (func_00409580). */
typedef struct Unk409580 {
    int unk00;                     /* 0x00 */
    int unk04;                     /* 0x04 */
    char unk08;                    /* 0x08 */
} Unk409580;

/* Message whose only payload is the word at +0x24 (cEnableMsg, cDisableMsg). */
typedef struct L4Msg24 {
    char pad00[0x24];
    int unk24;                     /* 0x24 */
} L4Msg24;

/* Packed event buffer written by the *_v02 serializers. */
typedef struct L4EventBuf {
    char pad00[8];
    int unk08;                     /* 0x08: first payload word */
} L4EventBuf;

/* Object reset by func_003F6CD0 (>= 0x60 bytes). */
typedef struct Unk3F6CD0 {
    int unk00;                     /* 0x00 */
    char pad04[0x2C];
    int unk30;                     /* 0x30 */
    char pad34[4];
    int unk38;                     /* 0x38 */
    int unk3C;                     /* 0x3C */
    char pad40[4];
    int unk44;                     /* 0x44 */
    char pad48[8];
    int unk50;                     /* 0x50 */
    char pad54[4];
    int unk58;                     /* 0x58 */
    int unk5C;                     /* 0x5C */
} Unk3F6CD0;

/* Object whose colour/vector at +0xA0 is set by func_003EE5E0. */
typedef struct Unk3EE5E0 {
    char pad00[0xA0];
    Vec4 unkA0;                    /* 0xA0 */
} Unk3EE5E0;

/* 0x124-byte vector element (func_00408E00). */
typedef struct L4Elem124 {
    char pad00[0x124];
} L4Elem124;

/* Vector of L4Elem124 (same layout as PtrVec) followed by one extra word. */
typedef struct L4Elem124Vec {
    int unk00;                     /* 0x00 */
    int count;                     /* 0x04 */
    L4Elem124* data;               /* 0x08 */
    int unk0C;                     /* 0x0C */
} L4Elem124Vec;

/* Object tested by func_00415870: GuiWidget flags at +0x14 and a byte at +0x51. */
typedef struct Unk415870 {
    char pad00[0x14];
    unsigned short flags;          /* 0x14 */
    char pad16[0x3B];
    unsigned char unk51;           /* 0x51 */
} Unk415870;

/* Record whose +4 word holds the 0xBEBAAFDE validity tag (func_003CB4F0). */
typedef struct L4Tagged {
    int unk00;                     /* 0x00 */
    unsigned int tag;              /* 0x04: 0xBEBAAFDE when valid */
} L4Tagged;

/* Owner of an L4Tagged pointer at +0xC (func_003CB4F0). */
typedef struct Unk3CB4F0 {
    char pad00[0xC];
    L4Tagged* unk0C;               /* 0x0C */
} Unk3CB4F0;

/* Object with a byte flag at +2 (func_003D1700 / func_003D1730). */
typedef struct Unk3D1700 {
    char pad00[2];
    char unk02;                    /* 0x02 */
} Unk3D1700;

/* 24-byte vector element (func_00416F40). */
typedef struct L4Elem18 {
    char pad00[0x18];
} L4Elem18;

/* Vector of L4Elem18 (same layout as PtrVec). */
typedef struct L4Elem18Vec {
    int unk00;                     /* 0x00 */
    int count;                     /* 0x04 */
    L4Elem18* data;                /* 0x08 */
} L4Elem18Vec;

/* Object with a container at +0x20 (func_003CAC40). */
typedef struct Unk3CAC40 {
    char pad00[0x20];
    char unk20[0xC];               /* 0x20: list with its sentinel at +4 */
} Unk3CAC40;

/* Object with a sub-object at +0x48 (func_003F5D40 / func_003F5D50). */
typedef struct Unk3F5D40 {
    char pad00[0x48];
    char unk48[4];                 /* 0x48 */
} Unk3F5D40;

/* Object with a state word at +0xA8 (func_003F5CD0..func_003F5CF0). */
typedef struct Unk3F5CD0 {
    char pad00[0xA8];
    int unkA8;                     /* 0xA8 */
} Unk3F5CD0;

/* Object with an optional sub-object pointer at +0x50C (func_003FA190). */
typedef struct Unk3FA190 {
    char pad00[0x50C];
    struct Unk3FA190Sub* unk50C;   /* 0x50C */
} Unk3FA190;

typedef struct Unk3FA190Sub {
    char pad00[0x48];
    float unk48;                   /* 0x48 */
} Unk3FA190Sub;

/* Object compared/reset by func_003F6000 / func_003F6020. */
typedef struct Unk3F6000 {
    char pad00[8];
    int unk08;                     /* 0x08 */
    int unk0C;                     /* 0x0C */
    int unk10;                     /* 0x10 */
} Unk3F6000;

/* Generic small records used by single accessors. */
typedef struct Unk3CB590 {
    char pad00[0xC];
    int unk0C;                     /* 0x0C */
} Unk3CB590;

typedef struct Unk3CC1D0 {
    char unk00;                    /* 0x00 */
    char pad01[3];
    int unk04;                     /* 0x04 */
    int unk08;                     /* 0x08 */
} Unk3CC1D0;

typedef struct L4Bytes3 {
    char unk00;
    char unk01;
    char unk02;
} L4Bytes3;

/* Collection with a trailing flag and a vtable pointer at +0x10 (func_003D28D0). */
typedef struct Unk3D28D0 {
    L4ScalarCollection coll;       /* 0x00 */
    char unk0C;                    /* 0x0C */
    char pad0D[3];
    void* vtable;                  /* 0x10 */
} Unk3D28D0;

/* Object with a handle at +0x74 and a word at +0x78 (func_003E7EB0 / func_003E7EC0). */
typedef struct Unk3E7EB0 {
    char pad00[0x74];
    int unk74;                     /* 0x74 */
    int unk78;                     /* 0x78 */
} Unk3E7EB0;

/* Object with flag bytes at +0x104 and +0x106 (func_003ED240). */
typedef struct Unk3ED240 {
    char pad00[0x104];
    char unk104;                   /* 0x104 */
    char pad105;
    char unk106;                   /* 0x106 */
} Unk3ED240;

/* Object with a count at +0x8C (func_003EE500). */
typedef struct Unk3EE500 {
    char pad00[0x8C];
    int unk8C;                     /* 0x8C */
} Unk3EE500;

/* Archive handle returned by Archive_Open (only the byte at +0x168 is known). */
typedef struct L4Archive {
    char pad00[0x168];
    char unk168;                   /* 0x168: set to 1 by func_003F96B0 */
} L4Archive;

/* Byte-flag variant of L4Elem124Vec used by func_004089B0. */
typedef struct L4FlagVec {
    PtrVec vec;                    /* 0x00 */
    char unk0C;                    /* 0x0C */
} L4FlagVec;

/* Word-tagged variant used by func_00418780. */
typedef struct L4WordVec {
    PtrVec vec;                    /* 0x00 */
    int unk0C;                     /* 0x0C */
} L4WordVec;

/* Node of the free list headed by D_00572118 (link at +4). */
typedef struct L4FreeNode {
    int unk00;                     /* 0x00 */
    struct L4FreeNode* next;       /* 0x04 */
} L4FreeNode;

/* Registered object: +0x1C holds the registry it belongs to (Object_SetRegistry). */
typedef struct L4RegObj {
    char pad00[0x1C];
    int registry;                  /* 0x1C */
} L4RegObj;

#endif
