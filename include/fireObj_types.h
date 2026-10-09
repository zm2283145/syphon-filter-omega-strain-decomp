#ifndef FIREOBJ_TYPES_H
#define FIREOBJ_TYPES_H

/* Types for the fireObj directory. Layouts are provisional. */

typedef struct cFireObj {
    char pad00[0x2C];
    unsigned char lit;          /* 0x2C: set by v08, cleared by v09 */
} cFireObj;

#endif
