#include "types.h"
typedef struct { unsigned short key; char p2[10]; } E32C1E0;
typedef struct { char p0[8]; E32C1E0* data; int count; } T32C1E0;
typedef struct { char p0[0x90]; T32C1E0* tab; } O32C1E0;
typedef struct { char p0[2]; unsigned short keys[4]; unsigned char flags; } I32C1E0;
extern int func_0032C2D0(O32C1E0* o, I32C1E0* it);
/* Looks up the table entry for the item's key in its current mode. */
E32C1E0* func_0032C1E0(O32C1E0* o, I32C1E0* it)
{
    int k = func_0032C2D0(o, it);
    if (it->flags & (4 << k)) {
        T32C1E0* t = o->tab;
        int i;
        for (i = 0; i < t->count; i++) {
            if (it->keys[k] == t->data[i].key) return &t->data[i];
        }
    }
    return 0;
}
