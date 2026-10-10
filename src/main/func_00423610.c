#include "types.h"
typedef struct { char pad[0x14]; unsigned short flags; char pad2[0x3E]; int id; } Ent;
extern char D_004BF6D0[];
extern void func_00424F60(void* t, char* name, int z);
/* Notifies the target if the entity is flagged and has the given id. */
void func_00423610(Ent* e, int id, void* target) { if ((e->flags & 0x100) && id == e->id) func_00424F60(target, D_004BF6D0, 0); }
