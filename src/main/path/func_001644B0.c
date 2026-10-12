#pragma cplusplus on
#pragma opt_loop_invariants off
#pragma opt_propagation off
#include "types.h"
#include "alloc_guard.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
extern "C" {
char *Mem_Alloc(int, int, char *, int);
int ObjectList_EraseRange(int *, char *, int *, char **);
int PathList_PushBack(char *, char **, int *);
extern char D_0049C1B8;
extern int D_004EA798;
extern int D_004ED9C0;
extern int D_004ED9C4;
extern int D_004ED9C8;
extern int D_004ED9CC;
extern signed char D_004ED9D0;
}
static inline void clr16(char *arg0) { int r; int f; char *l; l = arg0 + 0x30; f = F_(arg0, 0x34, int); ObjectList_EraseRange(&r, arg0 + 0x2C, &f, &l); }
struct Id{volatile int value;Id(int v):value(v){}};
static inline int* Identity(int*p){return p;}
static inline int* set16(char *t, int *pv) { F_(t, 0x4, int) = *pv; return pv;}
static inline void push16(char *arg0, char **pp, char *t) { PathList_PushBack(arg0 + 0x2C, pp, set16(t, Identity((int*)&Id(-1)))); }
#pragma push
#pragma opt_propagation off
extern "C" void NpcRouteMgr_AllocRequestPool(char *arg0) {
    char *sp6C;
    int var_s2;
    char *temp_v1;
    char *temp_s1;
    char *var_s0;

    clr16(arg0);
    {
        AllocGuard g;
        temp_s1 = Mem_Alloc(0, 0x6100, &D_0049C1B8, 0x28);
    }
    var_s2 = 0;
    var_s0 = arg0;
    F_(arg0, 0x38, int) = (int)(temp_s1);
    sp6C = (char *)(F_(arg0, 0x38, int));
    do {
        F_(var_s0, 0x3C, int) = (int)(sp6C);
        temp_v1 = (char *)(F_(var_s0, 0x3C, int));
        F_(temp_v1, 0x0, int) = 0;
        push16(arg0, &sp6C, temp_v1);
        var_s2 += 1;
        var_s0 += 4;
        sp6C += 0x610;
    } while (var_s2 < 0x10);
    D_004ED9D0 = 0;
    D_004ED9C0 = -1;
    D_004ED9C4 = -1;
    D_004ED9C8 = -1;
    D_004ED9CC = -1;
    D_004EA798 = 0;
}
#pragma pop