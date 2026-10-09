#ifndef LOADER_TYPES_H
#define LOADER_TYPES_H

#include "types.h"

/* Vector (three zeroed words, same shape as PtrVec) followed by an ownership flag. */
typedef struct LoaderOwnedVec {
    PtrVec vec;         /* 0x00: zeroed by func_001C0700 / func_001C07F0 / func_001C0840 */
    char owns;          /* 0x0C: set to 1 by the constructors */
} LoaderOwnedVec;

/* Object initialised by func_0013BCB0 with an extra word at +0x0C (size unknown). */
typedef struct LoaderObj {
    char pad00[0x0C];
    int unk0C;          /* 0x0C */
} LoaderObj;

#ifndef STDLIST_DEFINED
#define STDLIST_DEFINED
/* Doubly linked list with a sentinel node at +0x04 (end() == &header). */
typedef struct StdList {
    int unk00;
    int header;     /* 0x04: sentinel node (layout not recovered) */
} StdList;

/* Pair of iterators kept on the stack around List_InsertBefore. */
typedef struct ListInsertArgs {
    int* pos;       /* where to insert (end() for push_back) */
    int* result;    /* iterator to the new node */
} ListInsertArgs;
#endif

#endif
