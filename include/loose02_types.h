#ifndef LOOSE02_TYPES_H
#define LOOSE02_TYPES_H

/*
 * Provisional types for loose functions directly under src/main/ (batch loose_02).
 * Field names are placeholders (unkXX) unless a function name, a class-name
 * string returned by a vtable slot, or the research notes justify more.
 * Offsets come from the matched code. Vtable slot N lives at vtable + (N+2)*4;
 * slot 19 of the GUI classes returns the class name string.
 */

#include "types.h"

/* ---------------------------------------------------------------- misc --- */

/* One script-native argument word (int, float bits or pointer). */
typedef union ScriptArg {
    int i;
    float f;
    void* p;
} ScriptArg;

/* Script natives copy an argument through a one-word stack slot first. */
#define STACK_COPY(arr) (*(int*)(arr))

/* Six-float record (two xyz triples). */
typedef struct Float6 {
    float v[6];
} Float6;

/* 3x3 matrix of words, copied row by row. */
typedef struct Mat3Words {
    int m[9];
} Mat3Words;

/* Vector header plus an owns-storage flag (PtrVec-shaped, 0x10 bytes). */
typedef struct OwnedRel {
    Rel vec;                        /* 0x00 */
    unsigned char owned;            /* 0x0C: set to 1 by the constructors */
    char pad0D[3];
} OwnedRel;

/* ------------------------------------------------- animation channel --- */

/* Scalar curve storage embedded at +0x18 of curve channels (0x18 bytes). */
typedef struct CurveSegment {
    char pad[0x18];
} CurveSegment;

/* Base of AnimChannel (constructed with base table 0x004DA380). */
typedef struct CurveChannel {
    void* vtable;
    float previous;                 /* 0x04 */
    float current;                  /* 0x08 */
    float target;                   /* 0x0C */
    float rate;                     /* 0x10 */
    float damping;                  /* 0x14 */
    CurveSegment segment;           /* 0x18 */
    char binding[8];                /* 0x30 bound to segment */
} CurveChannel;

/* Normalized animation channel (0x3C bytes, table 0x004DA840). See research
 * PLAYER_INPUT.md / ANIMATION_CHANNEL_NATIVE.md. */
typedef struct AnimChannel {
    CurveChannel base;
    unsigned char wrap;             /* 0x38 */
    char pad39[3];
} AnimChannel;

/* ------------------------------------------------------------- GUI --- */

/* GUI widget base (constructor GuiWidget_ctor, 0x48 bytes). */
typedef struct GuiWidget {
    void* vtable;                   /* 0x00 */
    int unk04;                      /* 0x04 */
    int unk08;                      /* 0x08 */
    int unk0C;                      /* 0x0C */
    int unk10;                      /* 0x10 */
    unsigned short flags;           /* 0x14 */
    short unk16;                    /* 0x16 */
    short unk18;                    /* 0x18 */
    char pad1A[2];
    int unk1C;                      /* 0x1C */
    int unk20;                      /* 0x20 */
    int unk24;                      /* 0x24 */
    int children[3];                /* 0x28 */
    int unk34;                      /* 0x34 */
    int unk38;                      /* 0x38 */
    int unk3C;                      /* 0x3C */
    int unk40;                      /* 0x40 */
    struct GuiWidget* self;         /* 0x44 */
} GuiWidget;

/* Intermediate widget class with table D_004E1220 (0x4C bytes). */
typedef struct GuiItem {
    GuiWidget base;                 /* 0x00 */
    int unk48;                      /* 0x48: -2 after construction */
} GuiItem;

/* Manager singleton returned by func_004147A0. */
typedef struct GuiManager {
    char pad00[0x68];
    unsigned int flags;             /* 0x68 */
} GuiManager;

/* Animated GUI slot (0x1C bytes); constructor func_0044FA00, reset func_0044F6B0. */
typedef struct GuiSlot {
    int unk00;                      /* 0x00 */
    int unk04;                      /* 0x04 */
    int unk08;                      /* 0x08 */
    int unk0C;                      /* 0x0C */
    int unk10;                      /* 0x10 */
    int unk14;                      /* 0x14 */
    unsigned char unk18;            /* 0x18 */
    unsigned char unk19;            /* 0x19 */
    unsigned char unk1A;            /* 0x1A */
    char pad1B;
} GuiSlot;

