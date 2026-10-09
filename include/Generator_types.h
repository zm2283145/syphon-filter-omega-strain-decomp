#ifndef GENERATOR_TYPES_H
#define GENERATOR_TYPES_H

/* Linked list node (next at +4, value at +8). */
typedef struct GenListNode {
    struct GenListNode* unk00;      /* 0x00 */
    struct GenListNode* next;       /* 0x04 */
    int value;                      /* 0x08 */
} GenListNode;

typedef struct GenListPos {
    GenListNode* node;
} GenListPos;

#endif
