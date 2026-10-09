#ifndef BACKPACK_TYPES_H
#define BACKPACK_TYPES_H

/*
 * cBackpack (weapon/item pickup object) and the inventory / crate script
 * messages. Field names are provisional unless the script native names
 * justify them.
 */

/* One script-native argument slot (4 bytes). */
typedef union BackpackScriptArg {
    int i;
    float f;
    void* p;
    unsigned char u8;
} BackpackScriptArg;

/*
 * Script natives copy a value into a one-word stack array and read it back
 * through a cast; the cast keeps the original store/reload sequence.
 */
#define STACK_COPY(arr) (*(int*)(arr))

/* Object registered with func_00170E20 by func_00256180. */
typedef struct BackpackLink {
    char pad00[0x94];
    int owner;                       /* 0x94: copied from cBackpack.unk0C */
} BackpackLink;

typedef struct cBackpack {
    char pad00[0x0C];
    int unk0C;                       /* 0x0C */
    char pad10[0x2F0 - 0x10];
    unsigned char autoPickup;        /* 0x2F0: Script_cBackpack_SetAutoPickup */
    char pad2F1[0x2FC - 0x2F1];
    BackpackLink* link;              /* 0x2FC: created on demand by func_00256180 */
    char pad300[0x30C - 0x300];
    int unk30C;                      /* 0x30C: set to 1 by func_00255A40 */
} cBackpack;

/* Base layout shared by the inventory and crate script messages. */
typedef struct cItemMsg {
    char pad00[0x24];
    int taken;                       /* 0x24 */
    int count;                       /* 0x28: Count (inventory) / Given (crate) */
    int who;                         /* 0x2C: identity word of the sender */
} cItemMsg;

/* Object behind global D_004FFD30; only the field used here. */
typedef struct BackpackWorld {
    char pad00[0xB8];
    char* unkB8;                     /* 0xB8 */
} BackpackWorld;

/* Two-word element vector (8-byte entries) used by func_002564A0. */
typedef struct Pair {
    int a, b;
} Pair;

typedef struct PairVec {
    int unk0;
    int count;                       /* 0x04 */
    Pair* data;                      /* 0x08 */
} PairVec;

#endif
