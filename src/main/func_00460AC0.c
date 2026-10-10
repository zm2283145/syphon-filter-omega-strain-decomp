#include "types.h"

typedef struct Entry12 {
    int a;
    int b;
    int ticks;
} Entry12;

typedef struct Vec12 {
    int unk0;
    int count;
    Entry12* items;
} Vec12;

extern void strncpy(void* dst, const void* src, int size); /* strncpy-style copy */
extern void func_00461770(Vec12* vec, Entry12* pos, int count, Entry12* value);

/* Appends an entry: 8-byte name copied from `name`, ticks = seconds * 30. */
void func_00460AC0(Vec12* vec, const char* name, float seconds) {
    Entry12 entry;
    strncpy(&entry, name, 8);
    entry.ticks = (int)(30.0f * seconds);
    func_00461770(vec, vec->items + vec->count, 1, &entry);
}
