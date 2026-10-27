#ifndef HUMANCOLLISION_TYPES_H
#define HUMANCOLLISION_TYPES_H

/*
 * Human collision preset configuration: three [min, max] float ranges and a
 * boolean (see research HUMAN_COLLISION.md, preset records +0x14..+0x2c).
 */
typedef struct HumanColPresetCfg {
    float range0Min;                /* 0x00 */
    float range0Max;                /* 0x04 */
    float range1Min;                /* 0x08 */
    float range1Max;                /* 0x0C */
    float range2Min;                /* 0x10 */
    float range2Max;                /* 0x14 */
    unsigned char enabled;          /* 0x18 */
} HumanColPresetCfg;

/* Mask word: HumanColMask_* test the candidate flags, HumanColQueryMask_* a secondary query result. */
typedef struct HumanColMask {
    int bits;                       /* 0x00 */
} HumanColMask;

/* Preset record (0xF0 bytes); constructor cHumanCollisionRoutine_cIntermediateLedgeSearchInfo_ctor_void, configured by cHumanCollisionRoutine_cIntermediateLedgeSearchInfo_ctor_eLedgeSubtype_cBitArrayR_cBitArrayR_cBitArrayR_etc. */
typedef struct HumanColPreset {
    signed char selector;           /* 0x00 -1 until configured */
    char pad01[3];
    HumanColMask masks[4];          /* 0x04 required, excluded, query required, query excluded */
    HumanColPresetCfg cfg;          /* 0x14 range0 = accepted relative height interval */
    unsigned char descFlag;         /* 0x30 trailing descriptor boolean */
    unsigned char active;           /* 0x31 copied from the actor slot's activation byte */
    unsigned char unk32;            /* 0x32 reset before processing */
    char pad33[0x70 - 0x33];
    unsigned char unk70;            /* 0x70 */
    char pad71[0x90 - 0x71];
    int unk90;                      /* 0x90 */
    int unk94;                      /* 0x94 */
    int unk98;                      /* 0x98 */
    int pad9C;
    int unkA0;                      /* 0xA0 */
    char padA4[0xE0 - 0xA4];
    float bestHeight;               /* 0xE0 height of the accepted candidate so far */
    int unkE4;                      /* 0xE4 */
    char padE8[0xF0 - 0xE8];
} HumanColPreset;

#define HUMANCOL_PRESET_COUNT 9

/* Preset manager (0x880 bytes) at g_HumanColPresetMgr. */
typedef struct HumanColPresetMgr {
    int count;                      /* 0x00 presets appended so far */
    char pad04[0xC];
    HumanColPreset presets[HUMANCOL_PRESET_COUNT]; /* 0x10 */
} HumanColPresetMgr;

/* vector header {capacity, count, data} plus a byte; the two companion buffers. */
typedef struct HumanColVec {
    unsigned int capacity;          /* 0x00 */
    unsigned int count;             /* 0x04 */
    void* data;                     /* 0x08 */
    signed char flag0C;             /* 0x0C set to 1 by cHumanCollisionRoutine_InitStatics */
    char pad0D[3];
} HumanColVec;

/* Initial capacity of both companion buffers. */
#define HUMANCOL_VEC_RESERVE 150

#endif
