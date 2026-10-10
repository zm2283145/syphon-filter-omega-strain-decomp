#pragma opt_strength_reduction off
#include "types.h"

typedef struct LookupE6 {
    void* name;
    int pad[4];
    int value;
} LookupE6;

extern int D_00532AF4;
extern LookupE6* D_00532AF8;
extern void* func_003FDAE0(void* name);
extern int func_00128E80(void* a, void* b);

static inline LookupE6* EntryE6(int i) { return &D_00532AF8[i]; }

/* Finds the table entry whose name matches, returning its value (default 0x16). */
int func_00330B80(void* name)
{
    int count = D_00532AF4;
    int i;
    for (i = 0; i < count; i++) {
        if (func_00128E80(func_003FDAE0(EntryE6(i)->name), name) == 0) {
            return EntryE6(i)->value;
        }
    }
    return 0x16;
}