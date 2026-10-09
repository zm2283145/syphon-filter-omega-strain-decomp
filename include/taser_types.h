#ifndef TASER_TYPES_H
#define TASER_TYPES_H

/* Vector of 64-byte records used by the taser code. */
typedef struct TaserEntry {
    char pad00[0x40];
} TaserEntry;                       /* size 0x40 */

typedef struct TaserVec {
    int unk0;
    int count;
    TaserEntry* data;               /* 0x08 */
} TaserVec;

#endif
