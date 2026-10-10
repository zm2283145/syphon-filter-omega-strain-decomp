#include "types.h"

typedef struct FlagObj {
    char pad00[0x20];
    int flags; /* 0x20 */
} FlagObj;

/* Returns whether bit `bit` is set in the object's flag word. */
int func_00190920(FlagObj* obj, int bit) {
    return (obj->flags & (1 << bit)) != 0;
}
