#pragma cplusplus on
#pragma opt_propagation off
#include "types.h"
#include "alloc_guard.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#define VC_(p) ((int (*)())(p))
#pragma mpwc_relax on


extern "C" {
int Mem_Free(...); extern int D_00533888;                         
int ObjectList_EraseRange(...); 
int NpcRoute_Release(...);                                 
int func_00164850(...);                            
extern int D_0049C1B8;
extern int D_004EE118;
extern unsigned char D_00533880;
}
static inline int Identity(int p){return p;}
#define DECLS int sp48; int sp44; int sp40;
static inline void clr0(char *arg0) { int sp48; int sp44; int sp40; sp40 = (int)arg0 + 0x30; sp44 = F_(arg0, 0x34, int); ObjectList_EraseRange(&sp48, arg0 + 0x2C, &sp44, &sp40); }
static inline void fr0(int p) { AllocGuard g; Mem_Free(0, p, &D_0049C1B8, 0x41); }
extern "C" void func_00164330(char *arg0) {
    int temp_s0;
    int temp_s1;

    NpcRoute_Release(arg0, 0);
    temp_s1 = F_(arg0, 0x38, int);
    {
        AllocGuard g;
    Mem_Free(0, temp_s1, &D_0049C1B8, 0x41);
    }
    { int sp48; int sp44; int sp40; sp40 = Identity((int)(arg0 + 0x30)); sp44 = F_(arg0, 0x34, int); ObjectList_EraseRange(&sp48, arg0 + 0x2C, &sp44, &sp40); }
    temp_s0 = D_004EE118;
    if (temp_s0 != 0) {
        {
            AllocGuard g;
        if ((temp_s0 != 0) && (temp_s0 != 0) && (temp_s0 != 0)) {
            func_00164850(temp_s0, 0);
        }
        Mem_Free(0, temp_s0, &D_0049C1B8, 0xB2E);
        }
        D_004EE118 = 0;
    }
}
