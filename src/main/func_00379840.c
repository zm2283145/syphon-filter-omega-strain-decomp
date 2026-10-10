#include "types.h"

typedef struct Flags8 {
    char pad[0x100];
    unsigned int f[8];
} Flags8;

/* Packs eight flag words into a bitmask (bits 3..10). */
unsigned long func_00379840(Flags8* o) {
    unsigned long m = ((unsigned long)o->f[0] << 3) | ((unsigned long)o->f[1] << 4);
    m = ((unsigned long)o->f[2] << 5) | m;
    m = ((unsigned long)o->f[3] << 6) | m;
    m = ((unsigned long)o->f[4] << 7) | m;
    m = ((unsigned long)o->f[5] << 8) | m;
    m = ((unsigned long)o->f[6] << 9) | m;
    return ((unsigned long)o->f[7] << 10) | m;
}
