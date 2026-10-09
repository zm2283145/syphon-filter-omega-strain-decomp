#ifndef LOOSE01_TYPES_H
#define LOOSE01_TYPES_H

/*
 * Provisional types for loose functions directly under src/main/ (batch loose_01).
 * Field names are placeholders (unkXX) unless a function name justifies more.
 */

/* Object whose first word points at a handle; func_003EEBE0(*handle, 0, 1) is used on it. */
typedef struct HandleHolder {
    int* handle;
} HandleHolder;

/* Owner of a handle plus 14 slots released with func_00272280 (>= 0x3C bytes). */
typedef struct SlotTable14 {
    int* handle;     /* 0x00 */
    int slots[14];   /* 0x04 */
} SlotTable14;

/* 12-byte collection header initialized by ScalarCollection_Init. */
typedef struct ScalarCollection {
    int unk00;
    int unk04;
    int unk08;
} ScalarCollection;

/* Object built by func_0027B900 (>= 0x58 bytes). */
typedef struct Unk27B900 {
    int* handle;               /* 0x00 */
    int unk04;                 /* 0x04 */
    char pad08[4];
    int unk0C;                 /* 0x0C */
    char pad10[4];
    int unk14;                 /* 0x14 */
    int unk18;                 /* 0x18 */
    int unk1C;                 /* 0x1C */
    int unk20;                 /* 0x20 */
    char pad24[4];
    int unk28;                 /* 0x28 */
    ScalarCollection list;     /* 0x2C */
    int unk38;                 /* 0x38 */
    int unk3C;                 /* 0x3C */
    char pad40[0x10];
    int unk50;                 /* 0x50 */
    char unk54;                /* 0x54 */
    char unk55;                /* 0x55 */
    char unk56;                /* 0x56 */
} Unk27B900;

/* Growable array header: unk00, element count, data pointer, owns-storage flag (0x10 bytes). */
typedef struct ObjVec {
    int unk00;        /* 0x00 */
    int count;        /* 0x04 */
    char* data;       /* 0x08 */
    unsigned char owned;       /* 0x0C, set to 1 by the constructors */
} ObjVec;

/* Iterator over a linked list: the node's word at +4 is the next node. */
typedef struct ListNode {
    struct ListNode* unk00;
    struct ListNode* next;   /* 0x04 */
} ListNode;

typedef struct ListIter {
    ListNode* node;
} ListIter;

/* Base of the motion-graph nodes (built by MotionNode_BaseCtor, 0x20 bytes). */
typedef struct MotionNode {
    void* vtable;          /* 0x00 */
    char type;             /* 0x04: 2 = slider, 3 = node built by func_001F2B70 */
    char pad05[0xB];
    int name;              /* 0x10: initialized by func_00132800, copied by func_001325F0 */
    char pad14[0xC];
} MotionNode;

/* Motion node with a child array (MotionSlider and the type-3 node). */
typedef struct MotionSlider {
    MotionNode base;       /* 0x00 */
    int unk20;             /* 0x20 */
    ObjVec children;       /* 0x24 */
    unsigned char unk34;            /* 0x34 */
    unsigned char unk35;            /* 0x35 */
} MotionSlider;

/* Two-float threshold pair copied by MotionSliderChild_CopyThresholds. */
typedef struct FloatPair {
    float a;
    float b;
} FloatPair;

/* Element built by MotionEntry_Ctor (0x24 bytes, stored in 36-byte-stride arrays). */
typedef struct MotionEntry24 {
    ObjVec list;           /* 0x00 */
    float unk10;           /* 0x10 */
    float unk14;           /* 0x14 */
    int unk18;             /* 0x18, -1 */
    char unk1C;            /* 0x1C */
    char unk1D;            /* 0x1D */
    char pad1E[2];
    int unk20;             /* 0x20, -1 */
} MotionEntry24;

typedef struct Vec2f {
    float x;
    float y;
} Vec2f;

/* Object built by func_001F0540 on top of func_003B2950 (>= 0x70 bytes). */
typedef struct Unk1F0540 {
    void* vtable;          /* 0x00 */
    char pad04[0x4C];
    int unk50;             /* 0x50 */
    float unk54;           /* 0x54 */
    float unk58;           /* 0x58 */
    char pad5C[4];
    Vec4 unk60;            /* 0x60 */
} Unk1F0540;

/* Object built by func_001F32E0: a looked-up motion followed by an array at +4. */
typedef struct Unk1F32E0 {
    int unk00;             /* 0x00 */
    ObjVec list;           /* 0x04 */
} Unk1F32E0;

/* One script-native argument word (same layout as in scriptUtils_types.h). */
typedef union ScriptArg {
    int i;
    float f;
    void* p;
} ScriptArg;

