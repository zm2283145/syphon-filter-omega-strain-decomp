#include "types.h"
#include "vu0_quat_rot.h"
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
typedef struct { V4 rot; V4 pos; } P;
typedef struct { char pad[0xB0]; void* root; } Obj;
extern int Root_GetParent(void* r);
extern void Root_RefreshWorldCache(void* r);
extern char* Root_Identity(void* r);
static inline V4* CopyVec(V4* d, V4* s) { *d = *s; return d; }
static inline P* PCopy(P* d, P* s) { CopyVec(&d->rot, &s->rot); CopyVec(&d->pos, &s->pos); return d; }
static inline P* PInvert(P* p) {
    VU0_NEG3(p, p)
    { V4* b; V4* a; a = &p->pos; b = &p->pos; VU0_NEG3(a, b) }
    /* empty barrier: changes block scheduling so the then-arm's call arg lands in the jal delay slot */
    { V4* v; asm { .set reorder } v = &p->pos; VU0_QROT(v, p, v) }
    return p;
}
#pragma peephole off
#pragma opt_propagation off
#pragma opt_common_subs off
/* Copies the parent's world placement into out and inverts it in place. */
P* Root_GetParentInverse(Obj* o, P* out)
{
    void* r = o->root;
    P* v;
    if (Root_GetParent(r)) {
        Root_RefreshWorldCache(r);
        v = (P*)Root_Identity(r);
        asm { .set reorder }
    } else {
        v = (P*)(Root_Identity(r) + 0x50);
    }
    PCopy(out, v);
    PInvert(out);
    return out;
}

