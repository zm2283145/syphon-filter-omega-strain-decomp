#include "types.h"
typedef struct { char pad[0x12C]; int unk12C; char pad130[0x10]; } Entry004121D0; /* 0x140 */
typedef struct { char pad[0x60]; Entry004121D0* entries; int unk64; int current; } Obj004121D0;
/* Return field 0x12C of the current entry. */
int func_004121D0(Obj004121D0* obj)
{
    return obj->entries[obj->current].unk12C;
}
