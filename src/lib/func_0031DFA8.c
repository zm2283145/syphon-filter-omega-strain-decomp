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
extern int func_0031EDC8(void** p);
extern int func_0031E8B0(void** p);
int func_0031DFA8(Handle_31D* h)
{
    P_31D* p;
    if (h == 0 || h->magic != 0xFACE) return 0x17D4;
    if (h->state != 10) return 0x17DE;
    p = h->inner->p;
    if (func_0031EDC8(&p->f4)) return 0x17E8;
    if (func_0031E8B0(&p->f8)) return 0x17E8;
    if (p) D_004E1D38(p);
    return 0;
}
