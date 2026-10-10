#include "types.h"

typedef struct Sub33 {
    char pad[0x33];
    unsigned char value;
} Sub33;

typedef struct Holder3584 {
    char pad[0x3584];
    Sub33* sub;
} Holder3584;

/* Returns sub->value (byte at +0x33) or 0 when the sub-object at +0x3584 is absent. */
int func_00184CA0(Holder3584* self) {
    Sub33* sub = self->sub;
    if (sub) {
        return sub->value;
    }
    return 0;
}
