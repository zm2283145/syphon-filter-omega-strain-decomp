#ifndef WATERFX_TYPES_H
#define WATERFX_TYPES_H

/* Types for the WaterFx directory. Layouts are provisional. */

typedef struct WaterListLink {
    struct WaterListLink* next; /* 0x00 */
    struct WaterListLink* prev; /* 0x04 */
} WaterListLink;

/* Doubly linked list with an inline sentinel (12 bytes). */
typedef struct WaterList {
    int count;                  /* 0x00 */
    WaterListLink head;         /* 0x04: sentinel, end() */
} WaterList;

typedef struct WaterListIter {
    WaterListLink* node;
} WaterListIter;

#endif
