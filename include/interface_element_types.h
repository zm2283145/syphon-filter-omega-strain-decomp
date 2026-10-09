#ifndef INTERFACE_ELEMENT_TYPES_H
#define INTERFACE_ELEMENT_TYPES_H

/* Interface element (size unknown, at least 0x74). */
typedef struct IfElement {
    char pad00[0x70];
    int owner;      /* 0x70: owning object, passed to the owner-side helpers */
} IfElement;

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
