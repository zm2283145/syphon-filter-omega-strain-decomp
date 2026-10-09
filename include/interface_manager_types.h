#ifndef INTERFACE_MANAGER_TYPES_H
#define INTERFACE_MANAGER_TYPES_H

#define IFMGR_SLOT_COUNT 20

/* One manager slot (0x18 bytes). */
typedef struct IfMgrSlot {
    char pad00[0x0C];
    int unk0C;          /* 0x0C: returned by func_00413370 */
    char pad10[0x08];
} IfMgrSlot;

/* Interface manager (size unknown, at least 0x1E4). */
typedef struct IfManager {
    IfMgrSlot slots[IFMGR_SLOT_COUNT];  /* 0x000 */
    int unk1E0;                         /* 0x1E0 */
} IfManager;

/* 12-byte record. */
typedef struct IfRec12 {
    int a, b, c;
} IfRec12;

/* Vector of 12-byte records (same shape as PtrVec). */
typedef struct IfRecVec {
    int unk00;
    int count;          /* 0x04 */
    IfRec12* data;      /* 0x08 */
} IfRecVec;

#endif
