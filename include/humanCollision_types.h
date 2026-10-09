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

#endif
