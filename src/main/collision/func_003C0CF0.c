#include "types.h"

typedef struct { char pad[3]; unsigned char format; char pad2[0x14]; int data; } Obj3C0;
extern char* func_00183B20(Obj3C0* o, int* ref);

/* Returns the address of element idx; the element size (64/32/16 bytes) depends on the format byte. */
char* func_003C0CF0(Obj3C0* o, int idx)
{
    int r16;
    int r32;
    int r64;
    if (o->format < 4) {
        r64 = o->data;
        return func_00183B20(o, &r64) + idx * 64;
    } else if (o->format < 5) {
        r32 = o->data;
        return func_00183B20(o, &r32) + idx * 32;
    } else {
        r16 = o->data;
        return func_00183B20(o, &r16) + idx * 16;
    }
}