/* Screen base built by GuiScreen_ctor (table D_004DE830), >= 0x88 bytes. */
typedef struct GuiScreen {
    GuiItem base;                   /* 0x00 */
    char pad4C[0x78 - 0x4C];
    unsigned char unk78;            /* 0x78 */
    char pad79[0x80 - 0x79];
    unsigned char active;           /* 0x80 */
    char pad81[3];
    int screenId;                   /* 0x84 */
} GuiScreen;

/* Menu screen base built by GuiMenuScreen_ctor (table D_004DE8A0), >= 0x110 bytes. */
typedef struct GuiMenuScreen {
    GuiScreen base;                 /* 0x00 */
    int unk88;                      /* 0x88 */
    int unk8C;                      /* 0x8C */
    char pad90[4];
    unsigned char unk94;            /* 0x94 */
    char pad95[3];
    int unk98;                      /* 0x98 */
    int unk9C;                      /* 0x9C */
    int unkA0;                      /* 0xA0 */
    int unkA4;                      /* 0xA4 */
    int unkA8;                      /* 0xA8 */
    GuiSlot slots[3];               /* 0xAC */
    int unk100;                     /* 0x100 */
    int unk104;                     /* 0x104 */
    int unk108;                     /* 0x108 */
    int unk10C;                     /* 0x10C */
    char pad110[0x160 - 0x110];
} GuiMenuScreen;

/* GuiOnlineConnect screen (table D_004DD620). */
typedef struct GuiOnlineConnect {
    GuiScreen base;                 /* 0x00 */
    int unk88;                      /* 0x88 */
    int unk8C;                      /* 0x8C */
    int unk90;                      /* 0x90 */
    unsigned char unk94;            /* 0x94 */
    char pad95[3];
    GuiSlot slots[3];               /* 0x98 */
    int unkEC;                      /* 0xEC */
    char padF0[4];
    int unkF4;                      /* 0xF4 */
    int unkF8;                      /* 0xF8 */
    int unkFC;                      /* 0xFC */
    int unk100;                     /* 0x100 */
    int unk104;                     /* 0x104 */
    int resource;                   /* 0x108: released through func_00418E00 */
    int unk10C;                     /* 0x10C */
    int unk110;                     /* 0x110 */
    int unk114;                     /* 0x114 */
    int unk118;                     /* 0x118: 4 after construction */
    int unk11C;                     /* 0x11C: -2 after construction */
    int unk120;                     /* 0x120: -2 after construction */
} GuiOnlineConnect;

/* GuiMissionSetup screen (table D_004DD730). */
typedef struct GuiMissionSetup {
    GuiScreen base;                 /* 0x00 */
    GuiSlot slots[3];               /* 0x88 */
    int unkDC;                      /* 0xDC */
    int unkE0;                      /* 0xE0 */
    int unkE4;                      /* 0xE4 */
    int unkE8;                      /* 0xE8 */
    int unkEC;                      /* 0xEC */
    struct GameMachine* machine;    /* 0xF0: copy of D_004FFC04 */
    char* machineData;              /* 0xF4: machine + 0x140 */
    unsigned char unkF8;            /* 0xF8 */
} GuiMissionSetup;

/* GuiOnlineOptions screen (table D_004DDAF0). */
typedef struct GuiOnlineOptions {
    GuiScreen base;                 /* 0x00 */
    int unk88;                      /* 0x88 */
    int unk8C;                      /* 0x8C */
    int unk90;                      /* 0x90 */
    int unk94;                      /* 0x94 */
    int unk98;                      /* 0x98: -1 after construction */
    int unk9C;                      /* 0x9C: -1 after construction */
    GuiSlot slot;                   /* 0xA0 */
} GuiOnlineOptions;

/* GuiNetJoinMission (table D_004DDA50) and GuiNetContacts (table D_004DDC20). */
typedef struct GuiNetListScreen {
    GuiMenuScreen base;             /* 0x000 */
    int unk160;                     /* 0x160 */
    int unk164;                     /* 0x164 */
} GuiNetListScreen;

/* GuiNetAgencyCell screen (table D_004DDD40). */
typedef struct GuiNetAgencyCell {
    GuiMenuScreen base;             /* 0x000 */
    char pad160[4];
    int unk164;                     /* 0x164 */
    int unk168;                     /* 0x168 */
    int unk16C;                     /* 0x16C */
    unsigned char unk170;           /* 0x170 */
    char pad171[3];
    int unk174;                     /* 0x174 */
    int unk178;                     /* 0x178 */
    int unk17C;                     /* 0x17C */
} GuiNetAgencyCell;

