#ifndef FSTREAM_TYPES_H
#define FSTREAM_TYPES_H

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
