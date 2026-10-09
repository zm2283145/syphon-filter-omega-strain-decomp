/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "human_types.h"

extern void func_001BADD0(int*, int, int);
extern int func_001BDA10(PtrVec*, char*, int, int);

/* Tree iterator dereference: value stored at node +0x30. */
char* func_001926C0(Iter* it) {
    return (char*)it->p + 48;
}

/* Tree lookup wrapper returning the found iterator through out. */
void func_001926D0(int* out) {
    int it[1];
    int a1, a2;

    func_001BADD0(it, a1, a2);
    *out = it[0];
}

/* push_back for a vector of 20-byte elements. */
int func_00192700(PtrVec* v, int value) {
    char* data = (char*)v->data;
    int count = v->count;

    return func_001BDA10(v, data + count * 20, 1, value);
}

int* func_00192730(int* pair, int first, int second) {
    pair[0] = first;
    pair[1] = second;
    return pair;
}
