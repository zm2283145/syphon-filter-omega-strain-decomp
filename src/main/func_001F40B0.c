/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose01_types.h"

extern int func_001F40C0(ObjVec*, int);
extern char* func_001F4110(ObjVec*);
extern char** func_001F4150(ObjVec*);
extern int func_0020A080(ObjVec*, char*, int, int);

void func_001F40B0(ObjVec* v, int value) {
    func_001F40C0(v, value);
}

/* Append one element at the end. */
int func_001F40C0(ObjVec* v, int value) {
    return func_0020A080(v, func_001F4110(v), 1, value);
}

/* End pointer for 12-byte elements. */
char* func_001F4110(ObjVec* v) {
    char** data;
    int count;

    data = func_001F4150(v);
    count = v->count;
    return *data + count * 12;
}
