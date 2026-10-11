#include "types.h"
typedef struct { char pad[0x4C]; void* p; } Inner_31D;
typedef struct {
    long magic;
    char pad08[0x10];
    unsigned char state;
    char pad19[3];
    Inner_31D* inner;
} Handle_31D;
typedef struct {
    Handle_31D* owner;
    void* f4;
    void* f8;
    char pad0C[8];
    short f14;
    char pad16[8];
    unsigned char f1E;
    char pad1F;
} P_31D;
extern void* (*D_004E1D34)(int n, int size);
extern void (*D_004E1D38)(void*);
extern int func_0031ED08(void** p, short n, float x);
extern int func_0031E828(void** p);
int func_0031DEF8(Handle_31D* h)
{
    Inner_31D* in;
    P_31D* p;
    if (h == 0 || h->magic != 0xFACE) return 0x17D4;
    in = h->inner;
    p = D_004E1D34(1, sizeof(P_31D));
    in->p = p;
    if (!p) return 0x1770;
    if (func_0031ED08(&p->f4, 160, 8000.0f)) return 0x1770;
    if (func_0031E828(&p->f8)) return 0x1770;
    p->owner = h;
    p->f14 = 0;
    p->f1E = 0;
    return 0;
}