/* GuiSaveAgentWidget (table D_004DD460, base table D_004E1220). */
typedef struct GuiSaveAgentWidget {
    GuiItem base;                   /* 0x00 */
    char pad4C[0x78 - 0x4C];
    float unk78;                    /* 0x78: 10.0 after construction */
    unsigned char unk7C;            /* 0x7C: constructor argument */
} GuiSaveAgentWidget;

/* GuiOnlineOfflineSelect (table D_004DD6B0). */
typedef struct GuiOnlineOfflineSelect {
    GuiWidget base;                 /* 0x00 */
    unsigned char unk48;            /* 0x48 */
} GuiOnlineOfflineSelect;

/* GuiMessageBox (table D_004DD9D0). */
typedef struct GuiMessageBox {
    GuiWidget base;                 /* 0x00 */
    int unk48;                      /* 0x48 */
    int unk4C;                      /* 0x4C */
    int unk50;                      /* 0x50 */
    int unk54;                      /* 0x54 */
    int unk58;                      /* 0x58 */
    int unk5C;                      /* 0x5C */
    int unk60;                      /* 0x60 */
    int unk64;                      /* 0x64 */
    int unk68;                      /* 0x68 */
    int unk6C;                      /* 0x6C */
    int unk70;                      /* 0x70 */
    int unk74;                      /* 0x74 */
    int unk78;                      /* 0x78 */
    int unk7C;                      /* 0x7C */
    int unk80;                      /* 0x80 */
    int unk84;                      /* 0x84 */
    int unk88;                      /* 0x88 */
    int unk8C;                      /* 0x8C */
    int unk90;                      /* 0x90 */
} GuiMessageBox;

/* GuiQuickChat (table D_004DDE60). */
typedef struct GuiQuickChat {
    GuiWidget base;                 /* 0x00 */
    int unk48;                      /* 0x48 */
} GuiQuickChat;

/* GuiCharacterDisplay (table D_004DE670). */
typedef struct GuiCharacterDisplay {
    GuiWidget base;                 /* 0x00 */
    void (*onDestroy)(void);        /* 0x48: called by func_00326810 when set */
} GuiCharacterDisplay;

/* GuiMissionList (table D_004DDB80); derives from the widget built by func_00424C50. */
typedef struct GuiMissionListObj {
    GuiWidget base;                 /* 0x00 */
    char pad48[0x58 - 0x48];
    unsigned char unk58;            /* 0x58 */
    char pad59[0xA8 - 0x59];
    int unkA8;                      /* 0xA8 */
    unsigned char unkAC;            /* 0xAC */
    unsigned char unkAD;            /* 0xAD */
    char padAE[2];
    int unkB0;                      /* 0xB0 */
    unsigned char unkB4;            /* 0xB4 */
    unsigned char unkB5;            /* 0xB5 */
    char padB6[2];
    int unkB8;                      /* 0xB8 */
    unsigned char unkBC;            /* 0xBC */
    char padBD[3];
    int unkC0;                      /* 0xC0 */
    int unkC4;                      /* 0xC4 */
    char padC8[4];
    int unkCC;                      /* 0xCC */
    char padD0[0x10C - 0xD0];
    OwnedRel items;                 /* 0x10C */
    int unk11C;                     /* 0x11C */
} GuiMissionListObj;

/* Object behind the global pointer D_004FFC04 (stepped every frame by func_00169390). */
typedef struct GameMachine {
    char pad00[0x2A];
    unsigned char unk2A;            /* 0x2A */
    char pad2B[0x140 - 0x2B];
    char data140[1];                /* 0x140 */
} GameMachine;

/* Command-center style screen used by func_00297350 / func_00298250. */
typedef struct GuiCommandCenter {
    char pad00[0x80];
    unsigned char active;           /* 0x80 */
    char pad81[0x1CC - 0x81];
    int selection;                  /* 0x1CC: -1 when none */
    int unk1D0;                     /* 0x1D0 */
    signed char unk1D4;             /* 0x1D4 */
    char pad1D5[0x2D0 - 0x1D5];
    int unk2D0;                     /* 0x2D0 */
    int unk2D4;                     /* 0x2D4 */
    int unk2D8;                     /* 0x2D8 */
    int unk2DC;                     /* 0x2DC */
    int unk2E0;                     /* 0x2E0 */
    int unk2E4;                     /* 0x2E4 */
} GuiCommandCenter;

