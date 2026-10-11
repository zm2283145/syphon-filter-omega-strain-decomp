#include "types.h"
#include "vc_copy.h"
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4_73C0;
typedef struct { char pad[0xB0]; void* root; } Obj_73C0;
extern int Root_GetParent(void* r);
extern void Root_RefreshWorldCache(void* r);
extern char* Root_Identity(void* r);
#pragma push
#pragma opt_propagation off
V4_73C0* func_001A73C0(Obj_73C0* o, V4_73C0* out)
{
    void* r = o->root;
    V4_73C0* v;
    if (Root_GetParent(r)) {
        Root_RefreshWorldCache(r);
        v = (V4_73C0*)Root_Identity(r);
        asm { .set reorder } /* empty barrier keeps the then-arm separate (known trick) */
    } else {
        v = (V4_73C0*)(Root_Identity(r) + 0x50);
    }
    VCopyFF(out, v);
    asm {
        lqc2 vf1, 0x0(out)
        vsub.xyz vf1, vf0, vf1
        sqc2 vf1, 0x0(out)
    }
    return out;
}
#pragma pop
