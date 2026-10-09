/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose01_types.h"

extern int func_001F3480(ObjVec*, int);
extern char* func_001F34D0(ObjVec*);
extern char** func_001F3510(ObjVec*);
extern int func_0020A910(ObjVec*, char*, int, int);

void func_001F3470(ObjVec* v, int value) {
    func_001F3480(v, value);
}

/* Append one element at the end. */
int func_001F3480(ObjVec* v, int value) {
    return func_0020A910(v, func_001F34D0(v), 1, value);
}

/* End pointer for 36-byte elements. */
char* func_001F34D0(ObjVec* v) {
    char** data;
    int count;

    data = func_001F3510(v);
    count = v->count;
    return *data + count * 36;
}
