#include "types.h"
typedef struct { char d[0x8]; } B8;
typedef struct { int w[3]; } W12;
typedef struct { char d[0x20]; } B20;
typedef struct { char d[0x30]; } B30;
extern int func_00207340(void*, void*, void*, void*, void*, void*, void*, float, float, void*);
extern void func_001F12D0(void*, void*);
extern int func_002072B0(void*, void*, void*);
extern void* func_0018A700(void*, void*);
extern void MotionSelNode_Ctor(void*, void*, void*, void*);
extern void* func_002070F0(void*, void*);
extern void MotionRegistry_Register(void*, void*, void*);
extern void func_00200550(void*, int);
extern void func_00138350(void*, int);
/* Builds the "blend" selector node over the graph made by func_00207340 and registers it. */
#pragma optimization_level 1
int func_00206F90(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, float f0, float f1, void* p7)
{
    W12 vF0;
    W12 vE0;
    B8 vD8;
    W12 vC8;
    W12 vB8;
    W12 vA8;
    B30 v70;
    B20 v50;
    func_00207340(&v70, p1, p2, p3, p4, p5, p6, f0, f1, p7);
    func_001F12D0(&vF0, "blend");
    func_002072B0(&vE0, &vF0, p2);
    MotionSelNode_Ctor(&vC8, &v70, p1, func_0018A700(&vD8, p7));
    MotionRegistry_Register(p1, func_002070F0(&v50, &vE0), &vC8);
    func_00200550(&vC8, -1);
    func_00138350(&vE0, -1);
    func_00138350(&vF0, -1);
    func_001F12D0(&vB8, "blend");
    func_002072B0(&vA8, &vB8, p2);
    func_002070F0(p0, &vA8);
    func_00138350(&vA8, -1);
    func_00138350(&vB8, -1);
    return 0;
}
#pragma optimization_level reset
