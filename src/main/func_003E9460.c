#include "types.h"
#include "v4_asm_copy.h"
#include "vc_copy.h"
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V3E9460;
typedef struct { char mtx[0x110]; } Cam3E9460;
typedef struct { char p0[0x1F0]; Cam3E9460 cams[1]; } W3E9460;
typedef struct { char p0[0x60]; int h; char p64[0xC]; V3E9460 dir; } S3E9460;
extern void func_00374BC0(V3E9460* out, void* m, V3E9460* v);
extern void func_003E8180(int h, V3E9460* v);
extern W3E9460 D_005381F0;
extern int D_00538C60;
extern char D_0055A290[];
#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
#pragma peephole off
void func_003E9460(S3E9460* s)
{
    V3E9460 v;
    V3E9460 t;
    { V3E9460* d; __int128 w; V3E9460* q; V3E9460* o; char* m; V3E9460* p; d = &v;q = &s->dir; w = VLoadF(q); m = D_0055A290;o = &v;p = &v; VStoreF(d, w);
        asm {
            lqc2 vf8, 0x0(p)
            lqc2 vf4, 0x0(m)
            lqc2 vf5, 0x10(m)
            lqc2 vf6, 0x20(m)
            lqc2 vf7, 0x30(m)
            vmulax.xyzw ACC, vf4, vf8x
            vmadday.xyzw ACC, vf5, vf8y
            vmaddaz.xyzw ACC, vf6, vf8z
            vmaddw.xyzw vf12, vf7, vf8w
            sqc2 vf12, 0x0(o)
        }
    }
    func_00374BC0(&t, D_005381F0.cams[D_00538C60].mtx, &v);
    { V3E9460* x = &v; V3E9460* d = &v; V3E9460* q = &t; VCopyF(d, q); }
    { float z = v.z; if (z < 0.0f) v.z = -z; }
    func_003E8180(s->h, &v);
}
#pragma pop
