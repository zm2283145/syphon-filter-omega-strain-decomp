#include "types.h"
typedef struct {
    char pad00[0x14];
    short f14;
    short f16;
    unsigned short f18;
    unsigned short f1A;
    unsigned short f1C;
    unsigned char f1E;
} Params_31E;
typedef struct { char pad[0x4C]; Params_31E* p; } Inner_31E;
typedef struct {
    long magic;
    char pad08[0x10];
    unsigned char state;
    char pad19[3];
    Inner_31E* inner;
} Handle_31E;
#define CHECK_31E(h) \
    if (h == 0 || h->magic != 0xFACE) return 0x17D4; \
    if (h->state != 10) return 0x17DE;
int func_0031E370(Handle_31E* h, short* out) { if (out == 0) return 0x181A; CHECK_31E(h) *out = h->inner->p->f14; return 0; }
