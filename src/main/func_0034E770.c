#include "types.h"
typedef struct { char pad[0xC]; int value; char pad2[0x14]; } Entry36;
typedef struct { char pad[8]; Entry36* entries; } EntryTable;
typedef struct { char pad[0x48]; void* key; } Obj48;
extern char D_004FFB50[];
extern int func_00421480(void* key);
extern void* Agent_GetSelected(void* list, int index);
extern EntryTable* func_0034E760(void);
extern void func_00356850(Obj48* o, int idx, int value);
/* Looks up the entry index for the key and applies its value. */
void func_0034E770(Obj48* o)
{
    int idx = func_00421480(o->key);
    if (idx != -1) {
        Entry36* e;
        Agent_GetSelected(D_004FFB50, -1);
        e = &func_0034E760()->entries[idx];
        func_00356850(o, idx, e->value);
    }
}
