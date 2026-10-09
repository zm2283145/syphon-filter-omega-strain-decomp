#ifndef CALLBACK_TYPES_H
#define CALLBACK_TYPES_H

/* List iterator (single node pointer); the list sentinel node is at +4. */
typedef struct CbListPos {
    void* node;
} CbListPos;

#endif
