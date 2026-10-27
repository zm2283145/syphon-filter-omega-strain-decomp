/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose01_types.h"

extern int std_vector_imp_cSkaTransBLEND_push_back(ObjVec*, int);
extern char* std_vector_imp_cSkaTransBLEND_end_void(ObjVec*);
extern char** std_vector_deleter_cSkaTransBLEND_data_void(ObjVec*);
extern int std_vector_imp_cSkaTransBLEND_insert(ObjVec*, char*, int, int);

void std_vector_cSkaTransBLEND_push_back(ObjVec* v, int value) {
    std_vector_imp_cSkaTransBLEND_push_back(v, value);
}

/* Append one element at the end. */
int std_vector_imp_cSkaTransBLEND_push_back(ObjVec* v, int value) {
    return std_vector_imp_cSkaTransBLEND_insert(v, std_vector_imp_cSkaTransBLEND_end_void(v), 1, value);
}

/* End pointer for 36-byte elements. */
char* std_vector_imp_cSkaTransBLEND_end_void(ObjVec* v) {
    char** data;
    int count;

    data = std_vector_deleter_cSkaTransBLEND_data_void(v);
    count = v->count;
    return *data + count * 36;
}
