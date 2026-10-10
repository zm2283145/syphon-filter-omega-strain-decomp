#include "types.h"

typedef struct Obj1EA0 {
    char pad[0x1EA0];
    int value;
} Obj1EA0;

/* Stores value at +0x1EA0 when it changed. */
void func_004515F0(Obj1EA0* o, int value) {
    if (value != o->value) o->value = value;
}
