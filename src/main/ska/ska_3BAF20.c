#include "types.h"

typedef struct { char pad[0x50]; unsigned long bits; } Entry50;
typedef struct { char pad[8]; Entry50** entries; } EntryTable;

extern EntryTable* D_00539248;

/* Returns bits 5..13 of the 64-bit field at +0x50 of the indexed table entry. */
unsigned int func_003BAF20(int* index)
{
    return (unsigned int)(int)(D_00539248->entries[*index]->bits & 0x3FFF) >> 5;
}
