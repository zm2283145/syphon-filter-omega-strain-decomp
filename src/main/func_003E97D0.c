#include "types.h"
#include "v4_asm_copy.h"
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V3E97D0;
typedef struct { char mtx[0x110]; } Cam3E97D0;
typedef struct { char p0[0x1F0]; Cam3E97D0 cams[1]; } W3E97D0;
typedef struct { char p0[0x60]; int h; char p64[0xC]; V3E97D0 dir; } S3E97D0;
extern void func_003E9A60(V3E97D0*);
extern void func_00374BC0(V3E97D0* out, void* m, V3E97D0* v);
extern void func_003E8180(int h, V3E97D0* v);
extern W3E97D0 D_005381F0;
extern int D_00538C60;
#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
void func_003E97D0(S3E97D0* s)
{
    V3E97D0 t;
    unsigned char neg;
    func_003E9A60(&s->dir);
    neg = s->dir.y < 0.0f;
    func_00374BC0(&t, D_005381F0.cams[D_00538C60].mtx, &s->dir);
    {
        V3E97D0* d = &s->dir;
        V3E97D0* q = &t;
        V4Copy(d, q);
    }
    if (neg) s->dir.z = -s->dir.z;
    func_003E8180(s->h, &s->dir);
}
#pragma pop
