#ifndef NIEVENT_TYPES_H
#define NIEVENT_TYPES_H

/* One script-native argument slot (4 bytes). */
typedef union NIEventScriptArg {
    int i;
    float f;
    void* p;
} NIEventScriptArg;

/* Plain three-word vector header {begin, end, capacity end} cleared by the ctors. */
typedef struct NIEventVec3 {
    int begin;
    int end;
    int cap;
} NIEventVec3;

/* Same three words followed by an "owns storage" flag (0x10 bytes). */
typedef struct NIEventOwnedVec {
    NIEventVec3 vec;    /* 0x00 */
    char owned;         /* 0x0C */
} NIEventOwnedVec;

#endif
