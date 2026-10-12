#include "types.h"
typedef struct { unsigned short from; unsigned short to; } E32C120;
typedef struct { char p0[4]; E32C120* data; int count; } M32C120;
typedef struct { char p0[0x98]; M32C120* map; } O32C120;
typedef struct { char p0[2]; unsigned short keys[4]; unsigned char flags; } I32C120;
extern int func_0032C2D0(O32C120* o, I32C120* it);
extern int func_003FD6B0(unsigned short key);
/* Maps the item's key through the object's remap table (0xFF when unmapped and strict). */
int func_0032C120(O32C120* o, I32C120* it, int strict)
{
    int k = func_0032C2D0(o, it);
    unsigned short key = it->keys[k];
    M32C120* m = o->map;
    if (m) {
        int i;
        for (i = 0; i < m->count; i++) {
            if (key == m->data[i].from) return func_003FD6B0(m->data[i].to);
        }
        if (strict) return 0xFF;
    }
    return func_003FD6B0(key);
}