/* Object reached through D_004FFC2C; holds the objective marker manager at +0x90. */
typedef struct GameUI {
    char pad00[0x90];
    char markerMgr[0x40];  /* 0x90: ObjMarkerMgr (see hudTargets_types.h) */
} GameUI;

/* Game object as seen by the radar/waypoint natives: marker key at +0x0C. */
typedef struct MarkerTarget {
    char pad00[0xC];
    int markerKey;         /* 0x0C */
} MarkerTarget;

/* Event/message object built on Event_Construct: payload byte at +0x24. */
typedef struct ByteEvent {
    void* vtable;          /* 0x00 */
    char pad04[0x20];
    char value;            /* 0x24 */
} ByteEvent;

/* Message object holding a pointer at +0x24 (cBeamMsg / cMenuChoiceMsg). */
typedef struct PtrMsg {
    void* vtable;          /* 0x00 */
    char pad04[0x20];
    void* who;             /* 0x24 */
    int choice;            /* 0x28 */
} PtrMsg;

/*
 * Record view into the table at D_005381F0: record i starts at D_005381F0 + i * 0x110
 * (index from D_00538C60); only the fields used here (0x2E0..0x2F6) are named.
 */
typedef struct Slot110View {
    char pad000[0x2E0];
    int unk2E0;            /* 0x2E0 */
    char pad2E4[4];
    float unk2E8;          /* 0x2E8, set to 100.0f */
    char pad2EC[8];
    char unk2F4;           /* 0x2F4 */
    char pad2F5;
    char unk2F6;           /* 0x2F6 */
} Slot110View;

/* FX light entry (0x40 bytes). */
typedef struct FxLight {
    float dist;            /* 0x00 */
    char pad04[0x3C];
} FxLight;

/* FX light settings reached through D_004FFC30: five lights from +0x74. */
typedef struct FxLightSet {
    char pad00[0x74];
    FxLight lights[5];     /* 0x74 */
} FxLightSet;

typedef struct Vec3f {
    float x;
    float y;
    float z;
} Vec3f;

/* Value with "valid" flag: id -1 and flag cleared by func_00237380. */
typedef struct IdFlag {
    int id;                /* 0x00 */
    char flag;             /* 0x04 */
} IdFlag;

/* Object cleared by func_00260970: two flag bytes, an int and a float rectangle (0x18 bytes). */
typedef struct Unk260940 {
    unsigned char unk00;   /* 0x00 */
    unsigned char unk01;   /* 0x01 */
    char pad02[2];
    int unk04;             /* 0x04 */
    float unk08;           /* 0x08 */
    float unk0C;           /* 0x0C */
    float unk10;           /* 0x10 */
    float unk14;           /* 0x14 */
} Unk260940;

/* Object with four words cleared by func_00251350. */
typedef struct Unk251350 {
    char pad00[0xC];
    int unk0C;             /* 0x0C */
    int unk10;             /* 0x10 */
    int unk14;             /* 0x14 */
    int unk18;             /* 0x18 */
} Unk251350;

/* Object built by func_00288A80 on top of GuiWidget_ctor (>= 0x54 bytes). */
typedef struct Unk288A80 {
    void* vtable;          /* 0x00 */
    char pad04[0x44];
    unsigned char unk48;   /* 0x48: set when an agent is selected */
    char pad49[3];
    int unk4C;             /* 0x4C */
    int unk50;             /* 0x50, -2 */
} Unk288A80;

/* Object with a "pending" flag at +0x80 (func_0028A430). */
typedef struct Unk28A430 {
    char pad00[0x80];
    unsigned char pending; /* 0x80 */
} Unk28A430;

/* Object built by func_00229E60 on top of func_003CB110 (member at +0x2C). */
typedef struct Unk229E60 {
    void* vtable;          /* 0x00 */
    char pad04[0x28];
    int unk2C;             /* 0x2C */
} Unk229E60;

/* Global object at D_00489738 (only field read here). */
typedef struct Unk489738 {
    char pad00[0xC];
    int unk0C;             /* 0x0C */
} Unk489738;

/* Object with fields cleared by func_0026C130. */
typedef struct Unk26C130 {
    char pad00[0x60];
    int unk60;             /* 0x60 */
    int unk64;             /* 0x64 */
    char pad68[0x28];
    int unk90;             /* 0x90 */
    int unk94;             /* 0x94 */
} Unk26C130;

/* Motion selection node (MotionSelNode_Ctor): looked-up motion, then a group pair at +4. */
typedef struct MotionSelNode {
    int unk00;             /* 0x00 */
    int pair;              /* 0x04: copied by MotionGroup_CopyPair (size unknown) */
} MotionSelNode;

/* Object whose word at +0x3C is returned by func_00272AC0. */
typedef struct Unk272AC0 {
    char pad00[0x3C];
    int unk3C;             /* 0x3C */
} Unk272AC0;

#endif
