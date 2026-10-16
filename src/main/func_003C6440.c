#pragma peephole off
#include "types.h"
typedef struct { float m[4][4]; } __attribute__((aligned(16))) M40;
typedef struct { M40 m; __int128 q4; __int128 q5; } Xf60;

extern void Transform_GetInverseMatrix(M40* out, void* xf);
extern void Mtx_InvertRigid_13ECA0(M40* out, M40* in);
extern void* func_003C6520(void* a, M40* b);
extern void* func_003C64C0(void* a, M40* b);

void func_003C6440(__int128* dst, __int128* src, int unused, void* xf)
{
    M40 inv;
    M40 rig;
    /* empty asm: emits nothing, scheduling barrier so the entry daddu s0 precedes the first lq */
    { __int128 x, y; asm { .set noreorder; .set reorder } x = src[0]; y = src[1]; dst[0] = x; x = src[2]; dst[1] = y; y = src[3]; dst[2] = x; x = src[4]; dst[3] = y; y = src[5]; dst[4] = x; dst[5] = y; }
    Transform_GetInverseMatrix(&inv, xf);
    Mtx_InvertRigid_13ECA0(&rig, &inv);
    func_003C6520(dst, &rig);
    func_003C64C0(dst + 4, &inv);
}





