#include "types.h"

typedef struct Child5B {
    char pad00[0x5B];
    unsigned char state; /* 0x5B */
} Child5B;

typedef struct Parent421650 {
    char pad00[0xA0];
    Child5B* child;      /* 0xA0 */
    char padA4[0x4D];
    unsigned char state; /* 0xF1 */
} Parent421650;

/* Sets the state byte and mirrors it into the child, if any. */
void func_00421650(Parent421650* obj, unsigned char state) {
    obj->state = state;
    if (obj->child) {
        obj->child->state = obj->state;
    }
}
