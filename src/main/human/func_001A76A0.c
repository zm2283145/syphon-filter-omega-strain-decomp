#include "types.h"
#include "vc_copy.h"
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
typedef struct { V4 r[4]; } M4;
typedef struct { char pad[0x20]; V4 v20; char pad30[0x40]; V4 v70; char pad80[0x21]; unsigned char dirty; char padA2[0xE]; void* root; } Obj;
extern int Root_GetParent(void* r);
extern void Root_RefreshWorldCache(void* r);
extern char* Root_Identity(void* r);
extern V4* Placement_GetQuat(void* p);
extern M4* Quat_ToMatrix(M4* m, V4* q);
extern V4* Placement_GetPosition(void* p);
extern M4* Mtx_FromBasisAndPosition(M4* m, M4* b, V4* p);
#pragma opt_common_subs off
static inline char* GetWorld(void* r) {
    if (Root_GetParent(r)) {
        Root_RefreshWorldCache(r);
        return Root_Identity(r);
    }
    return Root_Identity(r) + 0x50;
}
void func_001A76A0(Obj* o)
{
    if (o->dirty) {
        char* v = GetWorld(o->root);
        VCopyF(&o->v20, &o->v70);
        {
            M4 m; M4 rot; M4* b; V4* d;
            b = Quat_ToMatrix(&rot, Placement_GetQuat(v));
            Mtx_FromBasisAndPosition(&m, b, Placement_GetPosition(v));
            d = &o->v20;
            {
                M4* mp = &m;
                asm {
                    lqc2 vf8, 0x0(d)
                    lqc2 vf4, 0x0(mp)
                    lqc2 vf5, 0x10(mp)
                    lqc2 vf6, 0x20(mp)
                    vmulax.xyz ACC, vf4, vf8x
                    vmadday.xyz ACC, vf5, vf8y
                    vmaddz.xyz vf8, vf6, vf8z
                    sqc2 vf8, 0x0(d)
                }
            }
        }
        o->dirty = 0;
    }
}







