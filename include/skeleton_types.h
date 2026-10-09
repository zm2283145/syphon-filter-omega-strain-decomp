#ifndef SKELETON_TYPES_H
#define SKELETON_TYPES_H

/* List iterator (single node pointer); the list sentinel node is at +4. */
typedef struct SkelListPos {
    void* node;
} SkelListPos;

#endif