/* GuiEquipmentModify screen instance (global D_0051EE10). */
typedef struct GuiEquipmentModifyObj {
    char pad00[0x84];
    int unk84;                      /* 0x84 */
    char pad88[4];
    int unk8C;                      /* 0x8C */
    char pad90[0xD4 - 0x90];
    int unkD4;                      /* 0xD4 */
    char padD8[0x104 - 0xD8];
    int weaponCount;                /* 0x104 */
    int weaponIndex;                /* 0x108 */
    short weaponIds[1];             /* 0x10C */
} GuiEquipmentModifyObj;

/* Weapon definition fields read by func_002C21C0 (see weapon_types.h WeaponDef). */
typedef struct WeaponDefL2 {
    char pad000[0xF0];
    unsigned char kind;             /* 0x0F0: 7 = uses the linked record at +0x11C */
    char pad0F1[0x11C - 0xF1];
    struct WeaponLinkL2* link;      /* 0x11C */
    char pad120[0x13C - 0x120];
    struct WeaponLinkL2* attachment; /* 0x13C */
} WeaponDefL2;

typedef struct WeaponLinkL2 {
    char pad000[0x40A];
    short weaponId;                 /* 0x40A */
} WeaponLinkL2;

/* -------------------------------------------- copyable value records --- */

/* 0x1C-byte record copied by func_002C5E20. */
typedef struct Rec1C {
    Q q;                            /* 0x00 */
    int unk10;                      /* 0x10 */
    int unk14;                      /* 0x14 */
    int unk18;                      /* 0x18 */
} Rec1C;

/* 0x22-byte record copied by func_002C5EE0. */
typedef struct Rec22 {
    Q q;                            /* 0x00 */
    float unk10;                    /* 0x10 */
    float unk14;                    /* 0x14 */
    int unk18;                      /* 0x18 */
    int unk1C;                      /* 0x1C */
    unsigned char unk20;            /* 0x20 */
    unsigned char unk21;            /* 0x21 */
} Rec22;

/* 0x1C-byte record reset by func_00316A00. */
typedef struct Rec316A00 {
    unsigned char unk00;            /* 0x00 */
    unsigned char unk01;            /* 0x01 */
    char pad02[2];
    int unk04;                      /* 0x04 */
    int unk08;                      /* 0x08 */
    signed char unk0C;              /* 0x0C */
    char pad0D[3];
    int unk10;                      /* 0x10 */
    int unk14;                      /* 0x14 */
    int unk18;                      /* 0x18 */
} Rec316A00;

/* --------------------------------- 0x002D.... controller family --- */

/* Owner object reached through Controller2D.owner. */
typedef struct ControllerOwner {
    char pad0000[0x44];
    int unk44;                      /* 0x44 */
    char pad0048[0x3524 - 0x48];
    int unk3524;                    /* 0x3524 */
} ControllerOwner;

/* Positioned target referenced at Controller2D +0x1E0. */
typedef struct ControllerTarget {
    char pad00[0x10];
    float x;                        /* 0x10 */
    float y;                        /* 0x14 */
    float z;                        /* 0x18 */
} ControllerTarget;

typedef struct ControllerLink {
    char pad00[4];
    unsigned char ready;            /* 0x04 */
} ControllerLink;

/* Controller objects whose methods live at 0x002D2xxx-0x002D4xxx. */
typedef struct Controller2D {
    char pad000[0x30];
    ControllerOwner* owner;         /* 0x030 */
    char pad034[0x1AC - 0x34];
    int unk1AC;                     /* 0x1AC */
    char pad1B0[0x1E0 - 0x1B0];
    ControllerTarget* target;       /* 0x1E0 */
    ControllerLink* link;           /* 0x1E4 */
    int unk1E8;                     /* 0x1E8 */
    char pad1EC[0x200 - 0x1EC];
    float unk200;                   /* 0x200 */
    char pad204[0x208 - 0x204];
    int unk208;                     /* 0x208 */
    char pad20C[4];
    int unk210;                     /* 0x210 */
} Controller2D;

