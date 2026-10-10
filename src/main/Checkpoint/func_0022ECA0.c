#include "types.h"

typedef struct cCheckpoint {
    void* vtable;
    char pad[0x5C];
    int unk60;
    int unk64;
    char pad2[8];
    int unk70;
} cCheckpoint;

extern char D_004F7980[];
extern char D_004DB8F0[]; /* cCheckpoint vtable */
extern void cGOBJ_ctor(cCheckpoint* self, int* handle, int flags, const char* name);

/* cCheckpoint constructor. */
cCheckpoint* cCheckpoint_ctor(cCheckpoint* self) {
    int handle = -1;
    cGOBJ_ctor(self, &handle, 0, D_004F7980);
    self->vtable = D_004DB8F0;
    self->unk60 = 100;
    self->unk64 = 100;
    self->unk70 = 0;
    return self;
}
