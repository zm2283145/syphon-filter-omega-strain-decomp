#ifndef GENINFOOBJECT_TYPES_H
#define GENINFOOBJECT_TYPES_H

/* List iterator (single node pointer); the list sentinel node is at +4. */
typedef struct GioListPos {
    void* node;
} GioListPos;

#endif
