#ifndef HUMANIK_TYPES_H
#define HUMANIK_TYPES_H

/* Pair of signed bytes copied by func_001DB8A0. */
typedef struct IkBytePair {
    signed char a;                  /* 0x00 */
    signed char b;                  /* 0x01 */
} IkBytePair;

/* Tree iterator (single node pointer). */
typedef struct IkIter {
    int node;
} IkIter;

#endif
