/*
 * Matched functions (byte-identical with the retail executable).
 * fileman.cc
 */

#include "types.h"
#include "fileman_types.h"

extern int func_003695C0(int halFile);

/* If the entry has an open file (flag bit 0), pass its HAL file to func_003695C0. */
void func_0036DEC0(FileManEntry* entry) {
    if (entry->flags & 1) {
        func_003695C0(entry->halFile);
    }
}