/* Object with a position at +0x38 (func_002D79A0). */
typedef struct PosObj38 {
    char pad00[0x38];
    float x;                        /* 0x38 */
    float y;                        /* 0x3C */
    float z;                        /* 0x40 */
} PosObj38;

/* Object at 0x002D9xxx-0x002DAxxx. */
typedef struct Obj2D9 {
    char pad00[0x6C];
    int unk6C;                      /* 0x6C */
    unsigned int flags;             /* 0x70 */
    char pad74[4];
    int unk78;                      /* 0x78 */
    char pad7C[0x98 - 0x7C];
    int unk98;                      /* 0x98 */
} Obj2D9;

/* --------------------------------- parameter blocks (0x00318xxx) --- */

/* Parameter block reached through ParamOwner.params (func_00318300..). */
typedef struct ParamBlock {
    char pad00[0x1C];
    float unk1C;                    /* 0x1C */
    char pad20[0x28 - 0x20];
    short unk28;                    /* 0x28: set to 1 when unk1C changes */
    short unk2A;                    /* 0x2A */
    short unk2C;                    /* 0x2C */
    char pad2E[2];
    float unk30;                    /* 0x30 */
    float unk34;                    /* 0x34 */
} ParamBlock;

typedef struct ParamOwner {
    char pad00[0x38];
    float scale;                    /* 0x38: used by func_003182E0 */
    char pad3C[0x48 - 0x3C];
    ParamBlock* params;            /* 0x48 */
} ParamOwner;

/* Object holding a screen pointer at +0x88 (func_002A7DD0). */
typedef struct ScreenRefHolder {
    char pad00[0x88];
    GuiScreen* screen;              /* 0x88 */
} ScreenRefHolder;

/* cEnableSuperJumpMsg network message (payload byte at +0x24). */
typedef struct EnableSuperJumpMsg {
    char pad00[0x24];
    unsigned char enable;           /* 0x24 */
} EnableSuperJumpMsg;

/* Object with float settings at +0x24 / +0x2C (func_0031FC10 / func_0031FC20). */
typedef struct FloatSettings {
    char pad00[0x24];
    float unk24;                    /* 0x24 */
    char pad28[4];
    float unk2C;                    /* 0x2C */
} FloatSettings;

/* Object with an embedded record at +0x48 and an index at +0x58 (func_00328630). */
typedef struct Obj328630 {
    char pad00[0x48];
    char unk48[0x10];               /* 0x48: reset by func_0032A280 */
    int unk58;                      /* 0x58 */
} Obj328630;

/* Copyable record (func_0032A050): base part, owning vector at +0x0C, word at +0x1C. */
typedef struct Rec32A050 {
    char pad00[0x0C];               /* 0x00: copied by func_0013BCB0 */
    OwnedRel vec;                   /* 0x0C */
    int unk1C;                      /* 0x1C */
} Rec32A050;

/* Network-library handles (0x002E....-0x00310...); only the touched fields are known. */
typedef struct RtObj3C {
    char pad00[0x3C];
    int unk3C;                      /* 0x3C */
} RtObj3C;

typedef struct RtObj5C {
    char pad00[0x5C];
    int unk5C;                      /* 0x5C */
} RtObj5C;

typedef struct RtObj188 {
    char pad000[0x188];
    unsigned int unk188;            /* 0x188: at most 256 */
} RtObj188;

typedef struct RtObj210 {
    char pad000[4];
    int unk004;                     /* 0x004 */
    char pad008[0x210 - 8];
    int unk210;                     /* 0x210 */
} RtObj210;

/* Small state record checked by func_002F67C0. */
typedef struct RtState {
    unsigned char unk00;            /* 0x00 */
    unsigned char unk01;            /* 0x01 */
    char pad02[6];
    unsigned int state;             /* 0x08: valid below 4 */
} RtState;

/* Objects read by single-field getters (0x002DC290..0x002F3BF0). */
typedef struct WordFields {
    int unk00;                      /* 0x00 */
    int unk04;                      /* 0x04 */
    int unk08;                      /* 0x08 */
    char pad0C[0x18 - 0x0C];
    int unk18;                      /* 0x18 */
} WordFields;

typedef struct Obj850 {
    char pad000[0x850];
    int unk850;                     /* 0x850 */
} Obj850;

/* Two-float pair (func_00318C50). */
typedef struct Float2 {
    float a;                        /* 0x00 */
    float b;                        /* 0x04 */
} Float2;

#endif
