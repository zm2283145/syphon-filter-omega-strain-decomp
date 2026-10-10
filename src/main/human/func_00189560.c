#include "types.h"

typedef struct { char data[0x124]; } Entry124;
typedef struct { char pad[8]; Entry124* entries; } EntryTable;
typedef struct { char unk0; unsigned char index; } EntryRef;
extern EntryTable* D_0053BB94;

/* Returns the 0x124-byte table entry selected by ref->index. */
Entry124* func_00189560(EntryRef* ref)
{
    return &D_0053BB94->entries[ref->index];
}
