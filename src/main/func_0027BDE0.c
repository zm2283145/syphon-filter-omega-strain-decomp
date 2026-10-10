#include "types.h"
#pragma opt_dead_assignments off

typedef struct {
    char pad[0x24];
    unsigned char mode;
    char pad2[3];
    void* target;
    int a;
    unsigned char b;
    char pad3[3];
    int c;
    char pad4[8];
    float x, y, z;
} cNetTaserMsg;
extern unsigned char* D_005061D0; /* network write cursor */
extern void func_00282020(void* target);
extern void func_001B99E0(float f);

static inline void WriteU8(unsigned char v)
{
    *D_005061D0 = v;
    D_005061D0++;
}

/* cNetTaserMsg virtual 4: writes the mode; unless mode 2, also the target, position and three parameters. */
void cNetTaserMsg_v04(cNetTaserMsg* self)
{
    WriteU8(self->mode);
    if (self->mode != 2) {
        func_00282020(self->target);
        func_001B99E0(self->x);
        func_001B99E0(self->y);
        func_001B99E0(self->z);
        WriteU8(self->a);
        WriteU8(self->b);
        WriteU8(self->c);
    }
}
