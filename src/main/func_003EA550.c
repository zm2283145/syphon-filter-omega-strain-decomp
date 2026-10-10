#include "types.h"

typedef struct Target {
    char pad[0xC];
    int serial;
} Target;

/* Weak reference: object pointer plus the serial it had when stored. */
typedef struct WeakRef {
    char pad[0x28];
    Target* obj;
    int serial;
} WeakRef;

/* Returns the referenced object, or 0 if it was replaced (serial mismatch). */
Target* func_003EA550(WeakRef* ref) {
    Target* obj = ref->obj;
    unsigned char valid = 1;
    if (!((obj != 0) ^ 1)) {
        if (obj->serial != ref->serial) {
            valid = 0;
        }
    }
    return valid ? obj : 0;
}
