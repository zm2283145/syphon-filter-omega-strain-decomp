#include "types.h"
typedef struct { char pad[0x312]; unsigned char state; unsigned char req; } Obj_001CB120;
void func_001CB120(Obj_001CB120* o, unsigned char s) {
    o->req = s;
    if (o->state != 0x15 && o->state != 0x16 && o->state != 0x18) {
        o->state = s;
    }
}