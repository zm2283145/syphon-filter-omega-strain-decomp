#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"
struct Res_1ADD90 { int a; int b; Res_1ADD90() {} };
class Obj_1ADD90 { public: VPAD2(p) virtual Res_1ADD90 Get(); };
typedef struct { int o; } Ref_1ADD90;
typedef struct { char name[0x30]; Ref_1ADD90 ref; int ra; int rb; } __attribute__((aligned(16))) MR_1ADD90;
typedef struct { char pad[0x34]; int reg; } Map_1ADD90;
extern "C" int NodeNameMap_Find(Map_1ADD90* m, MR_1ADD90* name);
extern "C" Ref_1ADD90* Registry_At(int* reg, int idx);
static inline void QZero_1ADD90(void* d0) { int n = 3; void* d = d0;
    asm {
        .set noreorder
    lp:
        nop
        addi n, n, -1
        sq $zero, 0(d)
        bgtz n, lp
        addiu d, d, 0x10
        .set reorder
    }
}
extern "C" void MotionRequest_ResolveName(MR_1ADD90* mr, Map_1ADD90* m)
{
    if (mr->name[0]) {
        volatile int t;
        t = Registry_At(&m->reg, NodeNameMap_Find(m, mr))->o;
        mr->ref.o = t;
        Res_1ADD90 r = ((Obj_1ADD90*)mr->ref.o)->Get();
        mr->ra = r.a;
        mr->rb = r.b;
        if (mr->name[0]) QZero_1ADD90(mr);
    }
}