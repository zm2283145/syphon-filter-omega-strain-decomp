#include "types.h"

typedef struct Entry140 {
    char pad[0x130];
    float value;
    char pad2[0xC];
} Entry140;

typedef struct EntryTable {
    char pad[0x60];
    Entry140* entries;
    int unk64;
    int current;
} EntryTable;

/* Returns the float at +0x130 of the current 0x140-byte entry. */
float func_00412130(EntryTable* t) {
    return t->entries[t->current].value;
}
