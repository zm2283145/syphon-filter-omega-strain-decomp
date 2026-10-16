#include "types.h"
typedef struct { int a, b, c, d; } I4;
extern float D_005383A8;
extern char D_005381F0[];
extern char D_005390F0[];
extern int D_00542D9C;
extern int D_00542D2C;
extern int D_00542D48;
extern int D_00542D10;
extern int D_004937C0[];
extern int D_004937D0[];
extern void Renderer_UpdateCameraMatrices(void* p);
void Culler_Setup(void)
{
    I4* vu = (I4*)0x11004000;
    I4 v;
    float f;
    int n = 4;
    v.a = 1;
    v.b = 0;
    v.d = 0;
    f = D_005383A8;
    v.c = *(int*)&f;
    vu->a = v.a;
    vu->b = v.b;
    vu->c = v.c;
    vu->d = v.d;
    Renderer_UpdateCameraMatrices(D_005381F0);
    {
void* s = D_005390F0; __int128 t; void* d = vu + 1;
        asm {
            .set noreorder
        lp:
            lq t, 0(s)
            addiu d, d, 0x10
            addi n, n, -1
            addiu s, s, 0x10
            bgtz n, lp
            sq t, -0x10(d)
            .set reorder
        }
    }
    D_00542D9C = 0;
    if (D_00542D2C != D_00542D48) {
        int i = D_00542D2C;
        int e = D_004937D0[i];
        int st = D_004937C0[i];
        *(unsigned int*)0x10008020 = (unsigned int)(e - st) >> 4;
        *(int*)0x10008010 = st;
        *(int*)0x10008000 = 0x101;
        asm __volatile__("sync");
        D_00542D48 = i;
    }
    {
        int m = D_00542D10;
        asm { ctc2.ni m, vi27 }
    }
}

