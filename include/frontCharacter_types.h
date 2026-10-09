#ifndef FRONTCHARACTER_TYPES_H
#define FRONTCHARACTER_TYPES_H

/* Vector of words (same layout as PtrVec). */
typedef struct FcVec {
    int unk0;
    int count;                      /* 0x04 */
    int* data;                      /* 0x08 */
} FcVec;

#endif
