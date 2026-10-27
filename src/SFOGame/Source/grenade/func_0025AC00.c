#include "types.h"

typedef struct ObjBC {
    char pad[0xBC];
    signed char value;
} ObjBC;

typedef struct Holder120 {
    char pad[0x120];
    ObjBC* obj;
} Holder120;

/* Returns the signed byte at obj+0xBC of the linked object, or 0. */
int cGrenade_GetDamageType(Holder120* h) {
    if (h->obj != 0) return h->obj->value;
    return 0;
}
