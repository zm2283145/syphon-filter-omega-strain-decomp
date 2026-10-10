#include "types.h"

typedef struct { int unk0; int value; } Entry4;
extern void* D_00583870;
extern void func_002EB650(Entry4** out, void* key);

/* Looks up the global key and returns the entry's value, or -1 if not found. */
int func_00437600(void)
{
    Entry4* entry;
    func_002EB650(&entry, D_00583870);
    if (entry)
        return entry->value;
    return -1;
}
