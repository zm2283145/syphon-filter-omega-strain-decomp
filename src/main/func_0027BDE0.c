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
extern void cNetMsg_PutGOBJ(void* target);
extern void cNetMsg_PutFloat(float f);

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
        cNetMsg_PutGOBJ(self->target);
        cNetMsg_PutFloat(self->x);
        cNetMsg_PutFloat(self->y);
        cNetMsg_PutFloat(self->z);
        WriteU8(self->a);
        WriteU8(self->b);
        WriteU8(self->c);
    }
}
