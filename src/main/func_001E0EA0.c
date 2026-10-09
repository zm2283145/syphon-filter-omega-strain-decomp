/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose00_types.h"

extern int func_001C50A0(void*, void*);
extern int Vec16Array_PopBack(Vec16Array*);
extern int func_001E0FE0(FlagElem16*, int);

/* End pointer of an array of 0x60-byte records. */
Elem60* func_001E0EA0(Vec60Array* v) {
    int count;
    Elem60* data;

    count = v->count;
    data = v->data;
    return data + count;
}

void func_001E0EC0(Iter* out, void* self, Iter* src) {
    out->p = src->p;
}

Elem60* func_001E0ED0(Vec60Array* v) {
    return v->data;
}

int func_001E0EE0(Vec16Array* v) {
    return Vec16Array_PopBack(v);
}

/* Pop the last 16-byte element and destroy it. */
int Vec16Array_PopBack(Vec16Array* v) {
    int count;
    FlagElem16* data;

    count = v->count;
    v->count = count + -1;
    data = v->data;
    return func_001E0FE0(data + (count + -1), -1);
}

/* Copy-construct: base copy then the flag byte at +0x0C. */
FlagElem16* func_001E0F10(FlagElem16* d, FlagElem16* s) {
    unsigned char flag;

    func_001C50A0(d, s);
    flag = s->unk0C;
    d->unk0C = flag;
    return d;
}

/* Last element of a 16-byte array. */
FlagElem16* func_001E0F50(Vec16Array* v) {
    return (v->data + v->count) + -1;
}
