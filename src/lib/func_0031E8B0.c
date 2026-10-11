#include "types.h"
extern void (*D_004E1D38)(void*);
typedef struct { void* buf; } S_0031E8B0;
int func_0031E8B0(S_0031E8B0** pp) { S_0031E8B0* p = *pp; if (!p) return 1; if (p->buf) { D_004E1D38(p->buf); p->buf = 0; p = *pp; } if (p) { D_004E1D38(p); *pp = 0; } return 0; }
