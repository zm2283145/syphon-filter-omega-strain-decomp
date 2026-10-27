/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose01_types.h"

extern int std_vector_imp_cSkaSwitchItem_push_back(ObjVec*, int);
extern char* std_vector_imp_cSkaSwitchItem_end(ObjVec*);
extern char** std_vector_deleter_cSkaSwitchItem_data(ObjVec*);
extern int std_vector_imp_cSkaSwitchItem_insert(ObjVec*, char*, int, int);

void std_vector_cSkaSwitchItem_push_back(ObjVec* v, int value) {
    std_vector_imp_cSkaSwitchItem_push_back(v, value);
}

/* Append one element at the end. */
int std_vector_imp_cSkaSwitchItem_push_back(ObjVec* v, int value) {
    return std_vector_imp_cSkaSwitchItem_insert(v, std_vector_imp_cSkaSwitchItem_end(v), 1, value);
}

/* End pointer for 20-byte elements. */
char* std_vector_imp_cSkaSwitchItem_end(ObjVec* v) {
    char** data;
    int count;

    data = std_vector_deleter_cSkaSwitchItem_data(v);
    count = v->count;
    return *data + count * 20;
}
