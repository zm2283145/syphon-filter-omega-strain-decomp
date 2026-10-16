#include "types.h"
extern void* D_00539248;
extern void TexMan_ReleaseSlot(void*, int);
typedef struct { int a; int b; } Pair;
/* Applies the global handler to the first id and, if valid, the second id. */
void RenderTarget_Release(Pair* p) { TexMan_ReleaseSlot(D_00539248, p->a); if (p->b != -1) TexMan_ReleaseSlot(D_00539248, p->b); }
