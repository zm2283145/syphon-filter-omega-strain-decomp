#ifndef MAN_TYPES_H
#define MAN_TYPES_H

/*
 * Types for man.cc (skeletal model rendering and equipment attachment).
 * Layouts are partial.
 */

/* 4x4 float matrix, row-major m[row][col]. */
typedef struct ManMatrix {
    float m[4][4];
} ManMatrix;

/* Owner of the equipment slot table used by Equip_Init / Equip_SwapSlots. */
typedef struct ManEquipOwner {
    char pad0000[0x2410];
    int slots[8];               /* 0x2410: attached item per slot, 0 = empty (count not confirmed) */
} ManEquipOwner;

#endif
