/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose01_types.h"

extern int func_001F2D60(ObjVec*, int);
extern char* func_001F2DB0(ObjVec*);
extern char** func_001F2DF0(ObjVec*);
extern int func_0020B570(ObjVec*, char*, int, int);

void func_001F2D50(ObjVec* v, int value) {
    func_001F2D60(v, value);
}

/* Append one element at the end. */
int func_001F2D60(ObjVec* v, int value) {
    return func_0020B570(v, func_001F2DB0(v), 1, value);
}

/* End pointer for 20-byte elements. */
char* func_001F2DB0(ObjVec* v) {
    char** data;
    int count;

    data = func_001F2DF0(v);
    count = v->count;
    return *data + count * 20;
}
