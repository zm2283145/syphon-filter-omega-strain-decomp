#include "types.h"

typedef struct Entry140 {
    char pad000[0x138];
    int value; /* 0x138 */
    char pad13C[4];
} Entry140; /* size 0x140 */

typedef struct EntryTable {
    char pad00[0x60];
    Entry140* entries; /* 0x60 */
    char pad64[4];
    int current;       /* 0x68 */
} EntryTable;

/* Returns the value field of the current entry. */
int func_004121F0(EntryTable* t) {
    return t->entries[t->current].value;
}
